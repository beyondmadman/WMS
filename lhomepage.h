#ifndef LHOMEPAGE_H
#define LHOMEPAGE_H

#include <QWidget>
#include "ltime.h"
#include "lcurve.h"
#include "lhistogram.h"

class LHomePage : public QWidget
{
    Q_OBJECT
public:
    explicit LHomePage(QWidget *parent = 0);

public:
    void initTime();
    void initCure();
    void initHistogram();
    void initLayout();

private:
    LTime*          time;
    LCurve*         curve;
    LHistogram*     histogram;

signals:

public slots:
};

#endif // LHOMEPAGE_H
