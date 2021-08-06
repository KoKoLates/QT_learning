#include "paintwidget.h"

//constructor(record the defalt properties)
PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    scribbling = false; //Before drawing, the mouse button is unclicked
    image = QImage(this->size(),QImage::Format_RGB32);
    //set the size of the canvas
    //QImage::Format_RGB32 : Using 32-bit RGB format, B,G,R,A(transparency) correspond to 0,1,2,3
    image.fill(qRgb(255,255,255)); //set the background color(White)
}

//Paintint terminal function, triggered by update(), become a State function after called
//Only if the mainwindow is closed, it's waiting for triggered by update()
void PaintWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //Painting operators, inherited from PaintWidget class that inherited from mainwindow class
    //close the mainwindow, mean close the PaintWidget, so that painter is closed
    painter.drawImage(0,0,image);
    //draw on the image
}

void PaintWidget::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){ // mouse left button is clicked
        //set the lastPoint and endPoint be the position that the mouse press
        lastPoint = event->pos();
        endPoint = event->pos();
        scribbling = true; // begin to draw(the mouse is clicked)
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){ //the mouse is moving as the left button is press
        endPoint = event->pos(); //refresh the endPoint each time as the mouse move
        paint(image);
        // call the void PaintWidget::paint(QImage &theImage) function and call the paintEvent function due to the update() in paint
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *){
    scribbling = false; //draw finish (mouse is unclicked/release)
    paint(image); //draw the endPoint on the image
}

//drawing on the image
void PaintWidget::paint(QImage &theImage){
    QPainter p(&theImage); //drawing on the theImage
    //theImage is parameter of paintDevice class, it's quote from image(it's equal to draw on the image, literally)
    QPen pen(Qt::black,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin); //pen setting
    p.setPen(pen);
    p.drawLine(lastPoint,endPoint); //connect each point, and it's equal to draw the trace
    lastPoint = endPoint; //lastPoint and endPoint are overlaped
    update(); //refresh
}

//resize the widget size as long as the mainwindow's size is changed
//initialize the defalt as the constructor
void PaintWidget::resizeEvent(QResizeEvent *event){
    QImage *newImage = new QImage(event->size(),QImage::Format_RGB32);
    newImage->fill(qRgb(255,255,255));
    QPainter painter(newImage);
    painter.drawImage(0,0,image);
    image = *newImage;
}
