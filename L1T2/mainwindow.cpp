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


void MainWindow::on_pushButton_clicked()
{
    double m_sideA = ui->sideA->text().toDouble();
    double m_sideB = ui->sideB->text().toDouble();
    double m_angle = ui->angle->text().toDouble();
    if(ui->radioButtonRadian->isChecked()) {
        double degree = m_angle * 57.29;
        m_angle = degree;
    }
    int result = qSqrt((m_sideB*m_sideB) + (m_sideA*m_sideA) - (2*m_sideA*m_sideB*qCos(m_angle)));
    ui->resultLabel->setText(QString::number(result));

}
