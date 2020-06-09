#ifndef LCONTENTWIDGET_H
#define LCONTENTWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "lnavbutton.h"
#include "lhomepage.h"
#include "lsupplierpage.h"

class LContentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LContentWidget(QWidget *parent = 0);

private:
    //创建导航
    void creatNavBar();
    //创建页面
    void creatStackWidget();

private:
    QList<LNavButton *> btns;
    QStackedWidget*     stackWidget;
    LHomePage*          homePage;
    LSupplierPage*      supplierPage;

    QVBoxLayout*        vLayout;
    QHBoxLayout*        hLayout;

signals:

public slots:
     void switchPages();
};

#endif // LCONTENTWIDGET_H
