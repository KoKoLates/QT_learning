#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QImage>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
    enum shape{Pen,Line,Rectangle,Triangle,Circle,Ellipse}; //enumeration: shape type

private:
    PaintWidget::shape type;
    QImage image,tempImage; //declare the canvas and buffer canvas
    QPoint lastPoint,endPoint; //record the position properties in lastPoint and endPoint
    bool scribbling; // judge the mouse is operated or not

protected:
    void paintEvent(QPaintEvent *); //terminal function triggered by the update() function
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paint(QImage &theImage); //drawing tool
    void resizeEvent(QResizeEvent *); //paintWidget resize event

public slots:
    //receive the signal emit from the mainwindow
    void setShape(PaintWidget::shape t){
        if(t != type) type = t;
        qDebug()<<type; //check the receive succeed or not
    }
};

#endif // PAINTWIDGET_H
