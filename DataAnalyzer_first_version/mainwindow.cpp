#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->plotWidget->addGraph();

 
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i / 50.0 - 1.0;
        y[i] = x[i] * x[i];
    }


    ui->plotWidget->graph(0)->setData(x, y);
    ui->plotWidget->xAxis->setLabel("X Axis");
    ui->plotWidget->yAxis->setLabel("Y Axis");
    ui->plotWidget->rescaleAxes();
    ui->plotWidget->replot();

}


MainWindow::~MainWindow()
{
    delete ui;
}