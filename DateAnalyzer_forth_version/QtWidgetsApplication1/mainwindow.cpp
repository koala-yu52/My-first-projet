#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <numeric>
mu::string_type ToMuString(const QString& s) {
#ifdef _UNICODE
    return s.toStdWString();
#else
    return s.toStdString();
#endif
}

// 辅助函数：将 muParser 的字符串类型转回 QString
QString FromMuString(const mu::string_type& s) {
#ifdef _UNICODE
    return QString::fromStdWString(s);
#else
    return QString::fromStdString(s);
#endif
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table_fit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->btn_add_fit, &QPushButton::clicked, [=]() { ui->table_fit->insertRow(ui->table_fit->rowCount()); });
    connect(ui->btn_del_fit, &QPushButton::clicked, [=]() { ui->table_fit->removeRow(ui->table_fit->currentRow()); });
    connect(ui->btn_run_fit, &QPushButton::clicked, this, &MainWindow::on_btn_run_fit_clicked);

    ui->table_ind->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->btn_add_ind, &QPushButton::clicked, [=]() { ui->table_ind->insertRow(ui->table_ind->rowCount()); });
    connect(ui->btn_del_ind, &QPushButton::clicked, [=]() { ui->table_ind->removeRow(ui->table_ind->currentRow()); });
    connect(ui->btn_calc_ind, &QPushButton::clicked, this, &MainWindow::on_btn_calc_ind_clicked);
    
    connect(ui->btn_calc_B, &QPushButton::clicked, this, &MainWindow::on_btn_calc_B_clicked);
    // A类页面：添加/删除行
    connect(ui->btn_add_A, &QPushButton::clicked, [=]() {
        ui->table_A->insertRow(ui->table_A->rowCount());
        });
    connect(ui->btn_del_A, &QPushButton::clicked, [=]() {
        ui->table_A->removeRow(ui->table_A->currentRow());
        });

    // A类页面：执行计算按钮
    connect(ui->btn_calc_A, &QPushButton::clicked, this, &MainWindow::on_btn_calc_A_clicked);
    // --- 统计学页面初始化 ---
    ui->table_stats->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 添加/删除行
    connect(ui->btn_add_stats, &QPushButton::clicked, [=]() {
        ui->table_stats->insertRow(ui->table_stats->rowCount());
        });
    connect(ui->btn_del_stats, &QPushButton::clicked, [=]() {
        ui->table_stats->removeRow(ui->table_stats->currentRow());
        });

    // 计算按钮
    connect(ui->btn_calc_stats, &QPushButton::clicked, this, &MainWindow::on_btn_calc_stats_clicked);
    // --- 平均值页面初始化 ---
// 让表格列宽自动填满
    ui->table_mean->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 绑定“添加行”按钮
    connect(ui->btn_add_mean, &QPushButton::clicked, [=]() {
        ui->table_mean->insertRow(ui->table_mean->rowCount());
        });

    // 绑定“删除行”按钮
    connect(ui->btn_del_mean, &QPushButton::clicked, [=]() {
        ui->table_mean->removeRow(ui->table_mean->currentRow());
        });

    // 绑定“开始计算”按钮（连接到我们下面要写的函数）
    connect(ui->btn_calc_mean, &QPushButton::clicked, this, &MainWindow::on_btn_calc_mean_clicked);

    // 1. 初始化页面显示主页 (第 0 页)
    ui->mainStackedWidget->setCurrentIndex(0);

    // 2. 翻页逻辑
    // --- 统一返回逻辑：所有返回按钮都指向第 0 页 (主页) ---
    // 2. 【核心跳转逻辑】从主页进入各个房间
    
    connect(ui->btn_go_mean, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(1); });
    connect(ui->btn_go_stats, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(2); });
    connect(ui->btn_go_A, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(3); });
    connect(ui->btn_go_B, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(4); });
    connect(ui->btn_go_ind, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(5); });
    connect(ui->btn_go_fit, &QPushButton::clicked, [=]() { ui->mainStackedWidget->setCurrentIndex(6); });

