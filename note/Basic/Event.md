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
};
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
In normal cases, Qt will try to propagate the event up the parent child relationship chain until it finds a handler willing to deal with the event. If that handler is not found, then the event is discarded or fully ignored. <br/><br/>

Depending on what you are trying to achieve, you may or may not be interested in what the parent implementation has to offer. If you want to completely bypass what the parent implementation is doing, just do your thing in your overridden event handler and don’t call the parent implementation. By the way, you call the parent implementation by doing something like this : 
```cpp
QWidget::keyPressEvent(event);
```
This is what is meant by event propagation. Events can be , and in most cases are , propagated from parent to child until an object is found, that is interested in the event. Child classes propagate to parents by calling the same event method in their parent classes.

## Events and Event classes
Events are all subclasses of the QEvent class and each child class adds new fields and methods to help fulfill the purpose it was made for. Below is a widget subclass with a few more events for you to play with.<br/>
* [Instance](https://github.com/KoKoLates/Qt-learning/blob/main/note/Basic/Event%20Class.cpp)
* [Event classes](https://doc.qt.io/qt-5/events.html)

Quoting the documentation,there are five different ways that events can be processed; subclassing your class of interest and overriding event, reimplementing this virtual function is just one of them : 
1. Reimplementing the event you interest, this is the most common, easiest, and least powerful way.
2. Reimplementing `QCoreApplication::notify`. This is very powerful, providing complete control; but only one subclass can be active at a time.
3. Installing an event filter on `QCoreApplication::instance()`. Such an event filter is able to process all events for all widgets, so it’s just as powerful as reimplementing `notify()`; furthermore, it’s possible to have more than one application-global event filter. Global event filters even see mouse events for disabled widgets. Note that application event filters are only called for objects that live in the main thread.
4. Reimplementing `QObject::event()`.
5. Installing an event filter on the object. Such an event filter gets all the events.


## Reimplementing QObject : : event ( )
Ones could use that method by subclassing your class of interest but instead of implementing specific event handlers, just impliement the `QObject::event()` override. This allows all events to pass through your override and you can decide which ones to handle and which ones to channel up the event propagation chain.
```cpp
class Button : public QPushButton
{
    Q_OBJECT
    
public:
    explicit MyButton(QWidget *parent = nullptr);
    
protected:
    bool event(QEvent * event) override;
};
```
The implemention cpp file : 
```cpp
bool Button::event(QEvent *event)
{
    if( (event->type() == QEvent::MouseButtonPress) || (event->type() == QEvent::MouseButtonDblClick))
    {
        qDebug() << "MyButton::Event : Pressed the MyButton instance. Consuming event";
        return true;
    }
    //Remember to call the event method of the base class for the events that you don't handle
    return QPushButton::event(event);
}
```
The return data of that `event()` method is bool. The logic here is very similar to what we’ve seen with the `accept()` and `ignore()` methods. When you return true, you are telling the Qt system that the event has been handled and a returned false means that the event has been ignored. <br/><br/>

Because all events are passing through this method, you have to check which specific event you received. You do that by relying on the `Event::Type` enum. Note that you have to call the parent implementation of `event()` for all events that you don’t handle. Otherwise you’re going to end up with an unresponsive widget for other events. This method is good if for some reason you want to channel all your events through one place.
```cpp
Button *button = new Button(this);
connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
```
Create an instance of the button in your widget class and connect a slot to it. Run the application and you’re going to see that as you click or double click on the button, the slot is not going to be called. Instead, the message from `MyButton::event()` is going to show up, because the signal : `clicked()` isn't being fired. The signal is fired somewhere in the event handles of QPushButton, and we have bypassed any event handling for QPushButton whatsoever when we detect that the user is just clicking or double clicking on our button. This also shows that the `event()` method is called before any specific event handler like mousePress or keyPress is called.

## Event Filters on QObject
Event filters are subclasses of the QObject class that you can attach to a given object to intercept events before they reach the target object. Ones could install the filter by calling `QObject::installEventFilter()` on the object. An event filter gets to process events before the target object does, allowing it to inspect and discard the events as required. An existing event filter can be removed using the `QObject::removeEventFilter()` function, and intercept events in the `eventFilter()` method that you have to override.
```cpp
class DigitFilter : public QObject
{
    Q_OBJECT
    
public:
    explicit DigitFilter(QObject *parent = nullptr, QString msg = "");
    
protected:
    bool eventFilter(QObject *dest, QEvent *event);
    
private:
    QString message;
};
```
The implementation :
```cpp
DigitFilter::DigitFilter(QObject *parent, QString msg) : QObject(parent)
{
    message = msg;
}

bool DigitFilter::eventFilter(QObject *dest, QEvent *event)
{
    if(event->type() == QEvent::keyPress)
    {
        qDebug() << "Event filter for " << message << " triggered";
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        static QString digits = QString("1234567890");
        if(digits.indexOf(keyEvent->text()) != -1)
            //Returning true here signals that the event has been handled and it's not sent to the destination.
            return true;
    }
    //This sends the event to be handled by the filter of the base class or the event handlers of the base class themselves
    return QObject::eventFilter(dest, event);
}
```
The event filter is also going to get all events for the object it is installed on. Once inside the `eventFilter()` method, we have to check for the event we are interested in. After that, we have to check which key was pressed, to know whether it is a digit or not. If it is we return true to signal that we don’t want this event handled any further, in other words, the event filter has done all that needs be done for this event on the target object, nobody else up the chain of event propagation should worry about it. This causes for digits not to be shown or processed when you type them on the line edit where we’re going to install the filter. <br/><br/>

Assuming you have a bare bones widget project created and opened, add the DigitFilter class to the project, and drag a line edit component to the widget form. In the wiget constructor, create a filter and install it on the line edit :
```cpp
DigitFilter *filter = new DigitFilter(this, "line edit");
ui->lineEdit->installEventFilter(filter);
ui->lineEdit->setText("line edit");
```
This will cause for all events for the line edit to go through the `eventFilter()` method of the filter object. The filter will filter out digits and you won’t see then in the user interface when you run the application. Event filters are great when you don’t want to mess with the target object and just want to influence it’s behavior though events.

## Installing Event Filter on QApplication
Besides installing filters on regular QObjects, you can also install them on the single QApplication instance in your application. Obviously , event filters on QApplication are called before any event filter installed on any other object in the application.
```cpp
class Filter : public QObject
{
    Q_OBJECT
    
public:
    explicit Filter(QObject *parent = nullptr, QString msg = "");
    
protected:
    bool eventFilter(QObject *dest, QEvent *event);
    
private:
    QString message;
};
```
It's just a regular filter as we seen before, and its implement is :
```cpp
Filter::Filter(QObject *parent, QString msg) :
    QObject(parent), message(msg)
{
}

bool Filter::eventFilter(QObject *dest, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
    {
        qDebug() << "Event hijacked " << message;
        return true;
        //Event handle here and no more need to propagate
    }
    return QObject::eventFilter(dest, event);
}
```
It’s clear that we’re filtering for mouse clicks and double clicks. Now you can full scale in craziness, and install this filter on the QApplication instance in your main function.
```cpp
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Widget w;
    
    Filter *filter = new Filter(&w, "Main");
    a.installEventFilter(filter);
    
    w.show();
    
    return a.exec();
}
```
If you create buttons in your form and attach slots to respond when they are clicked, after running the application, you’re going to see that when you click on the buttons, the slots are not going to respond, instead you’re going to see the filter respond in the debug output message.


## [Reference](https://www.learnqt.guide/events/working-with-events/)
