#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parseText = new ParseText();
    if (!parseText) close();

}

MainWindow::~MainWindow()
{
    if (parseText) {
        delete parseText;
        parseText = nullptr;
    }
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();
    if (parseText->change(txt))
    {
        ui->plainTextEdit->setPlainText(parseText->getText());
    }


}
