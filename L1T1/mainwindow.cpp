#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonResult_clicked()
{
    int x2 = ui->lineX2->text().toInt();
    int x = ui->lineX->text().toInt();
    int n = ui->lineN->text().toInt();
    int d = (x*x) - (4*x2*n);
    if(x2 == 0) {
        int root = -(n/x);
        QString result = QString("X = %1").arg(QString::number(root));
        ui->resultLabel->setText(result);
    }
    else if (d < 0) {
        ui->resultLabel->setText("Нет корней");
    }
    else if (d == 0) {
        int root = -(x/(2*x2));
        QString result = QString("X = %1").arg(QString::number(root));
        ui->resultLabel->setText(result);
    }
    else if (d > 0) {
        int root1 = (-x + qSqrt(d)) / (2*x2);
        int root2 = (-x - qSqrt(d)) / (2*x2);
        QString result = QString("X1 = %1, X2 = %2").arg(QString::number(root1), QString::number(root2));
        ui->resultLabel->setText(result);
    }

}
