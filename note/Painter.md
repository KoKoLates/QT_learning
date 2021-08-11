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
`color()` defines the color of the fill mode. This color can be a Qt predefined color constant, which is `Qt::GlobalColor`, or it can be any QColor object.
#### Gradient
`gradient()` defines a gradient fill. This property is only valid when the style is one of `Qt::LinearGradientPattern`, `Qt::RadialGradientPattern` or `Qt::ConicalGradientPattern`. Gradients can be represented by QGradient objects. Qt provides three gradients: QLinearGradient, QConicalGradient and QRadialGradient, they are all subclasses of QGradient.
### QPen
Used to draw the edges of geometric figures, composed of parameters such as color, width, line style. QPen contains different properties such as brush, width, style, capStyle and joinStyle.
#### Brush
`brush()` 
