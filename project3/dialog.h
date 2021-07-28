#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_pushButton_clicked();

    void getData(QString);
    //prototype the function of getData in the privae slots (recieve the signal)

};

#endif // DIALOG_H
