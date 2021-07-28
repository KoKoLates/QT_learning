# QT_learning
some project about learning qt

## project1
Ordering System with PushButton, CheckBox, RadioBox <br>
<br>
TO that the QT display in high DPI without ui ditortion, add this code in the main.cpp
```
QApplication::setAttribution(QT::AA_EnableHighDpiScaling);
```
Modifying the defalt of radiobutoon, to set the status or checked of it <br>
Remenber to set it back to (true) to get the property if radiobutton
```
this->ui->radiobutton->setAutoExclusive(bool);
```
[lesson1](https://www.notion.so/Qt-Lesson-1-HelloWorld-06030c9831854e3489f8d89e70b03615)
## project2
Simple Text I/O with File I/O access <br>
[lesson2](https://www.notion.so/Qt-Lesson-2-File-I-O-f3b006a408b84082add6f63f37366dd3)
## project3
Ordering System with StackedWidget, mutilpie window, File I/O access<br>
## note
