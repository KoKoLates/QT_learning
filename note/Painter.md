# Paint System
The Paint System of Qt is consist of `QPainter, QPaintEngine and QPaintDevice`. QPainter is used to perform drawing operations; QPaintDevice is an abstraction of a two-dimensional space, this two-dimensional space allows QPainter to draw on it, which is the space where QPainter works; QPaintEngine provides a brush (QPainter) to draw on different devices Unified interface. The QPaintEngine class is used between QPainter and QPaintDevice and is usually transparent to developers. Unless you need to customize a device, you don't need to care about the QPaintEngine class. We can understand QPainter as a paintbrush; understand QPaintDevice as a place where paintbrushes are used, such as paper, screen, etc. For paper and screen, we must use different paintbrushes to draw. In order to use one paintbrush uniformly, we designed QPaintEngine Class, this class allows different papers and screens to use one type of brush.


## QPainter
```cpp
QPainter painter(qPaintDevice);
```
`qPaintDevice` is indicated to the subclass of QPaintDevice, such as QWidget, QImage, QPicture and QPrinter. And if it's graphic components, the `paintEvent()` of the QWidget is usually redefined. When the Paint Device needs to be repainted, such as when the component appear, overwritten and reappear. You could use `repaint()` or `update()` function to trigger the `paintEvent()` to handle that event.<br>
<br>
The members of the QPainter class: `QBrush`, `QPen`, `QFont`, `QImage`, `QPicture`, `QPixmap` and `QBitmap`.
### QBrush
QBrush defines the filling mode of QPainter, which has some properties such as style, color, gradient, and texture.
#### Style
`style()` defines the filling style, using the `Qt::BrushStyle` for enumeration, the default value is `Qt::NoBrush`, that is, no filling is performed.<br><br>
![image](https://raw.githubusercontent.com/KoKoLates/QT_learning/main/note/images/QBrushStyle.png)
#### Color
`color()` defines the color of the fill mode. This color can be a Qt predefined color constant, which is [`Qt::GlobalColor`](https://doc.qt.io/qt-5/qt.html#GlobalColor-enum), or it can be any QColor object.
```cpp
#include <QColorDialog>
QColor color = QColorDialog::getColor(Qt::black,this,tr("Color Selector"),QColorDialog::ShowAlphaChannel);
// Set the deflaut color to the black
```
Ones could use the Qt standard dialog box to get select the color and stores it in the QColor object.
#### Gradient
`gradient()` defines a gradient fill. This property is only valid when the style is one of `Qt::LinearGradientPattern`, `Qt::RadialGradientPattern` or `Qt::ConicalGradientPattern`. Gradients can be represented by QGradient objects. Qt provides three gradients: QLinearGradient, QConicalGradient and QRadialGradient, they are all subclasses of QGradient. Gradient colors need to be specified using two attributes: stop-point and color. 
```cpp
void QGradient::setColorAt( qreal postion, const QColor &color)
```
You can use the `QGradient::setColorAt()` function to set a single stop-point and color. The stop-point is represented by a value between 0 and 1, and 0 means Start-point, 1 means End-point. And ones could also indicate the color in the assigned position.<br>
##### QLinearGradient 
```cpp
QPainter painter(this);
QLinearGradient linearGradient(0, 0, 100, 100); // gradient from (0,0) to (100,100)
linearGradient.setColorAt(0, Qt::white);
linearGradient.setColorAt(0.5, Qt::green);
linearGradient.setColorAt(0, Qt::black);
painter.setBrush(QBrush(linearGradient));
painter.drawRect(10, 10, 50, 50); //draw a reactangle from (10,10) to (50,50) with linearGradient
```
Then could create a rectangle from (10,10) to (50,50) that with linearGradient that white color in start-point, green in mid-point and black in the end. From the code above, we could know that the four parameter of the `QLinearGradient` is the 2D position of start point and end point. Ones could rewrite the code like :
```cpp
QLinearGradient linearGradient(QPoint(0,0), QPoint(100,100));
// or using QPointF to store the coordinate postion in float data and display the gradient more accurately
```

### QPen
Used to draw the edges of geometric figures, composed of parameters such as color, width, line style. QPen contains different properties such as brush, width, style, capStyle and joinStyle.
#### Brush
`brush()` 
