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


void MainWindow::on_openButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Пример фильтра", QDir::currentPath(),"Text(*.txt);;ALL(*.*)");
    qint32 extensionIndex = filename.indexOf(QRegExp("\\.[\\w\\d]+$"));
    QString extension = filename.mid(extensionIndex);
    if (extension.compare(".txt") == 0)
    {
        QFile file (filename);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream ts(&file);
            ui->plainTextEdit->setPlainText(ts.readAll());
            file.close();
        }
    }
    else if (extension.compare(".original") == 0)
    {
        QFile file (filename);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream ts(&file);
            ui->lineEdit->insert(ts.readLine());
            ui->plainTextEdit->setPlainText(ts.readAll());
            file.close();
        }
    }
    else
    {
        QFile file (filename);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream ts(&file);
            ui->plainTextEdit->setPlainText(ts.readAll());
            file.close();
        }
    }
}

/*
 * Добавить в редактор возможность сохранить содержимое текстового поля. Если
 * оно сохраняется в бинарный файл, сохранять имя автора, разместив поле QLineEdit,
 * а в тестовом виде запись в этом поле игнорировать.
 */
void MainWindow::on_saveButton_clicked()
{
    /*
     * Фильтр был определен строкой с символами ;;
     * Формат фильтра прост: Что будет написано в списке(*.расширение_файла)
     * Можно указать несколько расширений: Что будет написано в списке(*.расширение_файла1 *.расширение_файла2)
     */
    QString filter{"Текстовый файл(*.txt);;Двоичный файл(*.original)"};
    QString filename = QFileDialog::getSaveFileName(this, "Заголовок окна", QDir::current().path(), filter);
    qint32 extensionIndex = filename.indexOf(QRegExp("\\.[\\w\\d]+$"));
    QString extension = filename.mid(extensionIndex);
    if (extension.compare(".txt") == 0)
    {
        QFile file (filename);
        if (file.open(QFile::WriteOnly))
        {
            QTextStream ts(&file);
            ts << ui->plainTextEdit->toPlainText();
            ts.flush();
            file.close();
        }
    }
    else if (extension.compare(".original") == 0)
    {
        QFile file (filename);
        if (file.open(QIODevice::WriteOnly))
        {
            QDataStream ds(&file);
            QString author = ui->lineEdit->text();
            QString str = author + "\n" + ui->plainTextEdit->toPlainText();
            QByteArray b = QString(str).toUtf8();
            ds.writeRawData(b.data(), b.length());
        }
    }
    else
    {
        QFile file (filename);
        if (file.open(QIODevice::WriteOnly))
        {
            QDataStream ds(&file);
            QString str = ui->plainTextEdit->toPlainText();
            QByteArray b = QString(str).toUtf8();
            ds.writeRawData(b.data(), b.length());
        }
    }
}

/*
 * Добавить в текстовый редактор файл описания. Текстовый файл с описанием
 * разместить в ресурсах программы. Для вызова описания разместить на форме
 * соответствующую кнопку.
 */
void MainWindow::on_infoButton_clicked()
{
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("info");
    wdg->resize(300, 100);

    QFile file(":/info.txt");
    QString s;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        s = stream.readAll();
        file.close();
    }

    QLabel *lbl = new QLabel(wdg);
    lbl->setText(s);
    lbl->setAlignment(Qt::AlignJustify);
    lbl->setGeometry(50, 25, 200, 50);
    lbl->setWordWrap(true);

    wdg->show();
}
