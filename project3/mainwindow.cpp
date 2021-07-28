#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Ordering System");
    //initialize the pictures and items in comboBox
    Set_picture();
    Set_ComboBox_items();

    //Set the connect with the Button and the SwitchPage function
    connect(ui->Meal,&QPushButton::clicked,this,&MainWindow::SwitchPage);
    connect(ui->Drink,&QPushButton::clicked,this,&MainWindow::SwitchPage);
    connect(ui->Dessert,&QPushButton::clicked,this,&MainWindow::SwitchPage);
    //MainWindow create the subwindow
    MainWindow::dlg = new Dialog;
    connect(this,SIGNAL(sendData(QString)),dlg,SLOT(getData(QString)));
    //connect the sendData function in mainWindow with the getData function in subwindow

    product<<"Oumrice, "<<"Pasta, "<<"Risotto, "<<"BeefNoodle, "<<"BlackTea, "<<"GreenTea, "<<"Cola, "<<"Sprite, "<<
             "BubbleMilkTea, "<<"Puffs, "<<"RiceBall, "<<"CheeseCake, "<<"TiramisuCake, "<<"HaagenDas, ";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Set_picture(){

    //set Meal picture
    QPixmap Omurice("C:/Users/acer/Documents/project3/project3.pic/omurice.png");
    QPixmap Pasta("C:/Users/acer/Documents/project3/project3.pic/spaghetti.png");
    QPixmap Risotto("C:/Users/acer/Documents/project3/project3.pic/risotto.png");
    QPixmap BeefNoodle("C:/Users/acer/Documents/project3/project3.pic/noodle.png");
    ui->omurice_pic->setPixmap(Omurice.scaled(ui->omurice_pic->width(),ui->omurice_pic->height(),Qt::KeepAspectRatio));
    ui->pasta_pic->setPixmap(Pasta.scaled(ui->pasta_pic->width(),ui->pasta_pic->height(),Qt::KeepAspectRatio));
    ui->risotto_pic->setPixmap(Risotto.scaled(ui->risotto_pic->width(),ui->risotto_pic->height(),Qt::KeepAspectRatio));
    ui->noodle_pic->setPixmap(BeefNoodle.scaled(ui->noodle_pic->width(),ui->noodle_pic->height(),Qt::KeepAspectRatio));

    //set Drink picture
    QPixmap BlackTea("C:/Users/acer/Documents/project3/project3.pic/black-tea.png");
    QPixmap GreenTea("C:/Users/acer/Documents/project3/project3.pic/ice-tea.png");
    QPixmap Cola("C:/Users/acer/Documents/project3/project3.pic/cola.png");
    QPixmap Sprite("C:/Users/acer/Documents/project3/project3.pic/soda.png");
    QPixmap BubbleTea("C:/Users/acer/Documents/project3/project3.pic/bubble-tea.png");
    ui->blacktea_pic->setPixmap(BlackTea.scaled(ui->blacktea_pic->width(),ui->blacktea_pic->height(),Qt::KeepAspectRatio));
    ui->greentea_pic->setPixmap(GreenTea.scaled(ui->greentea_pic->width(),ui->greentea_pic->height(),Qt::KeepAspectRatio));
    ui->cola_pic->setPixmap(Cola.scaled(ui->cola_pic->width(),ui->cola_pic->height(),Qt::KeepAspectRatio));
    ui->sprite_pic->setPixmap(Sprite.scaled(ui->sprite_pic->width(),ui->sprite_pic->height(),Qt::KeepAspectRatio));
    ui->bubble_pic->setPixmap(BubbleTea.scaled(ui->bubble_pic->width(),ui->bubble_pic->height(),Qt::KeepAspectRatio));

    //set Dessert picture
    QPixmap Puffs("C:/Users/acer/Documents/project3/project3.pic/pastry.png");
    QPixmap RiceBall("C:/Users/acer/Documents/project3/project3.pic/sdumpling.jpg");
    QPixmap ChzCake("C:/Users/acer/Documents/project3/project3.pic/cheese.jpg");
    QPixmap Tiramisu("C:/Users/acer/Documents/project3/project3.pic/tiramisu.jpg");
    QPixmap Haagen("C:/Users/acer/Documents/project3/project3.pic/haagen.png");
    ui->puff_pic->setPixmap(Puffs.scaled(ui->puff_pic->width(),ui->puff_pic->height(),Qt::KeepAspectRatio));
    ui->sdumpling_pic->setPixmap(RiceBall.scaled(ui->sdumpling_pic->width(),ui->sdumpling_pic->height(),Qt::KeepAspectRatio));
    ui->cheese_pic->setPixmap(ChzCake.scaled(ui->cheese_pic->width(),ui->cheese_pic->height(),Qt::KeepAspectRatio));
    ui->tiramisu_pic->setPixmap(Tiramisu.scaled(ui->tiramisu_pic->width(),ui->tiramisu_pic->height(),Qt::KeepAspectRatio));
    ui->haagen_pic->setPixmap(Haagen.scaled(ui->haagen_pic->width(),ui->haagen_pic->height(),Qt::KeepAspectRatio));
}

