#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Text Note");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this,tr("OpenFile"),"",tr("Txet(*.txt)"));//get the file path

    QFile fileRead(filePath);
    if(fileRead.open(QIODevice::ReadOnly)){
        QTextStream input(&fileRead);
        input.setCodec("UTF-8");
        while(!input.atEnd()){
            QString line = input.readLine();
            ui->textBrowser->append(line.toStdString().data());
        }
        fileRead.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString UserInput = ui->lineEdit->text();
    QFile fileWrite(filePath);
    if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream output(&fileWrite);
        output<<UserInput<<endl;
        fileWrite.close();
    }
    ui->lineEdit->clear();
    ui->textBrowser->clear();
    QFile fileRead(filePath);
    if(fileRead.open(QIODevice::ReadOnly)){
        QTextStream input(&fileRead);
        input.setCodec("UTF-8");
        while(!input.atEnd()){
            QString line = input.readLine();
            ui->textBrowser->append(line.toStdString().data());
        }
        fileRead.close();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply =
            QMessageBox::question(this,"Exit","Sure to exit?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else {
        return;
    }
}

