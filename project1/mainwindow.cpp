#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ordering System");//set the window title
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBox_accepted()
{
    ui->textBrowser->setText("");//initial the textBrowser
    QString product="You have order : ";
    int total_money=0,pay_money;

    //check button status
    if(ui->omurice->checkState()){
        total_money+=90;
        product += "Omurice, ";
    }
    if(ui->pasta->checkState()){
        total_money += 110;
        product += "Pasta, ";
    }
    if(ui->risotto->checkState()){
        total_money += 110;
        product += "Risotto, ";
    }
    if(ui->beef_noodle->checkState()){
        total_money += 130;
        product += "Beef noodle, ";
    }
    if(ui->black_tea->checkState()){
        total_money += 15;
        product += "Black tea, ";
    }
    if(ui->green_tea->checkState()){
        total_money += 15;
        product += "Green tea, ";
    }
    if(ui->cola->checkState()){
        total_money += 20;
        product += "Cola, ";
    }
    if(ui->bubble_tea->checkState()){
        total_money += 50;
        product += "Bubble milk tea, ";
    }

    //the way of payment
    if(ui->cash->isChecked() && total_money != 0){
        pay_money = total_money -10;
    }
    else if(ui->card->isChecked() && total_money != 0){
        pay_money =total_money*0.9;
    }
    else if(total_money==0){ //avoid the checkbox haven't been chosen
        ui->textBrowser->setText("You haven't choose anything");
        return;
    }
    else { //avoid the radio checkbox haven't been chosen
        ui->textBrowser->setText("Please choose the payment method");
        return;
    }

    //display the pay money and what product been chosen
    ui->textBrowser->append(product);
    ui->textBrowser->append("You have to pay : $" + QString::number(pay_money));
}


void MainWindow::on_buttonBox_rejected()
{
    //inital the checkbox to be False
    ui->textBrowser->setText("");
    ui->omurice->setChecked(0);
    ui->pasta->setChecked(0);
    ui->risotto->setChecked(0);
    ui->beef_noodle->setChecked(0);
    ui->black_tea->setChecked(0);
    ui->green_tea->setChecked(0);
    ui->cola->setChecked(0);
    ui->bubble_tea->setChecked(0);

    //initial the radio checkbox
    //use setAutoExclusive to off by defalt
    if(ui->cash->isChecked()){
        ui->cash->setAutoExclusive(false);
        ui->cash->setChecked(0);
    }
    else if(ui->card->isChecked()){
        ui->card->setAutoExclusive(false);
        ui->card->setChecked(0);
    }

    //recover the defalt of radio checkbox
    ui->cash->setAutoExclusive(true);
    ui->card->setAutoExclusive(true);
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
                this,"Exit","Sure to leave this window?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        return;
    }
}

