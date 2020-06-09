#include "ltitlebar.h"
#include <QHBoxLayout>

LTitleBar::LTitleBar(QWidget *parent)
    : QWidget(parent),
      widgetMovable(false)
{
    widget = parent;

    iconLabel = new QLabel(this);
    titleLabel = new QLabel(this);
    minimizeButton = new LButton(this);
    maximizeButton = new LButton(this);
    closeButton = new LButton(this);

    //初始化图标Label
    iconLabel->setFixedSize(20, 20);
    iconLabel->setScaledContents(true);
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    titleLabel->setPalette(palette);

    //设置图片
    minimizeButton->loadPixmap(":/res/min_button");
    maximizeButton->loadPixmap(":/res/max_button");
    closeButton->loadPixmap(":/res/close_button");

    minimizeButton->setToolTip(tr("最小化"));
    maximizeButton->setToolTip(tr("最大化"));
    closeButton->setToolTip(tr("关闭"));


    //标题栏布局
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(iconLabel,0,Qt::AlignVCenter);
    hLayout->addSpacing(5);
    hLayout->addWidget(titleLabel,0,Qt::AlignVCenter);
    hLayout->addWidget(minimizeButton,0,Qt::AlignTop);
    hLayout->addWidget(maximizeButton,0,Qt::AlignTop);
    hLayout->addWidget(closeButton,0,Qt::AlignTop);
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(5, 0, 5, 0);
    setLayout(hLayout);

    //设置信号和槽
    connect(minimizeButton,&LButton::clicked,this,on_Clicked);
    connect(maximizeButton,&LButton::clicked,this,on_Clicked);
    connect(closeButton,&LButton::clicked,this,on_Clicked);

}

//按下事件
void LTitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        widgetMovable = true;
        QRect frameRect = widget->frameGeometry();
        dragPos = event->globalPos() - frameRect.topLeft();

    }
}

//移动事件
void LTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton) && widgetMovable)
    {
        if (widget->isMaximized())
        {
            maximizeMove(event);
            return;
        }

        moveWidget(event->globalPos());
    }
}

//释放事件
void LTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && widgetMovable)
    {
        widgetMovable = false;
    }
}

//双击事件
void LTitleBar::mouseDoubleClickEvent(QMouseEvent *)
{
    emit maximizeButton->clicked();
}

bool LTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    QWidget* widget = qobject_cast<QWidget *>(obj);

    //判断发生事件的类型
    switch ( event->type() )
    {
    case QEvent::WindowTitleChange: //窗口标题改变事件
    {
        if (widget)
        {
            titleLabel->setText(widget->windowTitle());
            return true;
        }
    }
        break;

    case QEvent::WindowIconChange: //窗口图标改变事件
    {
        if (widget)
        {
            QIcon icon = widget->windowIcon();
            iconLabel->setPixmap(icon.pixmap(iconLabel->size()));
            return true;
        }
    }
        break;
    case QEvent::Resize:
    {
        updateMaximize(); //最大化/还原
        return true;
    }
        break;
    default:
        return QWidget::eventFilter(obj, event);
    }

    return QWidget::eventFilter(obj, event);
}

//按钮点击
void LTitleBar::on_Clicked()
{
    LButton* button = qobject_cast<LButton *>(sender());

    if (widget->isTopLevel())
    {
        //判断对象
        if (button == minimizeButton)
        {
            //最小化
            widget->showMinimized();
        }
        else if (button == maximizeButton)
        {
            //最大化/还原
            widget->isMaximized() ? widget->showNormal() : widget->showMaximized();
        }
        else if (button == closeButton)
        {
            //关闭
            widget->close();
        }
    }
}

//最大化更新
void LTitleBar::updateMaximize()
{
    if (widget->isTopLevel())
    {
        if (widget->isMaximized())
        {
            maximizeButton->loadPixmap(":/res/restore_button");
            maximizeButton->setToolTip("还原");
        }
        else
        {
            maximizeButton->loadPixmap(":/res/max_button");
            maximizeButton->setToolTip("最大化");
        }
    }
}

//移动窗口
void LTitleBar::moveWidget(const QPoint& gMousePos)
{
    widget->move(gMousePos - dragPos);
}

//最大化移动
void LTitleBar::maximizeMove(QMouseEvent* event)
{
    QPoint distance = event->globalPos() - dragPos;
    int length = distance.manhattanLength();
    if (length > 20)
    {
        QRect rect = widget->normalGeometry();
        int desX = dragPos.x() * rect.width() / widget->geometry().width();
        int desY = dragPos.y();
        rect.moveTopLeft(event->globalPos() - QPoint(desX, desY));

        widget->showNormal();
        widget->setGeometry(rect);

        dragPos = QPoint(desX, desY);

    }
}

