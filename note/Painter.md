# Paint System
The Paint System of Qt is consist of `QPainter, QPaintEngine and QPaintDevice`. QPainter provides a low-level drawing API. It uses QPaintEngine internally as an interface to draw on QPaintDevice. As long as it is a subclass of QPaintDevice, you can create QPainter to draw graphics on it, such as QWidget, QImage, QPicture and QPrinter, all are the subclass of QPaintDevice.
## QPainter
```cpp
QPainter painter(qPaintDevice);
```
`qPaintDevice` is indicated to the subclass of QPaintDevice (like : QWidget, QImage, QPicture and QPrinter) . And if it's graphic components, the `paintEvent()` of the QWidget is usually redefined. When the Paint Device needs to be repainted, such as when the component appear, overwritten and reappear. You could use `repaint()` or `update()` function to trigger the `paintEvent()` to handle that event.
