#include "ltime.h"
#include <QLabel>
#include <QDateTime>
#include <QHBoxLayout>

LTime::LTime(QWidget *parent) : QWidget(parent)
{
    QLabel* timeLabel = new QLabel(this);
    QPalette pe;
    pe.setColor(QPalette::WindowText, QColor(0,138,0));
    timeLabel ->setPalette(pe);
    timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));

    QTimer *currentTime = new QTimer(this);
    currentTime->start(1000);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addStretch();
    hLayout->addWidget(timeLabel,0,Qt::AlignVCenter);
    hLayout->setContentsMargins(0, 0, 10, 0);
    setLayout(hLayout);

    connect(currentTime,QTimer::timeout,this,[=]()
    {
        timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd"));
    });
}
