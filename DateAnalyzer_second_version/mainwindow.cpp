#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <numeric>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->btn_addRow, &QPushButton::clicked, this, [=]() {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        });

    connect(ui->btn_delRow, &QPushButton::clicked, this, [=]() {
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        });

    connect(ui->btn_calculate, &QPushButton::clicked, this, &MainWindow::on_btn_calculate_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getTableData(QVector<double>& x, QVector<double>& y) {
    x.clear(); y.clear();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QTableWidgetItem* itemX = ui->tableWidget->item(i, 0);
        QTableWidgetItem* itemY = ui->tableWidget->item(i, 1);
        if (itemX && itemY && !itemX->text().isEmpty()) {
            x.append(itemX->text().toDouble());
            y.append(itemY->text().toDouble());
        }
    }
}


void MainWindow::on_btn_calculate_clicked() {
    QVector<double> x, y;
    getTableData(x, y);

    if (y.size() < 2) {
        ui->text_output->setText("错误：请至少输入两组数据！");
        return;
    }

    // --- 数学计算 ---
    int n = y.size();
    double sum = std::accumulate(y.begin(), y.end(), 0.0);
    double mean = sum / n; // 平均值

    double sumSqDiff = 0;
    for (double val : y) sumSqDiff += std::pow(val - mean, 2);
    double stdDev = std::sqrt(sumSqDiff / (n - 1)); // 标准差

    double uA = stdDev / std::sqrt(n); // A类不确定度
    double delta = ui->edit_delta->text().toDouble();
    double k = ui->edit_k->text().toDouble();
    double uB = delta / k; // B类不确定度
    double uCombined = std::sqrt(uA * uA + uB * uB); // 合成不确定度

    // --- 显示结果 ---
    QString result = QString("数据点个数: %1\n").arg(n);
    result += QString("平均值: %1\n").arg(mean);
    result += QString("A类不确定度 (uA): %1\n").arg(uA);
    result += QString("B类不确定度 (uB): %1\n").arg(uB);
    result += QString("合成不确定度 (uc): %1").arg(uCombined);
    ui->text_output->setText(result);

    // --- 绘图 ---
    ui->plotWidget->clearGraphs();
    ui->plotWidget->addGraph();
    ui->plotWidget->graph(0)->setData(x, y);
    ui->plotWidget->graph(0)->setLineStyle(QCPGraph::lsNone); // 只画点
    ui->plotWidget->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // 圆点
    ui->plotWidget->rescaleAxes();
    ui->plotWidget->replot();
}