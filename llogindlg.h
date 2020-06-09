#ifndef LLOGINDLG_H
#define LLOGINDLG_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "lshadowwidget.h"
#include "lbutton.h"

class LLoginDlg : public LShadowWidget
{
    Q_OBJECT

public:
    LLoginDlg(QWidget *parent = 0);
    ~LLoginDlg();

private:
    void paintEvent(QPaintEvent *event);

    //窗口下坠
    void onDropWindow();
    //窗口抖动
    void onShakeWindow();

private:
    QLabel              *iconLabel;             //标题图标
    QLabel              *titleLabel;
    LButton             *closeButton;

    QLabel              *accountLabel;
    QLabel              *passwordLabel;
    QLineEdit           *accountEdit;
    QLineEdit           *passwordEdit;
    QPushButton         *loginButton;
    QPushButton         *registButton;

public slots:
     //登录按钮
     void on_Login();
     //注册按钮
     void on_Regist();
};

#endif // LLOGINDLG_H
