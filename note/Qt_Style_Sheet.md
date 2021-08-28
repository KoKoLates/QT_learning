# Qt Style Sheet

There is a CSS syntax parser inside Qt. We could define our style control to an external file with CSS parser. After the CSS syntax parser is parsed, the corresponding function module is called to complete the style change. Qt's style sheet allows us to easily change the appearance of the application without making any code changes to the program. The idea comes from CSS in web design, that is, functional design and aesthetic design can be separated.

## Loading Method

In the QWidget project, add a qrc source file, and then add a prefix "/ ". Then add a QSS file here, just create a text file and modify it to the file extension as `*.qss` file,  and add it to the qrc source file with highlighter updates. After adding the qss file, then could open such file with coding :
```cpp
QFile file(":/qss/myQss.qss"); // relative path of the *.qss file
file.open(QFile::ReadOnly);
QTextStream fileText(&file);
QString stylesheet = fileText.readAll();
this->setStyleSheet(stylesheet);

file.close();
```

## Basic Grammar
The style sheet is composed of a series of style rules. Each rule can be divided into two parts: selector and declaratio. The selector indicates which controls the rule is applied to; the declaration details what the rule is.
```css
Selector {declaration;} 
```
Qt's style sheet is not case sensitive in properties, but when referring to the class name, it is case sensitive. Multiple selectors can be used side by side, separated by ***commas***. And the declaration part can also have multiple parallels, separated by ***semicolons***. When the selector we want to set has multiple attributes, we need to parallel multiple declarations.
```css
Selector1, Selector2, Selector3 {declaration} /*multiple selecctor*/
Selector {declaration1; declaration2; declaration3} /*multiple declaration*/
```

## Selector
### Universal Selector
`*` Used to select all Widgets. It can be restricted to a specific namespace or all namespaces.
### Element Selector
```css
QPushButton {background-color: gray; }
```
Match all QPushButton and its derived subclass objects.
### Arrttibute Selector
```css
QPushButton[flat = " false"] {background-color: magenta; }
```
Match all QPushButton instances whose flat attribute is false. Note that this attribute can be a custom attribute, not necessarily an attribute of the class itself.
### Class Selector
```css
.redButton {background-color: magenta; }
```
Matches all instances of QPushButton, but does not match its subclasses, note that there is a dot in front.
### ID Selector
```css
QPushButton #myButton {background-color: magenta; }
```
Match all QPushButton objects whose object name is myButton. The id here is actually the value specified by objectName.
### Descendant Selector
```css
QDialog {background-color: gray; }
QDialog QPushButton {
    border: 2px solid magenta;
    border-radius: 10px;
    background-color: white;
    padding: 2px 15px;
}
```
All QPushButtons contained in the QDialog container, whether direct or indirect.
### Child Selector
```css
QFrame {background-color: gray; }
QFrame > QPushButton{
    border: 2px solid magenta;
    border-radius: 10px;
    background-color: white;
    padding: 2px 15px;
}
```
QPushButton under all QFrame containers, where the direct parent container of QPushButton is required to be QFrame.
#### Sub-controls
For more complex controls, it is often composed of multiple sub-controls. For example, QComboBox is composed of text boxes and drop-down buttons. For Qt Style Sheet, we allow us to style the sub-controls separately, which greatly enhances the flexibility of styles.
```css
QComboBox::drop-down { background-color: brown; }

::down-arrow /*the drop down part of combo box and spin box*/
::drop-down /*the drop down part of combo box*/
::indicator /*the indicator part of the check box, radio button and selectable group box*/
::item /*the sub item of menu, menu bar and status bar*/
::menu-indicator /*the menu indicator of push button*/
::title /*the title part of group box*/
::down-button /*downward part of spin box*/
::up-arrow /*upward part  of spin box*/
::up-button /*upward push button part of spin box*/
```
### Pseudo Selector
```css
QPushButton:pressed {background-color: red; }
QPushButton:hover {background-color: red; }
QCheckBox:!checked {backgroundcolor: red; }

:checked 
:unchecked / :!checked
:disabled / :enabled
:focus
:hover
:indeterminate
:off / :on
:pressed
```
`Selector: State` As a selector, it supports the `!` Operator, which means not.
