# QMatrix
The default coordinate system of QPainter is the coordinate system of the drawing device, that is, the upper left corner is the origin, the right is a positive X, and the downward is a positive Y coordinate system. The conversion of the coordinate system often uses a matrix to express and perform operations. , The function of `QMatrix` is to allow you to use its built-in matrix to set relevant parameters, and then let `QPainter` perform some conversion actions of the two-dimensional coordinate system according to the settings of `QMatrix`.
```
x' = m11*x + m21*y + dx
y' = m22*y + m12*x + dy
```
_dx_ and _dy_ define horizontal and vertical movement, _m11_ and _m22_ define horizontal and vertical scaling , _m12_ and _m21_ define vertical and horizontal distortion (shearing). You can use the `setMatrix()` function of `QMatrix` to set _m11_, _m12_, _m21_, _m22_, _dx_, _dy_, or directly use the `QPainter::scale()` function to scale the coordinate system; use the `QPainter::rotate()` function to rotate the coordinate system clockwise; use the `QPainter::translate()` function to translate the coordinate system; you can also use `QPainter::shear()` to surround the origin To distort the coordinate system.

## Translate
```cpp
void Dialog::paintEvent(QPaintEvent *){
  QPainter painter(this);
  painter.setBrush(Qt::yellow);
  painter,drawRect(0, 0, 50, 50); 
  painter.translate(100, 100); //set the (100,100) be the origin 
  
  painter.setBrush(Qt::red);
  painter,drawRect(0, 0, 50, 50);
  painter.translate(-100, -100); // set back to the default coordinate
}
```
Here we first draw a square with a width and height of 50 at the origin (0, 0), and then use the `translate()` function to translate the coordinate system so that the (100, 100) point becomes the new origin, so we do it again When drawing, although the logical coordinates in `drawRect()` are still (0, 0), the actual display is the red square at (100, 100). You can use the `translate()` function again to translate in the opposite direction to make the origin return to the upper left corner of the window.

## Scale
```cpp
void Dialog::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setBrush(Qt::yellow);
  painter.drawRect(0, 0, 100, 100);
  painter.scale(2, 2); // enlarge 2 times
  painter.setBrush(Qt::red);
  painter.drawRect(50, 50, 50, 50);
}
```
When we use the `scale()` function to enlarge the horizontal and vertical coordinates of the coordinate system by two times, the logical (50, 50) point becomes the (100, 100) point on the window, and the logical length is 50, The length drawn to the window is 100.

## Shear
```cpp
void Dialog::paintEvent(QPaintEvent *)
{
  QPainter painter(this);    
  painter.setBrush(Qt::yellow);   
  painter.drawRect(0, 0, 50, 50);    
  painter.shear(0, 1); //vertical distortion   
  painter.setBrush(Qt::red);    
  painter.drawRect(50, 0, 50, 50);
}
```
`Shear()` has two parameters, the first is to twist the horizontal direction, the second is to twist the vertical direction, and the value is the degree of distortion. For example, the value of longitudinal distortion in the program is 1, then the left side of the red square is moved down by one unit, and the right side is moved down by two units. A value of 1 indicates that the right side is moved down by one more unit than the left side.

