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
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenText"),"",tr("Text(*.txt *.csv)"));
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenImage"),"",tr("Image(*.png *.jpg *.jepg)"));
QString filePath = "Path"; // directly indicate the file path
```
## Text file
### File Read
Read the file indicated by filePath.<br>
The defalt of unicode is UTF-8, as any file using other form will get corrupt
```cpp
QFile fileRead(filePath); 
if(fileRead.open(QIODevice::ReadOnly)){
  QTextStream input(&fileRead);  
  input.setCodec("UTF-8");
  while(!input.atEnd()){
    QString line = input.readline();
    ui->textBrowser->append(line.toStdString().c_str());
  }
  fileRead.close();
}
```
### File Write
Write the text file
```cpp
QString UserInput = ui->lineEdit->text(); 
//or use other ways to get the output QString

QFile fileWrite(filePath);
if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text )){
  QTextStream output(&fileWrite);
  output<<UserInput<<Qt::endl;
  fileWrite.close();
}
```
### Member type document
QIODevice :: OpenMode [QIODevice Class](https://doc.qt.io/qt-5/qiodevice.html#QIODevice)
```cpp
QIODevice::ReadOnly // open for reading
QIODevice::WriteOnly // open for writing, this mode implies Truncate unless combined with Append
QIODevice::ReadWrite // open for reading and writing
QIODevice::Append // open in append mode so that the data is written to the end of the file
QIODevice::Text //When reading, the end-of-line terminators are translated to '\n'. 
                //When writing, the end-of-line terminators are translated to the local encoding,
```
## Image file
### Read and show in the label
```cpp
QPixmap icon("imagePath");
ui->label->setPixmap(icon.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio));
```
### Open and Save the image
Open the image by using the paintEvent.
```cpp
QString filePath = QFileDialog::getOpenFileName(this,tr("OpenImage"),"",tr("Image(*.png *.jpg)"));
sourceImage.load(filePath); // load in the image that filePath directed
image = sourceImage.copy().scaled(this->width(), this->height(), Qt::KeepAspectRatio); // copy the sourceImage and resize to image
sourceImage = image;
update(); // trigger the paintEvent function
```
`paintEvent()` with double-buffers that could be use in geograhic shapes painting
```cpp
void PaintWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(scribbling == true ) painter.drawImage(0,0,tempImage); //scribbling(bool) indicate that drawing or not(mouse left button is clicked or not)
    else painter.drawImage(0,0,image);
}
```
Save the image to the indicated filePath that selected with the `QFileDialog`
```cpp
QString filePath = QFileDialog::getSaveFileName(this,tr("SaveImage"),"",tr("Image(*.png *.jpg)"));
image.save(filePath);
```
## .CSV file
A Common-Separated values(CSV) file is a delimited text file that use a comma to separate values.Each line of the file is a data record.Each record consists of one or more fields, separated by commas.
### File Read
```cpp
QFile fileRead(filePath);
QStringList lines;
if(fileRead.open(QIODevice::ReadOnly)){
    QTextStream input(&fileRead);
    while(!input.atEnd()){
        lines.push_back(fileRead.readLine());
    }
    for(int j=0; j<lines.size(); j++){
        QString line = lines.at(j);
        QStringList split = line.split(",");
        for(int col=0; col<split.size(); col++){
            ui->textBrowser->append(split.at(col));
        }
    }
    fileRead.close();
}
```
### File Write
Using QStringList as the UserInput
```cpp
QFile fileWrite(filePath);
QStringList lines;
lines<<"string1, "<<"string2,";  // each string has to end at commas
if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append)){
    for(int i=0; i<lines.size(); i++){
        fileWrite.write(lines[i].toStdString().c_str());
    }
    fileWrite.close();
 }
 ``` 
 Using QString as the UserInput
 ```cpp
//using commas to separate in the string
 QFile fileWrite(filePath);
if(fileWrite.open(QIODevice::WriteOnly | QIODevice::Append)){
    fileWrite,write(QString);
FileWrite.close();
}
```
