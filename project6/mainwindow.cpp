#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget = new PaintWidget(this);
    setCentralWidget(widget);
    this->setCursor(Qt::CrossCursor);  //set the mouse cursor to the crossCursor type
    this->setWindowIcon(QIcon(":/images/images/title.jpg")); //set the icon of the mainwindow

    //the actions are added in the Qt designer, so here is just add the icon of each action
    ui->actionopen_file->setIcon(QIcon(":/images/images/open.png"));
    ui->actionsave->setIcon(QIcon(":/images/images/save.png"));

    //Tool Bar
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::TopToolBarArea,toolBar); //initialize the position of the tool bar to the top of the widget
    QActionGroup *group = new QActionGroup(toolBar); // create a group for the actions of tool bar

    //storing the image in the images.qrc and give the relative path to display the images
    QAction *drawPen = new QAction("Pen",toolBar);
    drawPen->setToolTip("Pen");
    drawPen->setIcon(QIcon(":/images/images/pen.png"));
    drawPen->setChecked(true); //set the Pen type be the default as the constructor
    drawPen->setCheckable(true);
    group->addAction(drawPen);
    toolBar->addAction(drawPen);

    QAction *drawLine = new QAction("Line",toolBar);
    drawLine->setToolTip("Line");
    drawLine->setIcon(QIcon(":/images/images/line.png"));
    drawLine->setCheckable(true);
    group->addAction(drawLine);
    toolBar->addAction(drawLine);

    QAction *drawEllipse = new QAction("Ellipse",toolBar);
    drawEllipse->setToolTip("Ellipse");
    drawEllipse->setIcon(QIcon(":/images/images/circle.png"));
    drawEllipse->setCheckable(true);
    group->addAction(drawEllipse);
    toolBar->addAction(drawEllipse);

    QAction *drawRect = new QAction("Rectangle",toolBar);
    drawRect->setToolTip("Rectangle");
    drawRect->setIcon(QIcon(":/images/images/rectangle.png"));
    drawRect->setCheckable(true);
    group->addAction(drawRect);
    toolBar->addAction(drawRect);

    QAction *drawTri = new QAction("Triangle",toolBar);
    drawTri->setToolTip("Triangle");
    drawTri->setIcon(QIcon(":/images/images/triangle.png"));
    drawTri->setCheckable(true);
    group->addAction(drawTri);
    toolBar->addAction(drawTri);

    QAction *Eraser = new QAction("Eraser",toolBar);
    Eraser->setToolTip("Eraser");
    Eraser->setIcon(QIcon(":/images/images/eraser.png"));
    Eraser->setCheckable(true);
    group->addAction(Eraser);
    toolBar->addAction(Eraser);

    QAction *Color = new QAction("Color",toolBar);
    Color->setToolTip("Color");
    Color->setIcon(QIcon(":/images/images/color.png"));
    Color->setCheckable(true);
    group->addAction(Color);
    toolBar->addAction(Color);

    QComboBox *Size = new QComboBox(toolBar);
    Size->setFixedSize(55,35); //set the size of the comboBox
    for(int i=4; i<=20; i+=2) Size->addItem(QString::number(i)); //add items to the comboBox
    toolBar->addWidget(Size);

    // connect the signals and slots
    connect(ui->actionopen_file,&QAction::triggered,widget,&PaintWidget::fileOpen);
    connect(ui->actionsave,&QAction::triggered,widget,&PaintWidget::fileSave);

    connect(drawPen,&QAction::triggered,this,&MainWindow::drawPenActionTriggered);
    connect(drawLine,&QAction::triggered,this,&MainWindow::drawLineActionTriggered);
    connect(drawEllipse,&QAction::triggered,this,&MainWindow::drawEllipseActionTriggered);
    connect(drawRect,&QAction::triggered,this,&MainWindow::drawRectActionTriggered);
    connect(drawTri,&QAction::triggered,this,&MainWindow::drawTriActionTriggered);
    connect(Eraser,&QAction::triggered,this,&MainWindow::EraserActionTriggered);
    connect(Color,&QAction::triggered,widget,&PaintWidget::setColor);

    connect(Size,SIGNAL(currentIndexChanged(int)),this,SLOT(SizeActionTriggered(int)));
    connect(this,SIGNAL(drawShape(PaintWidget::shape)),widget,SLOT(setShape(PaintWidget::shape)));
    connect(this,SIGNAL(drawSize(int)),widget,SLOT(setSize(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPenActionTriggered(){ emit drawShape(PaintWidget::Pen);}
void MainWindow::drawLineActionTriggered(){ emit drawShape(PaintWidget::Line);}
void MainWindow::drawTriActionTriggered(){ emit drawShape(PaintWidget::Triangle);}
void MainWindow::drawRectActionTriggered(){ emit drawShape(PaintWidget::Rectangle);}
void MainWindow::drawEllipseActionTriggered(){ emit drawShape(PaintWidget::Ellipse);}
void MainWindow::EraserActionTriggered(){ emit drawShape(PaintWidget::Eraser);}
void MainWindow::SizeActionTriggered(int newSize){ emit drawSize(newSize);}
