# QT_learning
some project about learning qt

## project1
Ordering System with PushButton, CheckBox, RadioBox <br>
[lesson1](https://www.notion.so/Qt-Lesson-1-HelloWorld-06030c9831854e3489f8d89e70b03615)
## project2
Simple Text I/O with File I/O access <br>
<br>
get the path of a file :
```
#include <QFileDialog>
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenText"),"",tr("Text(*.txt)"));
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenImage"),"",tr("Image(*.png *.jpg *.jepg)"));
```
<br>
reading text file:
```
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
<br>
writing text file
```
QString UserInput = ui->lineEdit->text();
QFile fileWrite(filePath);
if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text )){
  QTextStream output(&fileWrite);
  output<<UserInput<<Qt::endl;
  fileWrite.close();
}
```
<br>
read and display *.png image:
```
QPixmap icon("imagePath");
ui->label->setPixmap(icon.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
```
[lesson2](https://www.notion.so/Qt-Lesson-2-File-I-O-f3b006a408b84082add6f63f37366dd3)
## project3
Ordering System with StackedWidget, mutilpie window, File I/O access<br>
## note