void MainWindow::Set_ComboBox_items(){
    //set all comboBox with items from 0 to 3
    for(int i=0 ; i<=3 ; i++){
        ui->Omurice->addItem(QString::number(i));
        ui->Pasta->addItem(QString::number(i));
        ui->Risotto->addItem(QString::number(i));
        ui->Noodle->addItem(QString::number(i));
        ui->BlackTea->addItem(QString::number(i));
        ui->GreenTea->addItem(QString::number(i));
        ui->Cola->addItem(QString::number(i));
        ui->Sprite->addItem(QString::number(i));
        ui->Bubble->addItem(QString::number(i));
        ui->Puff->addItem(QString::number(i));
        ui->SDumpling->addItem(QString::number(i));
        ui->Cheese->addItem(QString::number(i));
        ui->Tiramisu->addItem(QString::number(i));
        ui->Haagen->addItem(QString::number(i));
    }
}

void MainWindow::SwitchPage(){
    QPushButton *button = qobject_cast<QPushButton*>(sender()); //get the pointer of the button checked
    //switch to the page according to the stackedWidget's current index
    if(button == ui->Meal)
        ui->stackedWidget->setCurrentIndex(0);
    else if (button == ui->Drink)
        ui->stackedWidget->setCurrentIndex(1);
    else if (button == ui->Dessert)
        ui->stackedWidget->setCurrentIndex(2);
}

