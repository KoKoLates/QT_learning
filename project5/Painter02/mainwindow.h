#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "paintwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void drawShape(PaintWidget::shape newShape);
    //send the signal to paintWidget to change the type of shape

private slots:
    void drawPenActionTriggered();
    void drawLineActionTriggered();
    void drawRectActionTriggered();
    void drawTriActionTriggered();
    void drawCircleActionTriggered();
    void drawEllipseActionTriggered();

private:
    Ui::MainWindow *ui;
    PaintWidget *widget; //create a new paintWidget module
};
#endif // MAINWINDOW_H
