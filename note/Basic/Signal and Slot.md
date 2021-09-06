# Signal and Slot
Signals and slots are used for communication between two objects. The signal and slot mechanism is the core features of Qt, and it's also the most prominent feature of Qt that different from others development frameworks. <br/><br/>

In the GUI programming, when a component (condition) is changed, it's always hoped that other components can also understand the change. More generally, we want any object could be able to communicate with other objects. For example, if the user clicks the close button, we hope that the `close()` function of the window can be executed to close the window. In order to achieve communication between objects, some toolkits use a callback mechanism. while in Qt, signals and slots are used for communication between objects. <br/><br/>

A signal can be emitted when a special event occurs, such as a button being clicked, pressed or checked; and a slot is a function, which is called after the signal emitted to respond to the signal. Some signals and slots have been defined in Qt's component class, but more methods are to subclass this component, and then you can design some Slots to accept specific Signals and define corresponding functional actions. Signals and Slots can be connected through the static method connect of QObject. In addition, the processing between Signals and Slots is synchronized. <br/><br/>
![image](https://raw.githubusercontent.com/KoKoLates/Qt-learning/main/note/images/SignalAndSlot.PNG)

## Signal
In the header file, add that code to declare a signals :
```cpp
signals :
    void SendSignal(); // the parameter could be empty or other data type
```
To declare a signal, using the `signals` keyword is needed, and you cannot use public, private, and protected qualifiers before signals, because only the class that defines the signal and its subclasses can emit the signal. Moreover, the signal only needs to be declared, and it is not required to define the implement of the function. Also note that the signal has no return value and can only be of type void. Because only classes derived from the QObject class and its subclasses can use the signal and slot mechanism, so note that it's neccessary to add the `Q_OBJECT` micro in the most beginning of such class.
```cpp
void MainWindow::buttonClicked(){
    emit SendSignal();
}
```
Define a function that if it was called, then using `emit` to send the signal to corresponding slots.


## Slot
In the header file, add the code to declare s slots :
```cpp
public slots:
    void RequireSignal();
```
Declaring a slot requires the use of the `slots` keyword. A slot could be of private, public, or protected type, and the slot can also be declared as a virtual function, which is the same as a normal member function, and it can also be called like a normal function. The biggest feature of slots is that they can be associated with signals.


## Connect
