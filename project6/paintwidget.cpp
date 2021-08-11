#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    scribbling = false;
    type = PaintWidget::Pen;
    image = QImage(this->size(),QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    sourceImage = image;
    tempImage = image; //the new image and tempIamge are equal to the sourceImage
    setPen(); //set the deflaut of the pen
}

void PaintWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(scribbling == true ) painter.drawImage(0,0,tempImage);
    else painter.drawImage(0,0,image);
}

void PaintWidget::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        lastPoint = event->pos();
        endPoint = event->pos();
        scribbling = true;
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        endPoint = event->pos();
        tempImage = image;
        if(type == Pen || type == Eraser)paint(image); //add the Eraser type as the Pen without using double buffers
        else paint(tempImage);
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *){
    scribbling = false;
    if(type != Pen)paint(image);
}

void PaintWidget::setPen(){
    pen.setWidth(Size); //initial size is 4
    pen.setBrush(color); // initial color is black
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
}

void PaintWidget::paint(QImage &theImage){
    QPainter painter(&theImage); //theImage is the parameter of the paint function, it's equal to the image input (so that is image)
    switch (type) {
    case PaintWidget::Pen :{
        setPen();
        painter.setPen(pen);
        painter.drawLine(lastPoint,endPoint);
        lastPoint = endPoint;
        break;
    }
    case PaintWidget::Line :{
        setPen();
        painter.setPen(pen);
        painter.drawLine(lastPoint,endPoint);
        break;
    }
    case PaintWidget::Triangle :{
        setPen();
        painter.setPen(pen);
        int top,buttom,left,right;
        top = (lastPoint.y() < endPoint.y()) ? lastPoint.y() : endPoint.y();
        buttom = (lastPoint.y() > endPoint.y()) ? lastPoint.y() : endPoint.y();
        left = (lastPoint.x() < endPoint.x()) ? lastPoint.x() : endPoint.x();
        right = (lastPoint.x() > endPoint.x()) ? lastPoint.x() : endPoint.x();
        if(lastPoint.y() < endPoint.y()){
            QPoint points[3] = {QPoint(left,buttom),QPoint(right,buttom),QPoint((right + left)/2,top)};
            painter.drawPolygon(points,3);
        }else{
            QPoint points[3] = {QPoint(left,top),QPoint(right,top),QPoint((right + left)/2,buttom)};
            painter.drawPolygon(points,3);
        }
        break;
    }
    case PaintWidget::Rectangle :{
        setPen();
        painter.setPen(pen);
        painter.drawRect(lastPoint.x(),lastPoint.y(),endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());
        break;
    }
    case PaintWidget::Ellipse :{
        setPen();
        painter.setPen(pen);
        painter.drawEllipse(lastPoint.x(),lastPoint.y(),endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());
        break;
    }
    case PaintWidget::Eraser :{
        setEraser(); //change the type of the pen to the Eraser type
        painter.setPen(pen); // the basic type is like Pen, but the pen(color) is different
        painter.drawLine(lastPoint,endPoint);
        lastPoint = endPoint;
        break;
    }
    default:
        break;
    }
    update();
}

//redefined the paintwidget as the constructor as the size of the window is changed
void PaintWidget::resizeEvent(QResizeEvent *event){
    QImage *newImage = new QImage(event->size(),QImage::Format_RGB32);
    newImage->fill(qRgb(255,255,255));
    QPainter painter(newImage);
    painter.drawImage(0,0,image);
    image = *newImage;
    sourceImage = *newImage;
}

void PaintWidget::fileOpen(){
    QString filePath = QFileDialog::getOpenFileName(this,tr("OpenImage"),"",tr("Image(*.png *.jpg)"));
    sourceImage.load(filePath); // load the iamge to the sourceImage
    image = sourceImage.copy().scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    //copy the sourceImage to the image and adjust to the proper size
    sourceImage = image;
    update();
}

void PaintWidget::fileSave(){
    QString filePath = QFileDialog::getSaveFileName(this,tr("SaveImage"),"",tr("Image(*.png *.jpg)"));
    image.save(filePath); //save the image to the indicate path
}
