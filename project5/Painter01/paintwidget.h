#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event); //drawing terminal function, triggered by the update() function
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paint(QImage &theImage); //drawing tool
    void resizeEvent(QResizeEvent *event); // paintWidget resize event

private:
    bool scribbling; //determine it's drawing or not(judge that mouse is operated or not)
    QImage image; // declare canvas to draw
    QPoint lastPoint, endPoint;
    //lastPoint record the last point of the trace, due to the paintint trace is constructed by infinite point
    //endPoint record the postion of the end point
};

#endif // PAINTWIDGET_H
