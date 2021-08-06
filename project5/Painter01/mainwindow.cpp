#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Drawing Demo 1");
    widget = new PaintWidget;
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

