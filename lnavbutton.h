#ifndef LNAVBUTTON_H
#define LNAVBUTTON_H

#include <QPushButton>

class LNavButton : public QPushButton
{
    Q_OBJECT
public:
    explicit LNavButton(QWidget *parent = 0);

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawText(QPainter *painter);
    void drawIcon(QPainter *painter);

private:
    int iconHSpace;                     //图标间隔
    QSize iconSize;                     //图标尺寸
    QPixmap iconPix;                    //图标资源

    QColor normalBgColor;               //正常背景颜色
    QColor hoverBgColor;                //悬停背景颜色
    QColor checkBgColor;                //选中背景颜色

    int textHSpace;                     //文字间隔
    QColor normalTextColor;             //正常文字颜色
    QColor hoverTextColor;              //悬停文字颜色
    QColor checkTextColor;              //选中文字颜色

    QBrush normalBgBrush;               //正常背景画刷
    QBrush hoverBgBrush;                //悬停背景画刷
    QBrush checkBgBrush;                //选中背景画刷

    bool hover;                         //悬停标志位

public:
    //设置图标间隔
    void setIconHSpace(int iconHSpace);
    //设置图标尺寸
    void setIconSize(const QSize &iconSize);
    //设置图标资源
    void setIconPix(const QPixmap &iconNormal);

    //设置正常背景颜色
    void setNormalBgColor(const QColor &normalBgColor);
    //设置悬停背景颜色
    void setHoverBgColor(const QColor &hoverBgColor);
    //设置选中背景颜色
    void setCheckBgColor(const QColor &checkBgColor);

    //设置文字间隔
    void setTextHSpace(int textHSpace);
    //设置正常文字颜色
    void setNormalTextColor(const QColor &normalTextColor);
    //设置悬停文字颜色
    void setHoverTextColor(const QColor &hoverTextColor);
    //设置选中文字颜色
    void setCheckTextColor(const QColor &checkTextColor);

    //设置正常背景画刷
    void setNormalBgBrush(const QBrush &normalBgBrush);
    //设置悬停背景画刷
    void setHoverBgBrush(const QBrush &hoverBgBrush);
    //设置选中背景画刷
    void setCheckBgBrush(const QBrush &checkBgBrush);


signals:

public slots:
};

#endif // LNAVBUTTON_H
