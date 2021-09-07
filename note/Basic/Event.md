# Qt Event
Events are objects in your Qt C++ application, and they are indeed represented by the QEvent class. They are a low level mechanism allowing you to control the look and the behavior of your classes and objects and they are very useful for building event related features inside your objects, that you do not want to depend on other objects in the application. <br/><br/>

Events can either be generated from within the application or as a result of some external activity. When an event occurs, Qt constructs an appropriate instance of a QEvent subclass . Qt delivers the event by calling the `event()` method of the target object ( mostly widgets) . The `event()` method doesn’t handle the event itself. It looks at the type of the event in question (`Event::Type`), and calls the most appropriate event handler ( mousePressEvent, mouseMoveEvent, keyPressEvent, resizeEvent) and returns true or false, based on whether the event was accepted or ignored. 

## Events and Signals/Slots
The purpose of events is somewhat the same as for signals and slots. Signals /Slots allow you to respond when something happens after all. Events are different in that they allow you to do much more low level things that deeply affect the behavior of your objects. And if you look deep, the signal and slot mechanism in Qt is itself powered by events. The `clicked()` signal of QPushButton for example, is emitted somewhere deep in the implementation of some mouse events for the QPushButton class. <br/>
* [Signal/Slot](https://github.com/KoKoLates/Qt-learning/blob/main/note/Basic/Signal%20and%20Slot.md)

## Events Using
There are different ways you can use events in you Qt applications. Here are going to start off by showing you how you can play around with events for the QWidget class. And if it wanted to capture the close event for the widget, you would add an override of the `closeEvent()` method to your widget.
```cpp
class Widget : public QWidget
{
    Q_OBJECT
public:
    eplicit Widget(QWIidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    
protected:
    void closeEvent(QCloseEvent *event);
}
```
and implement the event function in the implementation file :
```cpp
void Widget::closeEvent(QCloseEvent *event){
    event->accept();
    qDebug() << "QCloseEvent : Widget closed";
}
```
If you run this application, you’ll going to see a usual boring widget. But if you click on the X icon in the top bar to close the window, you’ll see that your widget closes and the debug message display.<br/><br/>

This is the normal flow you’re going to follow to implement your events :
* Subclass your Qt class of interest
* Override the event you are interested in <br/>
<hr/>

* **Accept / Ignore**
```cpp
event->accept();
event->ignore();
```
When you handle an event, you have the option to ACCEPT the event, or to IGNORE the event. When you accept the event, by calling the `accept()` method on your event parameter, you’re signaling to the Qt framework that you have dealt with the event and it won’t try to handle it in any other way. Besides, if you don’t explicitly specify that you accept the event, the event is going to be accepted by default.<br/><br/>

When you ignore the event by calling `ignore()` on your event parameter, you’re telling the Qt framework that you’re rejecting the event, and it will try to find other ways to handle the event if possible. 

## Events Propagation
In normal cases, Qt will try to propagate the event up the parent child relationship chain until it finds a handler willing to deal with the event. If that handler is not found, then the event is discarded or fully ignored. <br/><>br/>

Depending on what you are trying to achieve, you may or may not be interested in what the parent implementation has to offer. If you want to completely bypass what the parent implementation is doing, just do your thing in your overridden event handler and don’t call the parent implementation. By the way, you call the parent implementation by doing something like this : 
```cpp
QWidget::keyPressEvent(event);
```
This is what is meant by event propagation. Events can be , and in most cases are , propagated from parent to child until an object is found, that is interested in the event. Child classes propagate to parents by calling the same event method in their parent classes.

## Events and Event classes

## [Reference](https://www.learnqt.guide/events/working-with-events/)
