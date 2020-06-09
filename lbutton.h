#ifndef LBUTTON_H
#define LBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>

enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};

class LButton : public QPushButton
{
     Q_OBJECT
public:
    explicit LButton(QWidget *parent = 0);

public:
    //添加图片
    void loadPixmap(QString pixPath);

private:
    //进入事件
    void enterEvent(QEvent *event);
    //离开事件
    void leaveEvent(QEvent *event);

    //鼠标按下
    void mousePressEvent(QMouseEvent *e);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *e);

    //绘图事件
    void paintEvent(QPaintEvent *);

private:
    //图片资源
    QPixmap pixmap;
     //按钮宽度
    int width;
    //按钮高度
    int height;
    //按钮状态
     ButtonStatus status;
    //按下标识
    bool press;
};

#endif // LBUTTON_H
