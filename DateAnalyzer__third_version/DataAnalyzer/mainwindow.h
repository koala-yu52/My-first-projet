#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "muParser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow(); // 析构函数声明

private slots:
    // 按钮槽函数声明
    void on_btn_calc_ind_clicked();
    void on_btn_calc_A_clicked(); // A类不确定度计算
    void on_btn_run_fit_clicked();
    void on_btn_calc_mean_clicked(); // 计算平均值并显示过程
    void on_btn_calc_stats_clicked();
    void on_btn_calc_B_clicked(); // B类不确定度计算
private:
    // 通用线性方程组求解器（高斯消元法）
    QVector<double> solveLinearSystem(QVector<QVector<double>> A, QVector<double> B);
    Ui::MainWindow* ui;
    // 获取表格数据的工具函数声明
    void getTableData(QVector<double>& x, QVector<double>& y);
};
#endif // MAINWINDOW_H