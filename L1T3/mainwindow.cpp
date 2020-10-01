#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_buttonRelocate_clicked()
{
    QString text1 = ui->textEdit->toPlainText();
    ui->textEdit_2->setPlainText(text1);
    ui->textEdit->clear();
}

void MainWindow::on_buttonChange_clicked()
{
    QString text1 = ui->textEdit->toPlainText();
    ui->textEdit_2->setPlainText(text1);
}

void MainWindow::on_buttonInsertHTML_clicked()
{
    QString text1 = ui->textEdit->toPlainText();
    QString htmlText = "<h1> <font color='red'>" + text1 + "</font></h1>";
    ui->textEdit->setHtml(htmlText);
}
