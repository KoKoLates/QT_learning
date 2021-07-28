/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *MainTitle;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *Meal;
    QPushButton *Drink;
    QPushButton *Dessert;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *Cash;
    QRadioButton *Card;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *Detail;
    QPushButton *Cancel;
    QPushButton *Ensure;
    QLabel *PriceStatus;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget;
    QLabel *omurice_pic;
    QLabel *omurice_tit;
    QComboBox *Omurice;
    QWidget *widget_2;
    QLabel *pasta_pic;
    QLabel *pasta_tit;
    QComboBox *Pasta;
    QWidget *widget_3;
    QLabel *risotto_pic;
    QLabel *risotto_tit;
    QComboBox *Risotto;
    QWidget *widget_4;
    QLabel *noodle_pic;
    QLabel *noodle_tit;
    QComboBox *Noodle;
    QWidget *page_2;
    QWidget *widget_5;
    QLabel *blacktea_pic;
    QLabel *blavktea_tit;
    QComboBox *BlackTea;
    QWidget *widget_6;
    QLabel *greentea_pic;
    QLabel *greentea_tit;
    QComboBox *GreenTea;
    QWidget *widget_7;
    QLabel *cola_pic;
    QLabel *cola_tit;
    QComboBox *Cola;
    QWidget *widget_8;
    QLabel *sprite_pic;
    QLabel *sprite_tit;
    QComboBox *Sprite;
    QWidget *widget_9;
    QLabel *bubble_pic;
    QLabel *bubble_tit;
    QComboBox *Bubble;
    QWidget *page_3;
    QWidget *widget_10;
    QLabel *puff_pic;
    QLabel *puff_tit;
    QComboBox *Puff;
    QWidget *widget_11;
    QLabel *sdumpling_pic;
    QLabel *sdumpling_tit;
    QComboBox *SDumpling;
    QWidget *widget_12;
    QLabel *cheese_pic;
    QLabel *cheese_tit;
    QComboBox *Cheese;
    QWidget *widget_13;
    QLabel *tiramisu_pic;
    QLabel *tiramisu_tit;
    QComboBox *Tiramisu;
    QWidget *widget_14;
    QLabel *haagen_pic;
    QLabel *haggen_tit;
    QComboBox *Haagen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 357);
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainTitle = new QLabel(centralwidget);
        MainTitle->setObjectName(QString::fromUtf8("MainTitle"));
        MainTitle->setGeometry(QRect(20, 20, 122, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font1.setPointSize(12);
        MainTitle->setFont(font1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 104, 127));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Meal = new QPushButton(groupBox);
        Meal->setObjectName(QString::fromUtf8("Meal"));

        verticalLayout->addWidget(Meal);

        Drink = new QPushButton(groupBox);
        Drink->setObjectName(QString::fromUtf8("Drink"));

        verticalLayout->addWidget(Drink);

        Dessert = new QPushButton(groupBox);
        Dessert->setObjectName(QString::fromUtf8("Dessert"));

        verticalLayout->addWidget(Dessert);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 210, 101, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font2.setPointSize(7);
        groupBox_2->setFont(font2);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Cash = new QRadioButton(groupBox_2);
        Cash->setObjectName(QString::fromUtf8("Cash"));

        verticalLayout_2->addWidget(Cash);

        Card = new QRadioButton(groupBox_2);
        Card->setObjectName(QString::fromUtf8("Card"));

        verticalLayout_2->addWidget(Card);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(150, 10, 376, 51));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Detail = new QPushButton(groupBox_3);
        Detail->setObjectName(QString::fromUtf8("Detail"));

        horizontalLayout->addWidget(Detail);

        Cancel = new QPushButton(groupBox_3);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout->addWidget(Cancel);

        Ensure = new QPushButton(groupBox_3);
        Ensure->setObjectName(QString::fromUtf8("Ensure"));

        horizontalLayout->addWidget(Ensure);

        PriceStatus = new QLabel(groupBox_3);
        PriceStatus->setObjectName(QString::fromUtf8("PriceStatus"));

        horizontalLayout->addWidget(PriceStatus);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 70, 401, 241));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 131, 121));
        omurice_pic = new QLabel(widget);
        omurice_pic->setObjectName(QString::fromUtf8("omurice_pic"));
        omurice_pic->setGeometry(QRect(-1, -1, 131, 81));
        omurice_tit = new QLabel(widget);
        omurice_tit->setObjectName(QString::fromUtf8("omurice_tit"));
        omurice_tit->setGeometry(QRect(10, 90, 60, 16));
        omurice_tit->setFont(font2);
        Omurice = new QComboBox(widget);
        Omurice->setObjectName(QString::fromUtf8("Omurice"));
        Omurice->setGeometry(QRect(80, 90, 41, 21));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(140, 0, 131, 121));
        pasta_pic = new QLabel(widget_2);
        pasta_pic->setObjectName(QString::fromUtf8("pasta_pic"));
        pasta_pic->setGeometry(QRect(-1, -1, 131, 81));
        pasta_tit = new QLabel(widget_2);
        pasta_tit->setObjectName(QString::fromUtf8("pasta_tit"));
        pasta_tit->setGeometry(QRect(10, 90, 60, 16));
        pasta_tit->setFont(font2);
        Pasta = new QComboBox(widget_2);
        Pasta->setObjectName(QString::fromUtf8("Pasta"));
        Pasta->setGeometry(QRect(80, 90, 41, 21));
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(270, 0, 131, 121));
        risotto_pic = new QLabel(widget_3);
        risotto_pic->setObjectName(QString::fromUtf8("risotto_pic"));
        risotto_pic->setGeometry(QRect(-1, -1, 131, 81));
        risotto_tit = new QLabel(widget_3);
        risotto_tit->setObjectName(QString::fromUtf8("risotto_tit"));
        risotto_tit->setGeometry(QRect(10, 90, 60, 16));
        risotto_tit->setFont(font2);
        Risotto = new QComboBox(widget_3);
        Risotto->setObjectName(QString::fromUtf8("Risotto"));
        Risotto->setGeometry(QRect(80, 90, 41, 21));
        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(10, 120, 131, 121));
        noodle_pic = new QLabel(widget_4);
        noodle_pic->setObjectName(QString::fromUtf8("noodle_pic"));
        noodle_pic->setGeometry(QRect(-1, -1, 131, 81));
        noodle_tit = new QLabel(widget_4);
        noodle_tit->setObjectName(QString::fromUtf8("noodle_tit"));
        noodle_tit->setGeometry(QRect(10, 90, 60, 16));
        noodle_tit->setFont(font2);
        Noodle = new QComboBox(widget_4);
        Noodle->setObjectName(QString::fromUtf8("Noodle"));
        Noodle->setGeometry(QRect(80, 90, 41, 21));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        widget_5 = new QWidget(page_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 0, 131, 121));
        blacktea_pic = new QLabel(widget_5);
        blacktea_pic->setObjectName(QString::fromUtf8("blacktea_pic"));
        blacktea_pic->setGeometry(QRect(-1, -1, 131, 81));
        blavktea_tit = new QLabel(widget_5);
        blavktea_tit->setObjectName(QString::fromUtf8("blavktea_tit"));
        blavktea_tit->setGeometry(QRect(10, 90, 60, 16));
        blavktea_tit->setFont(font2);
        BlackTea = new QComboBox(widget_5);
        BlackTea->setObjectName(QString::fromUtf8("BlackTea"));
        BlackTea->setGeometry(QRect(80, 90, 41, 21));
        widget_6 = new QWidget(page_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(140, 0, 131, 121));
        greentea_pic = new QLabel(widget_6);
        greentea_pic->setObjectName(QString::fromUtf8("greentea_pic"));
        greentea_pic->setGeometry(QRect(-1, -1, 131, 81));
        greentea_tit = new QLabel(widget_6);
        greentea_tit->setObjectName(QString::fromUtf8("greentea_tit"));
        greentea_tit->setGeometry(QRect(10, 90, 60, 16));
        greentea_tit->setFont(font2);
        GreenTea = new QComboBox(widget_6);
        GreenTea->setObjectName(QString::fromUtf8("GreenTea"));
        GreenTea->setGeometry(QRect(80, 90, 41, 21));
        widget_7 = new QWidget(page_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(270, 0, 131, 121));
        cola_pic = new QLabel(widget_7);
        cola_pic->setObjectName(QString::fromUtf8("cola_pic"));
        cola_pic->setGeometry(QRect(-1, -1, 131, 81));
        cola_tit = new QLabel(widget_7);
        cola_tit->setObjectName(QString::fromUtf8("cola_tit"));
        cola_tit->setGeometry(QRect(10, 90, 60, 16));
        cola_tit->setFont(font2);
        Cola = new QComboBox(widget_7);
        Cola->setObjectName(QString::fromUtf8("Cola"));
        Cola->setGeometry(QRect(80, 90, 41, 21));
        widget_8 = new QWidget(page_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(10, 120, 131, 121));
        sprite_pic = new QLabel(widget_8);
        sprite_pic->setObjectName(QString::fromUtf8("sprite_pic"));
        sprite_pic->setGeometry(QRect(-1, -1, 131, 81));
        sprite_tit = new QLabel(widget_8);
        sprite_tit->setObjectName(QString::fromUtf8("sprite_tit"));
        sprite_tit->setGeometry(QRect(10, 90, 60, 16));
        sprite_tit->setFont(font2);
        Sprite = new QComboBox(widget_8);
        Sprite->setObjectName(QString::fromUtf8("Sprite"));
        Sprite->setGeometry(QRect(80, 90, 41, 21));
        widget_9 = new QWidget(page_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(140, 120, 131, 121));
        bubble_pic = new QLabel(widget_9);
        bubble_pic->setObjectName(QString::fromUtf8("bubble_pic"));
        bubble_pic->setGeometry(QRect(-1, -1, 131, 81));
        bubble_tit = new QLabel(widget_9);
        bubble_tit->setObjectName(QString::fromUtf8("bubble_tit"));
        bubble_tit->setGeometry(QRect(10, 90, 60, 16));
        bubble_tit->setFont(font2);
        Bubble = new QComboBox(widget_9);
        Bubble->setObjectName(QString::fromUtf8("Bubble"));
        Bubble->setGeometry(QRect(80, 90, 41, 21));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        widget_10 = new QWidget(page_3);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setGeometry(QRect(10, 0, 131, 121));
        puff_pic = new QLabel(widget_10);
        puff_pic->setObjectName(QString::fromUtf8("puff_pic"));
        puff_pic->setGeometry(QRect(-1, -1, 131, 81));
        puff_tit = new QLabel(widget_10);
        puff_tit->setObjectName(QString::fromUtf8("puff_tit"));
        puff_tit->setGeometry(QRect(10, 90, 60, 16));
        puff_tit->setFont(font2);
        Puff = new QComboBox(widget_10);
        Puff->setObjectName(QString::fromUtf8("Puff"));
        Puff->setGeometry(QRect(80, 90, 41, 21));
        widget_11 = new QWidget(page_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(140, 0, 131, 121));
        sdumpling_pic = new QLabel(widget_11);
        sdumpling_pic->setObjectName(QString::fromUtf8("sdumpling_pic"));
        sdumpling_pic->setGeometry(QRect(-1, -1, 131, 81));
        sdumpling_tit = new QLabel(widget_11);
        sdumpling_tit->setObjectName(QString::fromUtf8("sdumpling_tit"));
        sdumpling_tit->setGeometry(QRect(10, 90, 60, 16));
        sdumpling_tit->setFont(font2);
        SDumpling = new QComboBox(widget_11);
        SDumpling->setObjectName(QString::fromUtf8("SDumpling"));
        SDumpling->setGeometry(QRect(80, 90, 41, 21));
        widget_12 = new QWidget(page_3);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(270, 0, 131, 121));
        cheese_pic = new QLabel(widget_12);
        cheese_pic->setObjectName(QString::fromUtf8("cheese_pic"));
        cheese_pic->setGeometry(QRect(-1, -1, 131, 81));
        cheese_tit = new QLabel(widget_12);
        cheese_tit->setObjectName(QString::fromUtf8("cheese_tit"));
        cheese_tit->setGeometry(QRect(10, 90, 60, 16));
        cheese_tit->setFont(font2);
        Cheese = new QComboBox(widget_12);
        Cheese->setObjectName(QString::fromUtf8("Cheese"));
        Cheese->setGeometry(QRect(80, 90, 41, 21));
        widget_13 = new QWidget(page_3);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setGeometry(QRect(10, 120, 131, 121));
        tiramisu_pic = new QLabel(widget_13);
        tiramisu_pic->setObjectName(QString::fromUtf8("tiramisu_pic"));
        tiramisu_pic->setGeometry(QRect(-1, -1, 131, 81));
        tiramisu_tit = new QLabel(widget_13);
        tiramisu_tit->setObjectName(QString::fromUtf8("tiramisu_tit"));
        tiramisu_tit->setGeometry(QRect(10, 90, 60, 16));
        tiramisu_tit->setFont(font2);
        Tiramisu = new QComboBox(widget_13);
        Tiramisu->setObjectName(QString::fromUtf8("Tiramisu"));
        Tiramisu->setGeometry(QRect(80, 90, 41, 21));
        widget_14 = new QWidget(page_3);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setGeometry(QRect(140, 120, 131, 121));
        haagen_pic = new QLabel(widget_14);
        haagen_pic->setObjectName(QString::fromUtf8("haagen_pic"));
        haagen_pic->setGeometry(QRect(-1, -1, 131, 81));
        haggen_tit = new QLabel(widget_14);
        haggen_tit->setObjectName(QString::fromUtf8("haggen_tit"));
        haggen_tit->setGeometry(QRect(10, 90, 60, 16));
        haggen_tit->setFont(font2);
        Haagen = new QComboBox(widget_14);
        Haagen->setObjectName(QString::fromUtf8("Haagen"));
        Haagen->setGeometry(QRect(80, 90, 41, 21));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 550, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MainTitle->setText(QCoreApplication::translate("MainWindow", "Ordering System", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\244\220\351\273\236", nullptr));
        Meal->setText(QCoreApplication::translate("MainWindow", "\344\270\273\351\243\237", nullptr));
        Drink->setText(QCoreApplication::translate("MainWindow", "\351\243\262\346\226\231", nullptr));
        Dessert->setText(QCoreApplication::translate("MainWindow", "\347\224\234\351\273\236", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\273\230\350\262\273\346\226\271\345\274\217", nullptr));
        Cash->setText(QCoreApplication::translate("MainWindow", "\347\217\276\351\207\221 $10off", nullptr));
        Card->setText(QCoreApplication::translate("MainWindow", "\345\210\267\345\215\241 10%off", nullptr));
        groupBox_3->setTitle(QString());
        Detail->setText(QCoreApplication::translate("MainWindow", "\351\273\236\351\244\220\346\230\216\347\264\260", nullptr));
        Cancel->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250\345\217\226\346\266\210", nullptr));
        Ensure->setText(QCoreApplication::translate("MainWindow", "\347\242\272\350\252\215\344\273\230\346\254\276", nullptr));
        PriceStatus->setText(QCoreApplication::translate("MainWindow", "Payment method", nullptr));
        omurice_pic->setText(QCoreApplication::translate("MainWindow", "Picture 1", nullptr));
        omurice_tit->setText(QCoreApplication::translate("MainWindow", "\350\233\213\345\214\205\351\243\257 $90", nullptr));
        pasta_pic->setText(QCoreApplication::translate("MainWindow", "Picture 2", nullptr));
        pasta_tit->setText(QCoreApplication::translate("MainWindow", "\347\276\251\345\244\247\345\210\251\351\272\265 $110", nullptr));
        risotto_pic->setText(QCoreApplication::translate("MainWindow", "Picture 3", nullptr));
        risotto_tit->setText(QCoreApplication::translate("MainWindow", "\347\207\211\351\243\257 $110", nullptr));
        noodle_pic->setText(QCoreApplication::translate("MainWindow", "Picture 4", nullptr));
        noodle_tit->setText(QCoreApplication::translate("MainWindow", "\347\211\233\350\202\211\351\272\265 $130", nullptr));
        blacktea_pic->setText(QCoreApplication::translate("MainWindow", "Picture 5", nullptr));
        blavktea_tit->setText(QCoreApplication::translate("MainWindow", "\347\264\205\350\214\266 $15", nullptr));
        greentea_pic->setText(QCoreApplication::translate("MainWindow", "Picture 6", nullptr));
        greentea_tit->setText(QCoreApplication::translate("MainWindow", "\347\266\240\350\214\266 $15", nullptr));
        cola_pic->setText(QCoreApplication::translate("MainWindow", "Picture 7", nullptr));
        cola_tit->setText(QCoreApplication::translate("MainWindow", "\345\217\257\346\250\202 $20", nullptr));
        sprite_pic->setText(QCoreApplication::translate("MainWindow", "Picture 8", nullptr));
        sprite_tit->setText(QCoreApplication::translate("MainWindow", "\351\233\252\347\242\247 $20", nullptr));
        bubble_pic->setText(QCoreApplication::translate("MainWindow", "Picture 9", nullptr));
        bubble_tit->setText(QCoreApplication::translate("MainWindow", "\347\217\215\347\217\240\345\245\266\350\214\266 $50", nullptr));
        puff_pic->setText(QCoreApplication::translate("MainWindow", "Picture 10", nullptr));
        puff_tit->setText(QCoreApplication::translate("MainWindow", "\346\263\241\350\212\231 $35", nullptr));
        sdumpling_pic->setText(QCoreApplication::translate("MainWindow", "Picture 11", nullptr));
        sdumpling_tit->setText(QCoreApplication::translate("MainWindow", "\347\202\270\346\271\257\345\234\223 $35", nullptr));
        cheese_pic->setText(QCoreApplication::translate("MainWindow", "Picture 12", nullptr));
        cheese_tit->setText(QCoreApplication::translate("MainWindow", "\344\271\263\351\205\252\350\233\213\347\263\225 $45", nullptr));
        tiramisu_pic->setText(QCoreApplication::translate("MainWindow", "Picture 13", nullptr));
        tiramisu_tit->setText(QCoreApplication::translate("MainWindow", "\346\217\220\346\213\211\347\261\263\350\230\207 $45", nullptr));
        haagen_pic->setText(QCoreApplication::translate("MainWindow", "Picture 14", nullptr));
        haggen_tit->setText(QCoreApplication::translate("MainWindow", "\345\223\210\346\240\271\351\201\224\346\226\257 $55", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