//use currentIndexChanged function to adjust the number of such prodcut storing in the array of Number(num[])
//and use the difference of the number to modify the value of price
//check the status of the radioButton to calculate the final value that the user have to pay
void MainWindow::on_Omurice_currentIndexChanged(int index)
{
    price += (index - num[0])*90;
    num[0]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Pasta_currentIndexChanged(int index)
{
    price += (index - num[1])*110;
    num[1]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Risotto_currentIndexChanged(int index)
{
    price += (index - num[2])*110;
    num[2]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Noodle_currentIndexChanged(int index)
{
    price += (index - num[3])*130;
    num[3]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_BlackTea_currentIndexChanged(int index)
{
    price += (index - num[4])*15;
    num[4]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_GreenTea_currentIndexChanged(int index)
{
    price += (index - num[5])*15;
    num[5]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Cola_currentIndexChanged(int index)
{
    price += (index - num[6])*20;
    num[6]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Sprite_currentIndexChanged(int index)
{
    price += (index - num[7])*20;
    num[7]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10)pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Bubble_currentIndexChanged(int index)
{
    price += (index - num[8])*50;
    num[8]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Puff_currentIndexChanged(int index)
{
    price += (index - num[9])*35;
    num[9]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_SDumpling_currentIndexChanged(int index)
{
    price += (index - num[10])*35;
    num[10]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Cheese_currentIndexChanged(int index)
{
    price += (index - num[11])*45;
    num[11]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10)pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Tiramisu_currentIndexChanged(int index)
{
    price += (index - num[12])*45;
    num[12]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Haagen_currentIndexChanged(int index)
{
    price += (index - num[13])*55;
    num[13]=index;

    if(ui->Cash->isChecked() && price > 10) pay_money = price -10;
    else if(ui->Card->isChecked()) pay_money = price *0.9;
    else if(ui->Cash->isChecked() && price <= 10) pay_money = 0;
    else{ ui->PriceStatus->setText("Payment method"); return;}
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

//modify the pay money immediately as the payment being changed
//toggled function trigger as the value of the radioButton being changed
void MainWindow::on_Cash_toggled(bool checked)
{
    if(checked && price > 10) pay_money = price -10;
    else if(price <= 10) pay_money = 0;
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

void MainWindow::on_Card_toggled(bool checked)
{
    if(checked) pay_money = price *0.9;
    ui->PriceStatus->setText("$ " + QString::number(pay_money));
}

//set the index and value status to the initial conditions
void MainWindow::on_Cancel_clicked()
{
    if(ui->Cash->isChecked()){
        ui->Cash->setAutoExclusive(false);
        ui->Cash->setChecked(false);
    }else {
        ui->Card->setAutoExclusive(false);
        ui->Card->setChecked(false);
    }
    ui->Cash->setAutoExclusive(true);
    ui->Card->setAutoExclusive(true);
    ui->Omurice->setCurrentIndex(0);
    ui->Pasta->setCurrentIndex(0);
    ui->Risotto->setCurrentIndex(0);
    ui->Noodle->setCurrentIndex(0);
    ui->BlackTea->setCurrentIndex(0);
    ui->GreenTea->setCurrentIndex(0);
    ui->Cola->setCurrentIndex(0);
    ui->Sprite->setCurrentIndex(0);
    ui->Bubble->setCurrentIndex(0);
    ui->Puff->setCurrentIndex(0);
    ui->SDumpling->setCurrentIndex(0);
    ui->Cheese->setCurrentIndex(0);
    ui->Tiramisu->setCurrentIndex(0);
    ui->Haagen->setCurrentIndex(0);
}

//File I/O function
void MainWindow::on_Ensure_clicked()
{
    QFile fileWrite(filePath_txt);
    QFile FileWrite(filePath_csv);

    //*.txt file output
    if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QTextStream output(&fileWrite);
        output<<"You have order: ";
        for(int i=0 ;i<14 ;i++){
            if(num[i] !=0 ) output<<(QString::number(num[i]) + " " + product[i]);
        }output<<Qt::endl<<"Total money : $" + QString::number(price)<< Qt::endl;
        if(ui->Cash->isChecked()) output<<"Pay the money with cash, you have pay $"<<QString::number(pay_money)<<Qt::endl<<""<<Qt::endl;
        else if(ui->Card->isChecked()) output<<"Pay the money with card, you have pay $"<<QString::number(pay_money)<<Qt::endl<<""<<Qt::endl;
        else {QMessageBox::warning(this,"waring","Choose a payment method"); return;}
        fileWrite.close();
    }

    //*.csv file output
    if(FileWrite.open(QIODevice::WriteOnly | QIODevice::Append)){
        for(int i=0 ; i<14 ; i++){
            if(num[i] != 0) FileWrite.write((product[i] + QString::number(num[i]) + "\n").toStdString().c_str());
        }
        FileWrite.write(("Total, $" + QString::number(price) +"\n").toStdString().c_str());
        if(ui->Cash->isChecked()) FileWrite.write(("CashPay, $" + QString::number(pay_money) + "\n\n").toStdString().c_str());
        else if(ui->Card->isChecked()) FileWrite.write(("CardPay, $" + QString::number(pay_money) + "\n\n").toStdString().c_str());
        else {QMessageBox::warning(this,"waring","Choose a payment method"); return;}
        FileWrite.close();
    }
    QMessageBox::about(this,"CheckOut","Check Out Done");
    MainWindow::on_Cancel_clicked();
}


void MainWindow::on_Detail_clicked()
{
    dlg->show(); //subwindow showing
    QString item = "You have order : \n";
    for(int i=0; i<14 ;i++){
        if(num[i] != 0 )item.push_back(QString::number(num[i]) + " " + product[i] + "\n"); //create the needed QString
    }
    emit sendData(item); //use the signal-slot to convert the data(QString) to the subwindow's function(getData)
}
