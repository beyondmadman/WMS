#include "lbutton.h"

LButton::LButton(QWidget *parent)
    :QPushButton(parent),
    status(NORMAL),
    press(false)
{

}

//添加图片
void LButton::loadPixmap(QString pic_name)
{
    pixmap.load(pic_name);
    width = pixmap.width()/4;
    height = pixmap.height();
    setFixedSize(width, height);
}

//进入事件
void LButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}

//离开事件
void LButton::leaveEvent(QEvent * e)
{
    status = NORMAL;
    update();
}

//鼠标按下
void LButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        press = true;
        status = PRESS;
        update();
    }
     QPushButton::mousePressEvent(e);
}

//鼠标释放
void LButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(press)
    {
        press = false;
        status = ENTER;
        update();
    }
    QPushButton::mouseReleaseEvent(e);
}

//绘图事件
void LButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), pixmap.copy(width * status, 0, width, height));
}
