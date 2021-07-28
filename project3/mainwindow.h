#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Dialog *dlg;

private slots:
    void on_Omurice_currentIndexChanged(int index);

    void on_Pasta_currentIndexChanged(int index);

    void on_Risotto_currentIndexChanged(int index);

    void on_Noodle_currentIndexChanged(int index);

    void on_BlackTea_currentIndexChanged(int index);

    void on_GreenTea_currentIndexChanged(int index);

    void on_Cola_currentIndexChanged(int index);

    void on_Sprite_currentIndexChanged(int index);

    void on_Bubble_currentIndexChanged(int index);

    void on_Puff_currentIndexChanged(int index);

    void on_SDumpling_currentIndexChanged(int index);

    void on_Cheese_currentIndexChanged(int index);

    void on_Tiramisu_currentIndexChanged(int index);

    void on_Haagen_currentIndexChanged(int index);

    void on_Cash_toggled(bool checked);

    void on_Card_toggled(bool checked);

    void on_Cancel_clicked();

    void on_Ensure_clicked();

    void on_Detail_clicked();

private:
    Ui::MainWindow *ui;
    //prototype the function
    void Set_picture();
    void Set_ComboBox_items();
    void SwitchPage();

    //initialize such variable
    int price = 0 ,pay_money;
    int num[14]={0}; //use the integral array to store the number conditions of each product
    QString filePath_txt = "C:/Users/acer/Documents/project3/project3.file/project3.txt";
    QString filePath_csv = "C:/Users/acer/Documents/project3/project3.file/project3.xlsx.csv";

    QStringList product;

signals:
    void sendData(QString);
    //prototype the sendData function in singals (convey the singal)
};
#endif // MAINWINDOW_H
