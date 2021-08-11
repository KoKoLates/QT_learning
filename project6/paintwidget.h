#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QDebug>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QFileDialog>
#include <QColorDialog>
#include <QMouseEvent>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
    enum shape {Pen,Line,Triangle,Rectangle,Ellipse,Eraser};

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paint(QImage &theImage);
    void resizeEvent(QResizeEvent *);

private:
    PaintWidget::shape type;
    //sourceImage give the Eraser the image to set the brush
    //tempIamge give the template canvas to operate double buffering method
    QImage sourceImage, image, tempImage;
    QPoint lastPoint, endPoint;
    QPen pen;
    QColor color;
    bool scribbling;
    int Size = 4; //initialize the size of the pen

public slots:
    void setShape(PaintWidget::shape t){
        if(t != type) type = t;
        qDebug()<<type;
    }
    void fileOpen();
    void fileSave();
    void setPen();
    void setEraser(){
        pen.setWidth(Size);
        pen.setBrush(QBrush(sourceImage)); // use the source image as the image of the brush
    }
    void setColor(){ // call the QColorDialog to get the color selector
        color = QColorDialog::getColor(Qt::black,this,tr("Select Color"),QColorDialog::ShowAlphaChannel);
        qDebug()<<color; //check the color selected
        setPen();
    }
    void setSize(int size){
        Size = size*2 + 2; // swith the index of the comboBox to the size of the pen
    }
};

#endif // PAINTWIDGET_H
