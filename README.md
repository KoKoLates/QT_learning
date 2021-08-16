# QT_learning
some projects about learning Qt

## project1 
Basic ordering system. Using several `CheckBoxs` and `RadioBox` to assure user needs. And according to different conditions, to calculate the payment money and display with products seleced in the widget. Mainyly learning about Qt creater and how to use the slot of object in Qt designer.
[(lesson1)](https://www.notion.so/Qt-Lesson-1-HelloWorld-06030c9831854e3489f8d89e70b03615)

## project2
Simple text file editor. That could use dialog box to seleced a file with file path, then open and edit with line editor. After editring, the file could be saved according to original file path that user selected.
[(lesson2)](https://www.notion.so/Qt-Lesson-2-File-I-O-f3b006a408b84082add6f63f37366dd3)

## project3
Advanced ordering system that uasing stacked widget to separate different types of products, and use the comboBox to increase the checkable number of each products. Then calculate the money and dislay with products selected in another independent window. Besides, after payment, the detail of money and products will save as text file and csv file spontaneously.

## project4
Rewrite the QMouseEvent's `mouseMoveEvent()`, `mousePressEvent()` and `mouseReleaseEvent()` to display the action and postion as 2 dimension coordinate in the window's background.
[(lesson3)](https://www.notion.so/Qt-Lesson-3-QIMAGE-Mouse-Event-674e197ba85f43499c5063619c00efe1)

## project5
Simple drawing board with `QEvent`, `QImage`, `QPoint` and `QPainter`
### Painter 01
A simple painter that rewrite the QMouseEvent and QPaintEvent to achieve using mouse clicked, move and release to draw the trace on the widget of window.
### painter 02
#### Double buffers
Switch the pen to Line, Triangle, Rectangle, Ellipse, Circle function by using the double buffers without Eraser. While using double, the Eraser function will not be able to operate.It has to manipulate like the pen tool.
 
### painter 03
#### QMatrix
Try to use the `QMatirx` adjust the coordinate of windows and draw a color wheel on the indicate position.

## project6
Simple painter that contain Pen, Line, Triangle, Rectangle, Ellipse and Eraser function. And using the `QFileDialog` and `QColorDialog` to possess the file open and save fuction, and the bulld-in color selector to chahge the color of the pen. Besides, using the basic QSS technique to advance the UI widget.