// 1. 平均值页返回
    connect(ui->btn_back_mean, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });

    // 2. 统计学页返回
    connect(ui->btn_back_stats, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });

    // 3. A类不确定度页返回
    connect(ui->btn_back_A, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });

    // 4. B类不确定度页返回
    connect(ui->btn_back_B, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });

    // 5. 间接不确定度页返回
    connect(ui->btn_back_ind, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });

    // 6. 曲线拟合页返回
    connect(ui->btn_back_fit, &QPushButton::clicked, [=]() {
        ui->mainStackedWidget->setCurrentIndex(0);
        });
}

// 补齐析构函数实现 (解决 LNK2019)
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_calc_mean_clicked() {
    QVector<double> data;
    QString data_process_str = "";

    for (int i = 0; i < ui->table_mean->rowCount(); ++i) {
        QTableWidgetItem* item = ui->table_mean->item(i, 0);
        if (item && !item->text().isEmpty()) {
            double val = item->text().toDouble();
            data.append(val);
            data_process_str += QString::number(val) + " + ";
        }
    }

    if (data.isEmpty()) {
        ui->text_res_mean->setHtml("<b style='color:red;'>【错误】请输入测量数据后再计算。</b>");
        return;
    }
    data_process_str.chop(3);

    int n = data.size();
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / n;

    // --- 开始构造精美 HTML 报告 ---
    QString html = "<h2 style='color:#2c3e50; text-align:center;'>平均值计算报告</h2><hr>";

    html += "<b style='font-size:12pt;'>【第一步】列出已知参数：</b><br>";
    html += QString("<p style='margin-left:20px;'>数据点个数 <i>n</i> = %1<br>").arg(n);
    html += "测量序列 <i>x<sub>i</sub></i> = {" + data_process_str + "}</p>";

    html += "<b style='font-size:12pt;'>【第二步】书写计算公式：</b><br>";
    html += "<p style='margin-left:40px; font-family:Times New Roman; font-size:14pt;'>"
        "<i>x&#772;</i> = ( &Sigma; <i>x<sub>i</sub></i> ) / <i>n</i></p>";

    html += "<b style='font-size:12pt;'>【第三步】代入数据计算：</b><br>";
    html += QString("<p style='margin-left:20px;'><i>x&#772;</i> = (%1) / %2</p>").arg(data_process_str).arg(n);
    html += QString("<p style='margin-left:20px;'><i>x&#772;</i> = %1 / %2</p>").arg(sum).arg(n);

    // 最终结果加亮色背景框
    html += "<br><b style='font-size:12pt;'>【最终结果】：</b><br>";
    html += "<div style='background-color:#e8f8f5; padding:10px; border:1px solid #27ae60; border-radius:5px; margin-top:5px;'>"
        "<span style='font-size:18pt; color:#1e8449; font-weight:bold;'>"
        "平均值 <i>x&#772;</i> &asymp; " + QString::number(mean, 'f', 6) + "</span>"
        "</div>";

    ui->text_res_mean->setHtml(html);
}
void MainWindow::on_btn_calc_stats_clicked() {
    QVector<double> data;
    for (int i = 0; i < ui->table_stats->rowCount(); ++i) {
        QTableWidgetItem* item = ui->table_stats->item(i, 0);
        if (item && !item->text().isEmpty()) data.append(item->text().toDouble());
    }

    if (data.size() < 2) {
        ui->text_res_stats->setHtml("<b style='color:red;'>【错误】计算方差至少需要 2 组数据。</b>");
        return;
    }

    int n = data.size();
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / n;

    double sumSqDiff = 0;
    QString step_details = "";
    for (double val : data) {
        double diff = val - mean;
        double sq = diff * diff;
        sumSqDiff += sq;
        step_details += QString("<li>(%1 - %2)<sup>2</sup> = %3</li>").arg(val).arg(mean, 0, 'f', 2).arg(sq, 0, 'f', 6);
    }

    double var = sumSqDiff / (n - 1);
    double stdDev = std::sqrt(var);

    QString html = "<h2 style='color:#2c3e50; text-align:center;'>统计分析报告</h2><hr>";

    html += "<b style='font-size:11pt;'>【第一步】基础统计：</b>";
    html += QString("<p style='margin-left:20px;'>平均值 <i>x&#772;</i> = %1</p>").arg(QString::number(mean, 'f', 4));

    html += "<b style='font-size:11pt;'>【第二步】计算离差平方和：</b>";
    html += "<ul style='font-size:10pt; color:#555;'>" + step_details + "</ul>";
    html += QString("<p style='margin-left:20px;'>总和 &Sigma;(<i>x<sub>i</sub> - x&#772;</i>)<sup>2</sup> = <b>%1</b></p>").arg(QString::number(sumSqDiff, 'f', 6));

    html += "<b style='font-size:11pt;'>【第三步】样本方差 (Bessel修正)：</b>";
    // --- 下面这一行就是之前报错的地方，现在已修正 ---
    html += QString("<p style='margin-left:20px; font-size:13pt;'><i>S<sup>2</sup></i> = %1 / (%2 - 1) = <b>%3</b></p>")
        .arg(sumSqDiff)
        .arg(n)
        .arg(QString::number(var, 'f', 6));

    html += "<br><b style='font-size:11pt;'>【第四步】得出标准差：</b><br>";
    QString resBox = "<div style='background-color:#f4ecf7; padding:10px; border:1px solid #8e44ad; border-radius:5px;'>";
    resBox += "<span style='font-size:18pt; color:#5b2c6f; font-weight:bold;'>标准差 <i>S</i> &asymp; ";
    resBox += QString::number(stdDev, 'f', 6);
    resBox += "</span></div>";

    html += resBox;

    ui->text_res_stats->setHtml(html);
}
void MainWindow::on_btn_calc_A_clicked() {
    QVector<double> data;
    for (int i = 0; i < ui->table_A->rowCount(); ++i) {
        if (ui->table_A->item(i, 0)) data.append(ui->table_A->item(i, 0)->text().toDouble());
    }

    if (data.size() < 2) {
        ui->text_res_A->setHtml("<b style='color:red;'>【错误】至少需要 2 组数据来计算 A类不确定度。</b>");
        return;
    }

    // 数学计算
    int n = data.size();
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / n;
    double sumSqDiff = 0;
    for (double x : data) sumSqDiff += std::pow(x - mean, 2);

    double S = std::sqrt(sumSqDiff / (n - 1));
    double t = ui->edit_t_A->text().toDouble();
    if (t <= 0) t = 1.0;
    double uA = t * (S / std::sqrt(n));

    // --- 构造精美 HTML 报告 ---
    QString html = "<h2 style='color:#2c3e50; text-align:center;'>A类不确定度分析报告</h2><hr>";

    html += "<b style='font-size:11pt;'>【第一步】计算标准偏差 (S)：</b>";
    // 修正点：合并了字符串，确保 .arg 对应正确的占位符
    html += QString("<p style='margin-left:20px;'>公式: <i>S</i> = &radic;[ &Sigma;(<i>x<sub>i</sub> - x&#772;</i>)<sup>2</sup> / (<i>n</i> - 1) ]<br>"
        "代入: <i>S</i> = &radic;[ %1 / (%2 - 1) ] = <b>%3</b></p>")
        .arg(QString::number(sumSqDiff, 'f', 4))
        .arg(n)
        .arg(QString::number(S, 'f', 6));

    html += "<b style='font-size:11pt;'>【第二步】读取修正因子 (t)：</b>";
    html += QString("<p style='margin-left:20px;'>当前置信因子 <i>t</i> = <b>%1</b></p>").arg(t);

    html += "<br><b style='font-size:11pt;'>【最终结果】：</b><br>";
    QString resBox = "<div style='background-color:#fef9e7; padding:12px; border:2px solid #f1c40f; border-radius:5px;'>";
    resBox += "<span style='font-size:16pt; color:#9a7d0a; font-weight:bold;'>A类不确定度 <i>u<sub>A</sub></i> &asymp; ";
    resBox += QString::number(uA, 'f', 6);
    resBox += "</span></div>";

    html += resBox;
    html += "<p style='color:gray; font-size:9pt; margin-top:10px;'>注：n为测量次数，S为单次测量实验标准偏差。</p>";

    ui->text_res_A->setHtml(html);
}
void MainWindow::on_btn_calc_B_clicked() {
    QString strDelta = ui->edit_delta_B->text();
    QString strK = ui->edit_k_B->text();

    if (strDelta.isEmpty() || strK.isEmpty()) {
        ui->text_res_B->setHtml("<b style='color:red;'>【错误】请输入仪器误差和包含因子！</b>");
        return;
    }

    double delta = strDelta.toDouble();
    double k = strK.toDouble();
    if (k == 0) {
        ui->text_res_B->setHtml("<b style='color:red;'>【错误】包含因子 k 不能为 0！</b>");
        return;
    }

    double uB = delta / k;

    // --- 构造精美 HTML 报告 ---
    QString html = "<h2 style='color:#2c3e50; text-align:center;'>B类不确定度分析报告</h2><hr>";

    html += "<b style='font-size:11pt;'>【理论依据】：</b>";
    html += "<p style='margin-left:20px; color:#555;'>B类不确定度通常根据仪器限误差 &Delta; 及分布系数 <i>k</i> 评估。</p>";

    html += "<b style='font-size:11pt;'>【计算过程】：</b>";
    // 修正点：去掉了多余的 .arg()
    html += QString("<p style='margin-left:20px;'>公式: <i>u<sub>B</sub></i> = &Delta; / <i>k</i><br>"
        "代入: <i>u<sub>B</sub></i> = %1 / %2</p>")
        .arg(delta)
        .arg(k);

    html += "<br><b style='font-size:11pt;'>【最终结果】：</b><br>";
    QString resBox = "<div style='background-color:#ebf5fb; padding:12px; border:2px solid #3498db; border-radius:5px;'>";
    resBox += "<span style='font-size:16pt; color:#21618c; font-weight:bold;'>B类不确定度 <i>u<sub>B</sub></i> &asymp; ";
    resBox += QString::number(uB, 'f', 6);
    resBox += "</span></div>";

    html += resBox;
    ui->text_res_B->setHtml(html);
}
void MainWindow::on_btn_calc_ind_clicked() {
    QString formula = ui->edit_formula_ind->text().trimmed();
    if (formula.isEmpty()) {
        ui->text_res_ind->setText("【错误】请输入物理公式！");
        return;
    }

    try {
        mu::Parser parser;
        parser.SetExpr(formula.toStdString());

        int rows = ui->table_ind->rowCount();
        QMap<std::string, double> varValues;
        QMap<std::string, double> varUncertainties;

        // 1. 读取并绑定变量数据
        for (int i = 0; i < rows; ++i) {
            QTableWidgetItem* itemName = ui->table_ind->item(i, 0);
            QTableWidgetItem* itemVal = ui->table_ind->item(i, 1);
            QTableWidgetItem* itemU = ui->table_ind->item(i, 2);

            if (itemName && itemVal && !itemName->text().isEmpty()) {
                std::string name = itemName->text().toStdString();
                double val = itemVal->text().toDouble();
                double u = itemU ? itemU->text().toDouble() : 0.0;
                varValues[name] = val;
                varUncertainties[name] = u;
                parser.DefineVar(name, &varValues[name]);
            }
        }

        // 2. 计算间接测量的平均值基准 Y
        double y_base = parser.Eval();

        // 3. 构建报告内容
        QString html = "<h2 style='color:#2c3e50; text-align:center;'>间接不确定度分析报告</h2><hr>";

        html += "<b>【第一步】误差传递公式：</b><br>";
        html += "<p style='margin-left:20px; font-family:Times New Roman; font-size:14pt;'>"
            "<i>u<sub>y</sub></i> = &radic;[ &Sigma; (&Delta;<i>y<sub>i</sub></i>)<sup>2</sup> ]"
            "</p>";
        html += "<small>说明：通过给每个分量施加其不确定度增量，计算结果的变化量 &Delta;y<sub>i</sub>。</small><br><br>";

        QString symbols = ""; // 符号分量展示
        QString values = "";  // 数值分量展示
        double sumSq = 0;

        for (auto it = varValues.begin(); it != varValues.end(); ++it) {
            std::string name = it.key();
            double original_val = it.value();
            double ux = varUncertainties[name];

            // 扰动计算
            varValues[name] = original_val + ux;
            double y_perturbed = parser.Eval();
            double delta_y = y_perturbed - y_base;
            sumSq += std::pow(delta_y, 2);

            QString varName = QString::fromStdString(name);
            symbols += QString("(&Delta;<i>y<sub>%1</sub></i>)<sup>2</sup> + ").arg(varName);
            values += QString("(%1)<sup>2</sup> + ").arg(QString::number(delta_y, 'f', 6));

            varValues[name] = original_val; // 还原
        }

        if (symbols.endsWith(" + ")) symbols.chop(3);
        if (values.endsWith(" + ")) values.chop(3);

        // 展示代入过程
        html += "<b>【第二步】各分量贡献过程：</b><br>";
        html += QString("<p style='margin-left:20px;'><i>u<sub>y</sub></i> = &radic;[ %1 ]</p>").arg(symbols);
        html += QString("<p style='margin-left:20px;'><i>u<sub>y</sub></i> = &radic;[ %1 ]</p>").arg(values);

        double uy = std::sqrt(sumSq);

        // 4. 展示最终计算结果
        html += "<br><b>【第三步】计算最终结果：</b><br>";
        html += QString("<p style='margin-left:20px;'>间接测量平均值 <b>Y = %1</b></p>").arg(y_base);

        // 此处仅显示“间接不确定度”，不再显示“合成”字样
        QString resBox = "<div style='background-color:#ebf5fb; padding:10px; border:1px solid #3498db; border-radius:5px;'>";
        resBox += "<span style='font-size:15pt; color:#2980b9;'>间接不确定度 <i>u<sub>y</sub></i> &asymp; <b>";
        resBox += QString::number(uy, 'f', 6);
        resBox += "</b></span></div>";

        html += resBox;

        ui->text_res_ind->setHtml(html);

    }
    catch (mu::Parser::exception_type& e) {
        QString errorMsg = QString::fromStdString(e.GetMsg());
        ui->text_res_ind->setHtml("<b style='color:red;'>公式解析失败：</b>" + errorMsg);
    }
}
QVector<double> MainWindow::solveLinearSystem(QVector<QVector<double>> A, QVector<double> B) {
    int n = B.size();
    for (int i = 0; i < n; i++) {
        int max = i;
        for (int k = i + 1; k < n; k++)
            if (std::abs(A[k][i]) > std::abs(A[max][i])) max = k;
        std::swap(A[i], A[max]); std::swap(B[i], B[max]);
        for (int k = i + 1; k < n; k++) {
            double f = A[k][i] / A[i][i];
            B[k] -= f * B[i];
            for (int j = i; j < n; j++) A[k][j] -= f * A[i][j];
        }
    }
    QVector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double s = 0;
        for (int j = i + 1; j < n; j++) s += A[i][j] * x[j];
        x[i] = (B[i] - s) / A[i][i];
    }
    return x;
}
void MainWindow::on_btn_run_fit_clicked() {
    QVector<double> vx, vy;
    for (int i = 0; i < ui->table_fit->rowCount(); ++i) {
        if (ui->table_fit->item(i, 0) && ui->table_fit->item(i, 1)) {
            vx.append(ui->table_fit->item(i, 0)->text().toDouble());
            vy.append(ui->table_fit->item(i, 1)->text().toDouble());
        }
    }
    if (vx.size() < 2) return;

    int type = ui->combo_fit_type->currentIndex();
    QVector<double> coeffs;
    QString formulaHtml = "y = ";
    std::function<double(double)> fitFunc;

    // --- 核心算法分支 ---

    if (type <= 4) { // 处理 1次(线性) 到 5次 多项式
        int degree = type + 1; // 索引0是1次，索引4是5次
        int size = degree + 1;

        if (vx.size() < size) {
            ui->text_res_fit->setText(QString("【错误】%1次拟合至少需要 %2 个点！").arg(degree).arg(size));
            return;
        }

        // 1. 构建正规方程组矩阵 (通用逻辑，自动适应 1-5 次)
        QVector<QVector<double>> A(size, QVector<double>(size, 0));
        QVector<double> B(size, 0);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (double x : vx) A[i][j] += std::pow(x, i + j);
            }
            for (int k = 0; k < vx.size(); ++k) B[i] += vy[k] * std::pow(vx[k], i);
        }
        coeffs = solveLinearSystem(A, B);

        // 2. 自动生成公式 HTML (支持 x^5, x^4...)
        for (int i = degree; i >= 0; --i) {
            double c = coeffs[i];
            if (i < degree && c >= 0) formulaHtml += " + ";
            else if (c < 0) formulaHtml += " - ";

            formulaHtml += QString::number(std::abs(c), 'f', 4);
            if (i > 1) formulaHtml += QString("x<sup>%1</sup>").arg(i);
            else if (i == 1) formulaHtml += "x";
        }

        // 3. 定义绘图采样函数
        fitFunc = [degree, coeffs](double x) {
            double res = 0;
            for (int d = 0; d <= degree; ++d) res += coeffs[d] * std::pow(x, d);
            return res;
            };
    }
    else {
        // --- 处理非线性拟合 (指数、对数、幂函数) ---
        // 注意：由于上面插入了两个选项，这里的 type 判定需要整体 +2
        if (type == 5) { // 指数 y = a * e^(bx)
            double sX = 0, sX2 = 0, sLY = 0, sXLY = 0; int n = vx.size();
            for (int i = 0; i < n; ++i) {
                double ly = std::log(std::abs(vy[i]));
                sX += vx[i]; sX2 += vx[i] * vx[i]; sLY += ly; sXLY += vx[i] * ly;
            }
            double b = (n * sXLY - sX * sLY) / (n * sX2 - sX * sX);
            double a = std::exp((sLY - b * sX) / n);
            coeffs = { a, b };
            fitFunc = [a, b](double x) { return a * std::exp(b * x); };
            formulaHtml = QString("y = %1 &middot; e<sup>%2x</sup>").arg(a, 0, 'f', 4).arg(b, 0, 'f', 4);
        }
        else if (type == 6) { // 对数 y = a * ln(x) + b
            double sLX = 0, sLX2 = 0, sY = 0, sLXY = 0; int n = vx.size();
            for (int i = 0; i < n; ++i) {
                double lx = std::log(std::abs(vx[i]));
                sLX += lx; sLX2 += lx * lx; sY += vy[i]; sLXY += lx * vy[i];
            }
            double a = (n * sLXY - sLX * sY) / (n * sLX2 - sLX * sLX);
            double b = (sY - a * sLX) / n;
            coeffs = { a, b };
            fitFunc = [a, b](double x) { return a * std::log(std::abs(x)) + b; };
            formulaHtml = QString("y = %1 &middot; ln(x) + %2").arg(a, 0, 'f', 4).arg(b, 0, 'f', 4);
        }
        else if (type == 7) { // 幂函数 y = a * x^b
            double sLX = 0, sLX2 = 0, sLY = 0, sLXLY = 0; int n = vx.size();
            for (int i = 0; i < n; ++i) {
                double lx = std::log(std::abs(vx[i])); double ly = std::log(std::abs(vy[i]));
                sLX += lx; sLX2 += lx * lx; sLY += ly; sLXLY += lx * ly;
            }
            double b = (n * sLXLY - sLX * sLY) / (n * sLX2 - sLX * sLX);
            double a = std::exp((sLY - b * sLX) / n);
            coeffs = { a, b };
            fitFunc = [a, b](double x) { return a * std::pow(std::abs(x), b); };
            formulaHtml = QString("y = %1 &middot; x<sup>%2</sup>").arg(a, 0, 'f', 4).arg(b, 0, 'f', 4);
        }
    }

    // --- 3. 绘图执行 (采样 200 个点以保证平滑) ---
    ui->plotWidget_fit->clearGraphs();
    ui->plotWidget_fit->addGraph(); // 点层
    ui->plotWidget_fit->graph(0)->setData(vx, vy);
    ui->plotWidget_fit->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plotWidget_fit->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, 8));

    ui->plotWidget_fit->addGraph(); // 线层
    double minX = *std::min_element(vx.begin(), vx.end());
    double maxX = *std::max_element(vx.begin(), vx.end());
    QVector<double> fx(200), fy(200);
    for (int i = 0; i < 200; ++i) {
        fx[i] = minX + i * (maxX - minX) / 199.0;
        fy[i] = fitFunc(fx[i]);
    }
    ui->plotWidget_fit->graph(1)->setData(fx, fy);
    ui->plotWidget_fit->graph(1)->setPen(QPen(Qt::red, 2));

    // 展示精美 HTML 报告
    ui->text_res_fit->setHtml("<h3 style='color:#2c3e50;'>曲线拟合分析报告</h3>"
        "<div style='background:#f4f6f7; padding:10px; border-left:5px solid #2ecc71; font-size:14pt;'>"
        "<b>模型方程：</b>" + formulaHtml + "</div>");
    ui->plotWidget_fit->rescaleAxes();
    ui->plotWidget_fit->replot();
}