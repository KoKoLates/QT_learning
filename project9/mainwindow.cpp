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
    if(!timer){
        timer = new QTimer(this); //create the QTimer object
        connect(timer,SIGNAL(timeout()),this,SLOT(display1()));
    }
    if(!thread){
        thread = new MyThread; // create the customize QThread object
        connect(thread,SIGNAL(sendNum(int)),this,SLOT(display3(int)));
        connect(thread,SIGNAL(done()),this,SLOT(finish()));
    }
    QTimer::singleShot(500,this,SLOT(display2()));
    timer->start(1000); //start the QTimer
    thread->start(); // start the customize QThread
}

void MainWindow::display1(){
    ui->label->setText("...");
    QTimer::singleShot(500,this,SLOT(display2())); // use single shot to call the waiting after 500 ms
}

void MainWindow::display2(){
    if(!timer)ui->label->setText("Done"); // if there is no QTimer then the thread is finished
    else ui->label->setText("waiting...");

}

void MainWindow::display3(int num){
    ui->label_2->setText(QString::number(num)+"%");
}

void MainWindow::finish(){
    //after the customize QThread call the finish signal
    timer->stop(); // then stop and delete to wait for recreate the QTimer object
    delete timer;
    delete thread;
    timer = 0;
    thread = 0;
    display1();
}


