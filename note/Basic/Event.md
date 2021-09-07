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

## Events Propagation

## Events and Event classes

## [Reference](https://www.learnqt.guide/events/working-with-events/)
