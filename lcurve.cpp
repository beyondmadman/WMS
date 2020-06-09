#include "lcurve.h"
#include <QPainter>

LCurve::LCurve(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(400,550);

    values.clear();
    xCount = 12;
    yCount = 3;
    xminValue = 0;
    xmaxValue = 12;
    yminValue = 0;
    ymaxValue = 3;
    xNames << "1" << "2" << "3" << "4" <<"5" << "6" << "7" << "8" << "9" <<"10" << "11" <<"12";
    yNames << "100" << "200" << "300";

    tipsName = "供应商数量";
    tipsValue = 0;

    homePoint.setX(100);
    homePoint.setY(height()-100);
    xPoint.setX(width()-100);
    xPoint.setY(height()-100);
    yPoint.setX(100);
    yPoint.setY(height()/2);
}

void LCurve::resizeEvent(QResizeEvent *)
{
    homePoint.setX(100);
    homePoint.setY(height()-100);
    xPoint.setX(width()-100);
    xPoint.setY(height()-100);
    yPoint.setX(100);
    yPoint.setY(height()/2);

    update();
}

void LCurve::paintEvent(QPaintEvent *)
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

    //绘制曲线
    drawCurve(&painter);
}

 void LCurve::drawBg(QPainter *painter)
 {
     painter->save();
     painter->setPen(Qt::NoPen);
     painter->setBrush(QColor(249,249,249));
     painter->drawRect(rect());
     painter->restore();
 }

 //绘制提示
 void LCurve::drawTips(QPainter *painter)
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
 void LCurve::drawAxis(QPainter *painter)
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

     //绘制刻度线
     QPen penDegree;
     penDegree.setColor(QColor(0,138,0));
     penDegree.setWidth(2);
     painter->setPen(penDegree);

     for(int i=0;i<xCount;i++)
     {
         QFont font;
         font.setPointSize(9);
         painter->setFont(font);
         QFontMetrics fmTipsValue(font);
         QRect rec = fmTipsValue.boundingRect(xNames.at(i));
         int textWidth = rec.width();
         int textHeight = rec.height();

         painter->drawLine(homePoint.x()+(i+1)*(xPoint.x()-homePoint.x()-10)/xCount,homePoint.y(),homePoint.x()+(i+1)*(xPoint.x()-homePoint.x()-10)/xCount,homePoint.y()-4);
         painter->drawText(homePoint.x()+(i+1)*(xPoint.x()-homePoint.x()-10)/xCount-textWidth/2,homePoint.y()+textHeight+10,xNames[i]);

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

         painter->drawLine(homePoint.x(),homePoint.y() - (i + 1)*(homePoint.y() - yPoint.y() - 10)/yCount,homePoint.x()+4,homePoint.y()-(i+1)*(homePoint.y()-yPoint.y()-10)/yCount);
         painter->drawText(homePoint.x()- textWidth - 15,homePoint.y() - (i + 1)*(homePoint.y()-yPoint.y()-10) / yCount+textHeight/2,yNames[i]);
     }

     painter->drawText(yPoint.x(),yPoint.y()-20,tipsName);

     painter->restore();
 }

 //绘坐曲线
 void LCurve::drawCurve(QPainter *painter)
 {
     if (values.count() <= 0) return;

     painter->save();

     int xOffset=(xPoint.x()-homePoint.x()-10)/xCount;
     int yOffset=(homePoint.y()-yPoint.y()-10)/yCount;

     float kx = (float)(xmaxValue - xminValue)/xCount;
     float ky = (float)(ymaxValue - yminValue)/yCount;

     QPen pen,penPoint;
     pen.setColor(QColor(0,138,0));
     pen.setWidth(2);

     penPoint.setColor(QColor(120,120,120));
     penPoint.setWidth(5);
     for(int i=0;i<values.count()-1;i++)
     {
         painter->setPen(pen);
         painter->drawLine(QPointF(homePoint.x()+(values[i].x()-xminValue)/kx*xOffset, homePoint.y()-(values[i].y()-yminValue)/ky*yOffset),
                           QPointF(homePoint.x()+(values[i+1].x()-xminValue)/kx*xOffset, homePoint.y()-(values[i+1].y()-yminValue)/ky*yOffset));
         painter->setPen(penPoint);
         painter->drawPoint(homePoint.x()+(values[i].x()-xminValue)/kx*xOffset,
                            homePoint.y()-(values[i].y()-yminValue)/ky*yOffset);
     }
     painter->drawPoint(homePoint.x()+(values[values.count()-1].x()-xminValue)/kx*xOffset,homePoint.y()-(values[values.count()-1].y()-yminValue)/ky*yOffset);

     painter->restore();
 }

 //设置X轴数量
 void LCurve::setXAxis(int count,double minValue,double maxValue)
 {
     xCount = count;
     xminValue = minValue;
     xmaxValue = maxValue;

     update();
 }

 //设置Y轴数量
 void LCurve::setYAxis(int count,double minValue,double maxValue)
 {
     yCount = count;
     yminValue = minValue;
     ymaxValue = maxValue;

     update();
 }

 //设置数据
 void LCurve::setData(const QStringList &xNames, const QStringList &yNames, const QVector<QPointF> &values)
 {
     this->xNames = xNames;
     this->yNames = yNames;
     this->values = values;

     for(int i=0;i<values.count();i++)
     {
         tipsValue += values[i].y();
     }

     update();
 }


