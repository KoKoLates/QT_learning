#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//define the getData function
//set the text(QString) send from the sendData function in the mainwindow
void Dialog::getData(QString data){
    ui->textBrowser->setText(data);
}

//close the subwindow as this button is checked
void Dialog::on_pushButton_clicked()
{
    this->close();
}

