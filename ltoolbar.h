#ifndef LTOOLBAR_H
#define LTOOLBAR_H

#include <QWidget>

class LToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit LToolBar(QWidget *parent = 0);

signals:

public slots:
    //登录按钮
    void on_login();
};

#endif // LTOOLBAR_H
