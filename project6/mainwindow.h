#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QComboBox>
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

private:
    Ui::MainWindow *ui;
    PaintWidget *widget;

private slots:
    void drawPenActionTriggered();
    void drawLineActionTriggered();
    void drawTriActionTriggered();
    void drawRectActionTriggered();
    void drawEllipseActionTriggered();
    void EraserActionTriggered();
    void SizeActionTriggered(int);

signals:
    void drawShape(PaintWidget::shape newShape);
    void drawSize(int newSize);
};
#endif // MAINWINDOW_H
