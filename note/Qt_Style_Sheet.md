# Qt Style Sheet

There is a CSS syntax parser inside Qt. We could define our style control to an external file with CSS parser. After the CSS syntax parser is parsed, the corresponding function module is called to complete the style change. Qt's style sheet allows us to easily change the appearance of the application without making any code changes to the program. The idea comes from CSS in web design, that is, functional design and aesthetic design can be separated.

## Loading Method

In the QWidget project, add a qrc source file, and then add a prefix "/". Then add a QSS file here, just create a text file and modify it to the file extension as `*.qss` file,  and add it to the qrc source file with highlighter updates. After adding the qss file, then could open such file with coding :
```cpp
QFile file(":/qss/myQss.qss"); // relative path of the *.qss file
file.open(QFile::ReadOnly);
QTextStream fileText(&file);
QString stylesheet = fileText.readAll();
this->setStyleSheet(stylesheet);

file.close();
```
