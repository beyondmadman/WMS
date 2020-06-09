#include "ltoolbar.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include "llogindlg.h"

LToolBar::LToolBar(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(25);

    //登录图标
    QLabel* iconLabel = new QLabel(this);
    iconLabel->setFixedSize(25, 25);
    iconLabel->setScaledContents(true);
    QPixmap *pixmap = new QPixmap(":/res/logon.png");
    pixmap->scaled(iconLabel->size(), Qt::KeepAspectRatio);
    iconLabel->setScaledContents(true);
    iconLabel->setPixmap(*pixmap);

    //设置按钮
    QPushButton* loginButton = new QPushButton(this);
    loginButton->setText("登录");
    loginButton->setFixedSize(40,18);
    loginButton->setStyleSheet(
                "QPushButton{color:rgb(0,212,86);background:transparent;border: 1px solid rgb(0,212,86);}"
                "QPushButton:hover{color:rgb(33,231,130);background:transparent;border: 1px solid rgb(33,231,130);}"
                "QPushButton:pressed{color:rgb(22,205,103);background:transparent;border: 1px solid rgb(22,205,103);}"
                );

    //标题栏布局
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addStretch();
    hLayout->addWidget(loginButton,0,Qt::AlignVCenter);
    hLayout->addWidget(iconLabel,0,Qt::AlignVCenter);
    hLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(hLayout);

    connect(loginButton,&QPushButton::clicked,this,on_login);
}

//登录按钮
void LToolBar::on_login()
{
    LLoginDlg* loginDlg = new LLoginDlg(this);
    loginDlg->show();
}

