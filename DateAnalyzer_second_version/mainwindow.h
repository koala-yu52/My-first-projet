#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_calculate_clicked(); // 点击计算按钮的反应

private:
    Ui::MainWindow* ui;
    // 获取表格数据的工具函数
    void getTableData(QVector<double>& x, QVector<double>& y);
};
