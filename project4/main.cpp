#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class EventLabel : public QLabel{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

void EventLabel::mouseMoveEvent(QMouseEvent *event){
    QString msg;
    msg.sprintf("<center><h1>Move: (%d, %d)</h1></center>",event->x(),event->y());
    this->setText(msg);
}

void EventLabel::mousePressEvent(QMouseEvent *event){
    QString msg;
    msg.sprintf("<center><h1>Press: (%d, %d)</h1></center>",event->x(),event->y());
    this->setText(msg);
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event){
    QString msg;
    msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",event->x(),event->y());
    this->setText(msg);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(900,600);
    label->show();

    return a.exec();
}
