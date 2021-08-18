#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMessageBox>
#include <QMainWindow>

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
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void timeOut();

private:
    Ui::MainWindow *ui;
    QTimer *timer = 0; // declare QTimer initialize to none
    int timeCount = 0; // use to counting in the program
};
#endif // MAINWINDOW_H
