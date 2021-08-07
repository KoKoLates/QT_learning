# QSS

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
```cpp
QWidget *myWidget = new QWidget(this);
myWidget->setGeometry(0,0,this->width(),this->height());
myWidget->setStyleSheet("background-color:black");
myWidget->show();
```
If wanted to subclass a QWidget, in order to be able to use the Style Sheet, you need to provide the paintEvent event. That is because the `paintEvent()` function of QWidget is empty, and the style sheet needed to be drawn into the window through paint.
```cpp
#include <QPainter>
#include <QStyleOption>
```
```cpp
void CustomWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    CustomWidget::paintEvent(event);
}
```
