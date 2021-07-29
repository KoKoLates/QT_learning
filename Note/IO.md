# file I/O
## main include
```cpp
#include <QfileDialog>
#include <QFile>
#include <QTextStream> //for text file
#include <QImage> //for image file
```
## filePath
Get the path of existed file by storing it as a QString data. And ones can then operate I/O of such file
```cpp
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenText"),"",tr("Text(*.txt)"));
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenImage"),"",tr("Image(*.png *.jpg *.jepg)"));
```
```
read and display .png image:

QPixmap icon("imagePath");
ui->label->setPixmap(icon.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
//define the function
void MainWindow::switchPage(){
  QPushButton *button = qobject_cast<QPushButton*>(sender()); //obtain the pointer of the button USER clicked
  if(button == ui->Button_1)
    ui->stackedWidget->setCurrentIndex(0);
  else if(button == ui->Button_2)
    ui->stackedWidget->setCurrentIndex(1);
  else if(button == ui->Button_3)
    ui->stackedWidget->setCurrentIndex(2);
}

reading text file:
QFile fileRead(filePath);  //#include <QFile> 
if(fileRead.open(QIODevice::ReadOnly)){
  QTextStream input(&fileRead);  //#include <QTextStream>
  input.setCodec("UTF-8");
  while(!input.atEnd()){
    QString line = input.readline();
    ui->textBrowser->append(line.toStdString().c_str());
  }
  fileRead.close();
}
```
writing text file:
QString UserInput = ui->lineEdit->text();
QFile fileWrite(filePath);
if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text )){
  QTextStream output(&fileWrite);
  output<<UserInput<<Qt::endl;
  fileWrite.close();
}
