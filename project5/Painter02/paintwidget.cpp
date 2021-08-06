#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    scribbling = false; //Before drawing, the mouse button is unclicked
    type = PaintWidget::Pen; //set the Pen type be the defalt
    image = QImage(this->size(),QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    tempImage = image; //set the properties of tempImage that equals to image
}

void PaintWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(scribbling == true ) painter.drawImage(0,0,tempImage);
    // if it's drawing, the mouse is moving with clicked, then paint on tempImage
    else painter.drawImage(0,0,image);
    // if the mouse is release, then store in the image
}

void PaintWidget::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        lastPoint = event->pos();
        scribbling = true;
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        endPoint = event->pos();
        tempImage = image;
        if(type == Pen)paint(image); //if the shape type is Pen, then draw on the image directly
        else paint(tempImage); // otherwise, using double buffer
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *){
    scribbling = false;
    if(type != Pen) paint(image);
}

void PaintWidget::paint(QImage &theImage){
    QPainter p(&theImage);
    QPen pen(Qt::black,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin); //set the prorperties of pen
    p.setPen(pen);
    switch (type) {
    // define the type of Pen
    case PaintWidget::Pen :{
        p.drawLine(lastPoint,endPoint);
        lastPoint = endPoint;
        break;
    }
    // define the type of Line
    case PaintWidget::Line :{
        p.drawLine(lastPoint,endPoint);
        break;
    }
    // define the type of Rectangle
    case PaintWidget::Rectangle :{
        p.drawRect(lastPoint.x(),lastPoint.y(),endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());
        break;
    }
    // define the type of Triangle
    case PaintWidget::Triangle :{
        int top,buttom,left,right;
        top = (lastPoint.y() < endPoint.y()) ? lastPoint.y() : endPoint.y();
        buttom = (lastPoint.y() > endPoint.y()) ? lastPoint.y() : endPoint.y();
        left = (lastPoint.x() < endPoint.x()) ? lastPoint.x() : endPoint.x();
        right = (lastPoint.x() > endPoint.x()) ? lastPoint.x() : endPoint.x();

        if(lastPoint.y() < endPoint.y()){
            QPoint points[3] = {QPoint(left,buttom),QPoint(right,buttom),QPoint((right + left)/2,top)};
            p.drawPolygon(points,3);
        }else{
            QPoint points[3] = {QPoint(left,top),QPoint(right,top),QPoint((right + left)/2,buttom)};
            p.drawPolygon(points,3);
        }
        break;
    }
    // define the type of Circle
    case PaintWidget::Circle :{
        double length =((endPoint.x()-lastPoint.x()) > (endPoint.y()-lastPoint.y())) ? (endPoint.x()-lastPoint.x()) : (endPoint.y()-lastPoint.y());
        p.drawEllipse(lastPoint.x(),endPoint.y(),length,length);
        break;
    }
    // define the type of Ellipse
    case PaintWidget::Ellipse :{
        p.drawEllipse(lastPoint.x(),lastPoint.y(),endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());
        break;
    }
    default:
        break;
    }
    update(); //refresh
}

void PaintWidget::resizeEvent(QResizeEvent *event){
    QImage *newImage = new QImage(event->size(),QImage::Format_RGB32);
    newImage->fill(qRgb(255,255,255));
    QPainter painter(newImage);
    painter.drawImage(0,0,image);
    image = *newImage;
}
