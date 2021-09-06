# Signal and Slot
Signals and slots are used for communication between two objects. The signal and slot mechanism is the core feature of Qt, and it is also the most prominent feature of Qt different from other development frameworks. In GUI programming, when a component is changed, it is always hoped that other components can also understand the change. More generally, we want any object to be able to communicate with other objects. For example, if the user clicks the close button, we hope that the `close()` function of the window can be executed to close the window. In order to achieve communication between objects, some toolkits use a callback mechanism, while in Qt, signals and slots are used for communication between objects. A signal can be emitted when a special event occurs, such as a button being clicked; and a slot is a function, which is called after the signal is emitted to respond to the signal. Some signals and slots have been defined in Qt's component class, but more methods are to subclass this component, and then you can design some Slots to accept specific Signals and define corresponding actions. Signals and Slots can be connected through the static method connect of QObject. The processing between Signals and Slots is synchronized.
![image](https://raw.githubusercontent.com/KoKoLates/Qt-learning/main/note/images/SignalAndSlot.PNG)

## Signal
Self-declare the signal in one's class's header file :
```cpp
signal :
    void SendSignal(); // the parameter could be empty or other data type
```
To declare a signal, use the signals keyword, and you cannot use public, private, and protected qualifiers before signals, because only the class that defines the signal and its subclasses can emit the signal. Moreover, the signal only needs to be declared, and it is not required to define the implement of the function. Also note that the signal has no return value and can only be of type void. Because only classes derived from the QObject class and its subclasses can use the signal and slot mechanism, so that note that add the `Q_OBJECT` in the beginning of the class.
```cpp
void MainWindow::buttonClicked(){
    emit SendSignal();
}
```
Define a function that as it was called, then using `emit` to send the signal to corresponding slots.



## Slot
In the class's declaration's header file, ones could seld-define the needed slots :
```cpp
public slots:
    void RequireSignal();
```
Declaring a slot requires the use of the slots keyword. A slot can be of private, public, or protected type, and the slot can also be declared as a virtual function, which is the same as a normal member function, and it can also be called like a normal function. The biggest feature of slots is that they can be associated with signals.
