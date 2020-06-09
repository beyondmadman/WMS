#include "lhistogram.h"
#include <QPainter>

LHistogram::LHistogram(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(400,550);

    values.clear();
    yCount = 3;
    yminValue = 0;
    ymaxValue = 3;
    xNames << "商品1" << "商品2" << "商品3" << "商品4";
    yNames << "100" << "200" << "300";

    tipsName = "商品数量";
    tipsValue = 0;

    homePoint.setX(100);
    homePoint.setY(height()-100);
    xPoint.setX(width()-100);
    xPoint.setY(height()-100);
    yPoint.setX(100);
    yPoint.setY(height()/2);

    pillarWidth = (xPoint.x()-homePoint.x())/(values.size()*2+1);
    heightFact = qreal(homePoint.y()-yPoint.y())/300;

}

void LHistogram::resizeEvent(QResizeEvent *)
{
    homePoint.setX(100);
    homePoint.setY(height()-100);
    xPoint.setX(width()-100);
    xPoint.setY(height()-100);
    yPoint.setX(100);
    yPoint.setY(height()/2);

    pillarWidth = (xPoint.x()-homePoint.x())/(values.size()*2+1);
    heightFact = qreal(homePoint.y()-yPoint.y())/300;

    update();
}

void LHistogram::paintEvent(QPaintEvent *)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制背景
    drawBg(&painter);

    //绘制提示
    drawTips(&painter);

    //绘制坐标轴
    drawAxis(&painter);

    //绘柱状图
    drawHistogram(&painter);
}

//绘制背景
void LHistogram::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(249,249,249));
    painter->drawRect(rect());
    painter->restore();
}

//绘制提示
void LHistogram::drawTips(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,138,0));
    painter->drawEllipse(QPointF(width()/2, height()/4),35,35);

    QPen pen;
    pen.setColor(Qt::white);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    painter->setPen(pen);
    QFont font;
    font.setPointSize(10);
    painter->setFont(font);
    QFontMetrics fmTipsValue(font);
    QRect rec = fmTipsValue.boundingRect(QString::number(tipsValue));
    int textWidth = rec.width();
    int textHeight = rec.height();

    painter->drawText(QRect((width()-textWidth)/2, height()/4-textHeight/2,textWidth,textHeight),Qt::AlignHCenter|Qt::AlignVCenter,QString::number(tipsValue));

    pen.setColor(QColor(0,138,0));
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);

    font.setPointSize(11);
    font.setBold(true);
    painter->setFont(font);
    QFontMetrics fmTipsName(font);
    rec = fmTipsName.boundingRect(tipsName);

    textWidth = rec.width();
    textHeight = rec.height();
    painter->drawText(QRect((width()-textWidth)/2, height()/4-textHeight/2-60,textWidth,textHeight),Qt::AlignHCenter|Qt::AlignVCenter,tipsName);

    painter->restore();
}

//绘坐标轴
void LHistogram::drawAxis(QPainter *painter)
{
    painter->save();
    painter->setPen(QColor(0,138,0));

    painter->drawLine(homePoint, xPoint);
    painter->drawLine(homePoint, yPoint);


    int Offset=6;
    QPointF xArrows1(xPoint.x(),xPoint.y()+Offset);
    QPointF xArrows2(xPoint.x(),xPoint.y()-Offset);
    QPointF xArrows3(xPoint.x()+Offset,xPoint.y());
    QPointF xArrowsPoints[3] = {xArrows1,xArrows2,xArrows3};

    QPointF yArrows1(yPoint.x()+Offset,yPoint.y());
    QPointF yArrows2(yPoint.x()-Offset,yPoint.y());
    QPointF yArrows3(yPoint.x(),yPoint.y()-Offset);
    QPointF yArrowsPoints[3] = {yArrows1,yArrows2,yArrows3};

    painter->setBrush(QBrush(QColor(0,138,0),Qt::SolidPattern));
    painter->drawPolygon(xArrowsPoints,3);
    painter->drawPolygon(yArrowsPoints,3);

    QPen penDegree;
    penDegree.setColor(QColor(0,138,0));
    penDegree.setWidth(2);
    painter->setPen(penDegree);


    pillarWidth = (xPoint.x()-homePoint.x())/(values.size()*2+1);
    heightFact = qreal(homePoint.y()-yPoint.y())/300;

    for(int i=0;i<xNames.count();i++)
    {
        QFont font;
        font.setPointSize(9);
        painter->setFont(font);
        QFontMetrics fmTipsValue(font);
        QRect rec = fmTipsValue.boundingRect(xNames[i]);
        int textWidth = rec.width();
        int textHeight = rec.height();

        painter->drawText((homePoint.x()+ pillarWidth + i * pillarWidth * 2) + pillarWidth / 2 - textWidth / 2,homePoint.y()+ textHeight + 10,xNames[i]);
    }

    for(int i=0;i<yCount;i++)
    {
        QFont font;
        font.setPointSize(9);
        painter->setFont(font);
        QFontMetrics fmTipsValue(font);
        QRect rec = fmTipsValue.boundingRect(QString::number(tipsValue));
        int textWidth = rec.width();
        int textHeight = rec.height();

        painter->drawLine(homePoint.x(),homePoint.y()-(i+1)*(homePoint.y()-yPoint.y()-10)/yCount,homePoint.x()+4,homePoint.y()-(i+1)*(homePoint.y()-yPoint.y()-10)/yCount);
        painter->drawText(homePoint.x()- textWidth - 15,homePoint.y() - (i + 1)*(homePoint.y()-yPoint.y()-10) / yCount+textHeight/2,yNames[i]);
    }

    painter->drawText(yPoint.x(),yPoint.y()-20,tipsName);

    painter->restore();
}

//绘柱状图
void LHistogram::drawHistogram(QPainter *painter)
{
    if (values.count() <= 0) return;

    painter->save();
    painter->setPen(Qt::NoPen);

    for (int i = 0; i < values.count(); ++i)
    {
        quint32 pillarHeight = values[i] * heightFact;
        int leftUpX = homePoint.x()+ pillarWidth + i * pillarWidth * 2;
        int leftUpY = homePoint.y()-pillarHeight;
        QRect rect(leftUpX, leftUpY, pillarWidth, pillarHeight);

        painter->setBrush(QColor(0,138,0));
        painter->drawRect(rect);
    }

    painter->restore();
}


void LHistogram::setYAxis(int count, double minValue, double maxValue)
{
    yCount = count;
    yminValue = minValue;
    ymaxValue = maxValue;

    update();
}

void LHistogram::setData(const QStringList &xNames, const QStringList &yNames, const QVector<qreal> &values)
{
    this->xNames = xNames;
    this->yNames = yNames;
    this->values = values;

    for(int i=0;i<values.count();i++)
    {
        tipsValue += values[i];
    }

    update();
}

