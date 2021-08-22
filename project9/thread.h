#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QMainWindow>

class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread();
    void run();

signals:
    void sendNum(int);
    void done();
};

#endif // THREAD_H
