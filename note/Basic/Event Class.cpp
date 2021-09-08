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
    qDebug() << "Event x :" << event->x() << " event y : " << event->y();
    qDebug() << "Event reason : " << event->reason();
    event->ignore();
}
 
void Widget::enterEvent(QEvent *event)
{
    event->accept();
    qDebug() << "Mouse pointer entered widget space";
}
 
