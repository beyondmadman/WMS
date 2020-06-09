#include "lnavbutton.h"
#include <QPainter>

LNavButton::LNavButton(QWidget *parent) : QPushButton(parent)
{
    iconHSpace = 11;
    iconSize = QSize(16, 16);
    iconPix = QPixmap();

    normalBgColor = QColor(221, 221, 221);
    hoverBgColor = QColor(204, 204, 204);
    checkBgColor = QColor(12, 204, 108);

    textHSpace = 0;
    normalTextColor = QColor(120, 120, 120);
    hoverTextColor = QColor(120, 120, 120);
    checkTextColor = QColor(255, 255, 255);

    normalBgBrush = Qt::NoBrush;
    hoverBgBrush = Qt::NoBrush;
    checkBgBrush = Qt::NoBrush;

    hover = false;
    setCheckable(true);
}

void LNavButton::enterEvent(QEvent *)
{
    hover = true;
    this->update();
}

void LNavButton::leaveEvent(QEvent *)
{
    hover = false;
    this->update();
}

void LNavButton::paintEvent(QPaintEvent *)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制背景
    drawBg(&painter);

    //绘制图标
    drawIcon(&painter);

    //绘制文字
    drawText(&painter);
}

void LNavButton::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QRect bgRect;
    bgRect = QRect(0,0,width() ,height());


    //如果画刷存在则取画刷
    QBrush bgBrush;
    if (isChecked()) {
        bgBrush = checkBgBrush;
    } else if (hover) {
        bgBrush = hoverBgBrush;
    } else {
        bgBrush = normalBgBrush;
    }

    if (bgBrush != Qt::NoBrush) {
        painter->setBrush(bgBrush);
    } else {
        //根据当前状态选择对应颜色
        QColor bgColor;
        if (isChecked()) {
            bgColor = checkBgColor;
        } else if (hover) {
            bgColor = hoverBgColor;
        } else {
            bgColor = normalBgColor;
        }

        painter->setBrush(bgColor);
    }

    painter->drawRect(bgRect);

    painter->restore();
}

void LNavButton::drawIcon(QPainter *painter)
{
    painter->save();

    if (!iconPix.isNull()) {
        //等比例平滑缩放图标
        iconPix = iconPix.scaled(iconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter->drawPixmap((width() - iconSize.width()) / 2 , iconHSpace, iconPix);
    }

    painter->restore();
}

void LNavButton::drawText(QPainter *painter)
{
    painter->save();
    painter->setBrush(Qt::NoBrush);

    //根据当前状态选择对应颜色
    QColor textColor;
    if (isChecked()) {
        textColor = checkTextColor;
    } else if (hover) {
        textColor = hoverTextColor;
    } else {
        textColor = normalTextColor;
    }

    QRect textRect = QRect(0, iconSize.height() + iconHSpace + textHSpace, width(), height());
    painter->setPen(textColor);
    painter->drawText(textRect, Qt::AlignHCenter | Qt::AlignTop, text());

    painter->restore();
}

void LNavButton::setIconHSpace(int iconHSpace)
{
    if (this->iconHSpace != iconHSpace) {
        this->iconHSpace = iconHSpace;
        this->update();
    }
}

void LNavButton::setIconSize(const QSize &iconSize)
{
    if (this->iconSize != iconSize) {
        this->iconSize = iconSize;
        this->update();
    }
}

void LNavButton::setIconPix(const QPixmap &iconPix)
{
    this->iconPix = iconPix;
    this->update();
}

void LNavButton::setNormalBgColor(const QColor &normalBgColor)
{
    if (this->normalBgColor != normalBgColor) {
        this->normalBgColor = normalBgColor;
        this->update();
    }
}

void LNavButton::setHoverBgColor(const QColor &hoverBgColor)
{
    if (this->hoverBgColor != hoverBgColor) {
        this->hoverBgColor = hoverBgColor;
        this->update();
    }
}

void LNavButton::setCheckBgColor(const QColor &checkBgColor)
{
    if (this->checkBgColor != checkBgColor) {
        this->checkBgColor = checkBgColor;
        this->update();
    }
}

 void LNavButton::setTextHSpace(int textHSpace)
 {
     if (this->textHSpace != textHSpace) {
         this->textHSpace = textHSpace;
         this->update();
     }
 }

void LNavButton::setNormalTextColor(const QColor &normalTextColor)
{
    if (this->normalTextColor != normalTextColor) {
        this->normalTextColor = normalTextColor;
        this->update();
    }
}

void LNavButton::setHoverTextColor(const QColor &hoverTextColor)
{
    if (this->hoverTextColor != hoverTextColor) {
        this->hoverTextColor = hoverTextColor;
        this->update();
    }
}

void LNavButton::setCheckTextColor(const QColor &checkTextColor)
{
    if (this->checkTextColor != checkTextColor) {
        this->checkTextColor = checkTextColor;
        this->update();
    }
}

void LNavButton::setNormalBgBrush(const QBrush &normalBgBrush)
{
    if (this->normalBgBrush != normalBgBrush) {
        this->normalBgBrush = normalBgBrush;
        this->update();
    }
}

void LNavButton::setHoverBgBrush(const QBrush &hoverBgBrush)
{
    if (this->hoverBgBrush != hoverBgBrush) {
        this->hoverBgBrush = hoverBgBrush;
        this->update();
    }
}

void LNavButton::setCheckBgBrush(const QBrush &checkBgBrush)
{
    if (this->checkBgBrush != checkBgBrush) {
        this->checkBgBrush = checkBgBrush;
        this->update();
    }
}
