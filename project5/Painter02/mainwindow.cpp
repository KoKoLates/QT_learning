#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Drawing Demo 2");
    QToolBar *bar = this->addToolBar("Tools");
    QActionGroup *group = new QActionGroup(bar); // put all action in the group

    QAction *drawPenAction = new QAction("Pen",bar);
    drawPenAction->setToolTip("Pen");
    drawPenAction->setCheckable(true);
    drawPenAction->setChecked(true); //the Pen shape is defalt
    group->addAction(drawPenAction);
    bar->addAction(drawPenAction);

    QAction *drawLineAction = new QAction("Line",bar);
    drawLineAction->setToolTip("Line");
    drawLineAction->setCheckable(true);
    group->addAction(drawLineAction);
    bar->addAction(drawLineAction);

    QAction *drawRectangleAction = new QAction("Rectangle",bar);
    drawRectangleAction->setToolTip("Rectangle");
    drawRectangleAction->setCheckable(true);
    group->addAction(drawRectangleAction);
    bar->addAction(drawRectangleAction);

    QAction *drawTriangleAction = new QAction("Triangle",bar);
    drawTriangleAction->setToolTip("Triangle");
    drawTriangleAction->setCheckable(true);
    group->addAction(drawTriangleAction);
    bar->addAction(drawTriangleAction);

    QAction *drawCircleAction = new QAction("Circle",bar);
    drawCircleAction->setToolTip("Circle");
    drawCircleAction->setCheckable(true);
    group->addAction(drawCircleAction);
    bar->addAction(drawCircleAction);

    QAction *drawEllipseAction = new QAction("Ellipse",bar);
    drawEllipseAction->setToolTip("Ellipse");
    drawEllipseAction->setCheckable(true);
    group->addAction(drawEllipseAction);
    bar->addAction(drawEllipseAction);

    statusBar();
    widget = new PaintWidget;
    setCentralWidget(widget);

    connect(drawPenAction,SIGNAL(triggered()),this,SLOT(drawPenActionTriggered()));
    connect(drawLineAction,SIGNAL(triggered()),this,SLOT(drawLineActionTriggered()));
    connect(drawRectangleAction,SIGNAL(triggered()),this,SLOT(drawRectActionTriggered()));
    connect(drawTriangleAction,SIGNAL(triggered()),this,SLOT(drawTriActionTriggered()));
    connect(drawCircleAction,SIGNAL(triggered()),this,SLOT(drawCircleActionTriggered()));
    connect(drawEllipseAction,SIGNAL(triggered()),this,SLOT(drawEllipseActionTriggered()));
    connect(this,SIGNAL(drawShape(PaintWidget::shape)),widget,SLOT(setShape(PaintWidget::shape)));
}

void MainWindow::drawPenActionTriggered(){ emit drawShape(PaintWidget::Pen);}
void MainWindow::drawLineActionTriggered(){ emit drawShape(PaintWidget::Line);}
void MainWindow::drawRectActionTriggered(){ emit drawShape(PaintWidget::Rectangle);}
void MainWindow::drawTriActionTriggered(){ emit drawShape(PaintWidget::Triangle);}
void MainWindow::drawCircleActionTriggered(){ emit drawShape(PaintWidget::Circle);}
void MainWindow::drawEllipseActionTriggered(){ emit drawShape(PaintWidget::Ellipse);}

MainWindow::~MainWindow()
{
    delete ui;
}

