# Double Buffering
Without double buffering painting method, when using the mouse to drag out a geometric shapes and then found a lot of shadows. Try dragging the mouse quickly and slowly to draw the geometric shapes respectively. As a result, you will find that the faster the dragging speed, the less shadowing. In fact, in the process of dragging the mouse, the screen has been refreshed many times. It can also be understood that the `paintEvent()` function has been executed many times, and the geometric shapes will be drawn every time as it's executed.

### Add private member in PaintWidget class
Add an template widget. if you are drawing, that is, as the mouse button has not been released, then drawing on the template widget. Only when the mouse button is released, so that could paint on the real `image` widget.<br>
<br>
Adding the private members in the `paintwidget.h` header file:
```cpp
QImage tempImage;
bool scribbling;
```

### Initialize the constructor of `paintwidget.cpp`
```cpp
scribbling = false;
```
