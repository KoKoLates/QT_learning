// Event Instance

//Header file
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    
private:
    Ui::Widget *ui;
    
protected:
    void closeEvent(QCloseEvent * event);
    void contextMenuEvent(QContextMenuEvent * event);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void mouseMoveEvent( QMouseEvent * event );
    void keyPressEvent( QKeyEvent * event );
    void wheelEvent( QWheelEvent * event );
    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent * event);
};

//Source file
Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event)
{
    //event->accept();
    //event->ignore();
    qDebug() << "QCloseEvent : Widget closed";
}
 
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "ContextMenu";
    event->accept();
    qDebug() << "QContextMenuEvent : Should pop up a context menu";
    qDebug() << "Event x : " << event->x() << " event y : " << event->y();
    qDebug() << "Event reason : " << event->reason();
    event->ignore();
}
 
void Widget::enterEvent(QEvent *event)
{
    event->accept();
    qDebug() << "Mouse pointer entered widget space";
}
 
void Widget::leaveEvent(QEvent *event)
{
    event->accept();
    qDebug() << "Mouse pointer left widget space";
    releaseKeyboard();
}
 
void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse pressed";
    qDebug() << "Button : " << event->button();
    grabKeyboard();
    event->accept();
}
 
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse released";
    releaseKeyboard();
    event->accept();
}
 
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "Mouse double clicked";
    event->accept();
}
 
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse moved to (" << event->x() << "," << event->y() << ")";
    event->accept();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "KeyPress event, pressed the key" << event->key();
    QString modifiers;
    if (event->modifiers() & Qt::ShiftModifier){
        modifiers += "Shift ";
    }
    if (event->modifiers() &  Qt::ControlModifier){
        modifiers += "Control ";
    }
    if (event->modifiers() & Qt::AltModifier){
        modifiers += "Alt ";
    }
    qDebug() << "Modifiers : " << modifiers;
 
    //Detect Shift+A
    if ( event->modifiers() & Qt::ShiftModifier){
        if(event->key() == 65){//
            qDebug() << "Shift A detected";
        }
    }
}
 
void Widget::wheelEvent(QWheelEvent *event)
{
    qDebug() << "Weel Event Delta : " << event->delta();
    qDebug() << " x : " << event->x() << ", y : " <<event->y();
    qDebug() << " Orientation : " << event->orientation();
}
 
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized , old size : " << event->oldSize();
    qDebug() << " new size : " << event->size();
}
 
void Widget::paintEvent(QPaintEvent *event)
{
    //Can be triggered for multiple reasons. Examples are when widget is resized, update or when an other maximized widget lies on top of this widget
    qDebug() << "Paint event. Rect is : " << event->rect();
}

