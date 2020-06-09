#ifndef LTITLEBAR_H
#define LTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include "lbutton.h"

class LTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit LTitleBar(QWidget *parent = 0);

protected:
    //按下事件
    void mousePressEvent(QMouseEvent *event);
    //移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //双击事件
    void mouseDoubleClickEvent(QMouseEvent *event);

    //事件处理
    bool eventFilter(QObject *obj, QEvent *event);

    //移动窗口
    void moveWidget(const QPoint& gMousePos);
    //最大化移动
    void maximizeMove(QMouseEvent* event);
    //最大化更新
    void updateMaximize();

private:
    QWidget             *widget;                //窗口变量
    QPoint              dragPos;                //移动位置
    bool                widgetMovable;          //移动标识
    QLabel              *iconLabel;             //标题图标
    QLabel              *titleLabel;            //标题内容
    LButton             *minimizeButton;        //最小按钮
    LButton             *maximizeButton;        //最大按钮
    LButton             *closeButton;           //关闭按钮


signals:


public slots:
     //按钮点击
     void on_Clicked();
};

#endif // LTITLEBAR_H
