#include "lhomepage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDate>

LHomePage::LHomePage(QWidget *parent) : QWidget(parent)
{
    initTime();

    initCure();

    initHistogram();

    initLayout();
}

void LHomePage::initTime()
{
    time = new LTime(this);
    time->setFixedHeight(50);
    QPalette palette;
    time->setAutoFillBackground(true);
    palette.setColor(QPalette::Background, QColor(249,249,249));
    time->setPalette(palette);
}

void LHomePage::initCure()
{
    curve = new LCurve(this);
    curve->setXAxis(12,0,12);
    curve->setYAxis(3,0,300);
    //QDate date = QDate::currentDate();
    //int month = date.month();
    QStringList xNameCurve,yNameCurve;
    QString name;
    for(int i = 1 ;i <= 12; ++i)
    {
       name = QString("%1").arg(i);
       xNameCurve << name;
    }

    yNameCurve << "100" << "200" << "300";

    QVector<QPointF> valuesCurve;
    valuesCurve.push_back(QPointF(1,100));
    valuesCurve.push_back(QPointF(2,200));
    valuesCurve.push_back(QPointF(3,205));
    valuesCurve.push_back(QPointF(4,220));
    curve->setData(xNameCurve,yNameCurve,valuesCurve);
}

void LHomePage::initHistogram()
{
    histogram = new LHistogram(this);
    histogram->setYAxis(3,0,300);
    QStringList xNameHistogram,yNameHistogram;
    xNameHistogram << "商品1" << "商品2" << "商品3"<< "商品4";
    yNameHistogram << "100" << "200" << "300";
    QVector<qreal> valuesHistogram;
    valuesHistogram.push_back(100);
    valuesHistogram.push_back(200);
    valuesHistogram.push_back(250);
    valuesHistogram.push_back(300);
    histogram->setData(xNameHistogram,yNameHistogram,valuesHistogram);

}

void LHomePage::initLayout()
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(curve);
    hLayout->setSpacing(0);
    hLayout->addWidget(histogram);
    hLayout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(time);
    vLayout->setSpacing(0);
    vLayout->addLayout(hLayout);
    vLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(vLayout);
}

