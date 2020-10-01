#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list {"C++", "Python", "PHP", "Ruby"};
    model = new QStandardItemModel(list.size(),1,this);
    for(int i=0; i<model->rowCount(); ++i){
        QModelIndex index = model->index(i, 0);
        QString str = list[i];
        model->setData(index, str, Qt::DisplayRole);
        model->setData(index, str, Qt::ToolTipRole);
        model->setData(index, QIcon("./Icons/"+str+".png"), Qt::DecorationRole);
    }


    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString item = ui->plainTextEdit->toPlainText();
    model->appendRow(new QStandardItem(item));
    QModelIndex idx = model->index(model->rowCount(), 0);
    model->setData(idx, QIcon("./Icons/C++.png"), Qt::DecorationRole);
}

void MainWindow::on_pushButton_2_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ui->listView->setViewMode(QListView::IconMode);
}
