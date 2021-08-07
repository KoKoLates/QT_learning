# Advanced Ui

## QWidget Background
### QPalette
```cpp
QWidget *myWidget = new QWidget(this);
myWidget->setGeometry(0,0,this->width(),this->height());
QPalette pal(myWidget->palette());

//set the background color be black
pal.setColor(QPalette::Background,qRgb(0,0,0)); // equal to Qt::black
myWidget->setAutoFillBackground(true);
myWidget->setPalette(pal);
myWidget->show();
```
### Style Sheet
