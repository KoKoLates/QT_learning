#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QThread>
#include <QtGlobal>
#include <QMainWindow>

#include "thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void display1();
    void display2();
    void display3(int);
    void finish();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QThread *thread;
};

#endif // MAINWINDOW_H
