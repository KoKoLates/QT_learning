#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMatrix>

class PaintWidget : public QWidget{
protected:
    void paintEvent(QPaintEvent *);
};

void PaintWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QFont font("time",15,QFont::Bold);
    painter.setFont(font);
    painter.setPen(Qt::black);

    for(int i=0; i<36; i++){ //rotate 36 times
        QMatrix matrix;
        matrix.translate(250,250); // set (250,250) be the origin
        matrix.rotate((float)i*10); // rotate 10 degree each time
        painter.setMatrix(matrix); //use this QMatrix

        QColor color;
        color.setHsv(i*10, 255, 255);
        painter.setBrush(color);
        painter.drawRect(70, -10, 80, 10);

        QString str;
        str.sprintf("H=%d",i*10);
        painter.drawText(80 + 70 + 5, 0, str);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PaintWidget widget;
    widget.setWindowTitle("QMatrix");
    widget.resize(500,500);
    widget.show();

    return a.exec();
}
