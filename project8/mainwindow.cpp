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

void MainWindow::on_pushButton_clicked()
{
    if(ui->spinBox->value() != 0){ // ensure the interval has been selected
        if(!timer){ // as the QTimer has not been created
            timer = new QTimer(); //then create the QTimer
            connect(timer,SIGNAL(timeout()),this,SLOT(timeOut())); //connect with the display function
        }
        timer->start(ui->spinBox->value()*1000); //start to count in time
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop(); // stop the QTimer
}

void MainWindow::on_pushButton_3_clicked()
{
    timer->stop(); // Stop the QTimer
    delete timer; // delete the object with indicated interval conditions
    timer = 0; // reindicate the QTimer to none and wait for new QTimer object to be created
    timeCount = 0; // turn to zero count
    ui->label_3->setText("count : 0");
}

void MainWindow::timeOut(){
    timeCount += 1; //each time the QTimer call as the time is got, plus one count
    ui->label_3->setText("count : " + QString::number(timeCount)); //display on the label
}

