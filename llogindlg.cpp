#include "llogindlg.h"
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QApplication>

#define SHADOW_WIDTH            5

LLoginDlg::LLoginDlg(QWidget *parent)
    : LShadowWidget(parent)
{
    //设置窗口大小
    resize(370, 275);

    //设置标题
    iconLabel = new QLabel(this);
    titleLabel = new QLabel(this);
    closeButton = new LButton(this);
    iconLabel->setFixedSize(20, 20);
    iconLabel->setPixmap(QPixmap(":/res/wms"));
    iconLabel->setScaledContents(true);
    titleLabel->setText("登录");
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    closeButton->loadPixmap(":res/close");
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    titleLabel->setPalette(palette);

    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->addWidget(iconLabel,0,Qt::AlignVCenter);
    titleLayout->setSpacing(5);
    titleLayout->addWidget(titleLabel,0,Qt::AlignVCenter);
    titleLayout->addStretch();
    titleLayout->addWidget(closeButton,0,Qt::AlignTop);
    titleLayout->setContentsMargins(5, 5, 5, 0);

    //输入区域
    accountLabel = new QLabel("账号:");
    passwordLabel = new QLabel("密码:");
    accountEdit = new QLineEdit;
    passwordEdit = new QLineEdit;
    accountLabel->setScaledContents(true);
    passwordLabel->setScaledContents(true);
    accountLabel->setAlignment(Qt::AlignRight);
    passwordLabel->setAlignment(Qt::AlignRight);
    passwordEdit->setEchoMode(QLineEdit::Password);
    accountEdit->setFixedHeight(25);
    passwordEdit->setFixedHeight(25);
    accountEdit->setStyleSheet(
                "QLineEdit{background:white;padding-left:5px;padding-top:1px; border:1px solid rgb(209,209,209);}"
               );
    passwordEdit->setStyleSheet("QLineEdit{background:white;padding-top:0px;border:1px solid rgb(209,209,209);}"
               );

    QGridLayout *contentLayout = new QGridLayout;
    contentLayout->addWidget(accountLabel,0,0);
    contentLayout->addWidget(accountEdit,0,1);
    contentLayout->addWidget(passwordLabel,1,0);
    contentLayout->addWidget(passwordEdit,1,1);
    contentLayout->setHorizontalSpacing(5);
    contentLayout->setVerticalSpacing(10);
    contentLayout->setContentsMargins(70, 40, 70, 0);

    //登录按钮
    loginButton = new QPushButton();
    loginButton->setText("登录");
    loginButton->setFixedSize(160, 25);
    loginButton->setStyleSheet(
                "QPushButton{color:white;background-color:rgb(0,212,86);border-radius:1px;}"
                "QPushButton:hover{color:white; background-color:rgb(33,231,130);}"
                "QPushButton:pressed{color:white;background-color:rgb(22,205,103);padding-left:1px;padding-top:1px; }"
                );
    QHBoxLayout *loginLayout = new QHBoxLayout();
    loginLayout->addWidget(loginButton);
    loginLayout->setSpacing(0);
    loginLayout->setContentsMargins(10, 0, 10, 0);

    //注册按钮
    registButton = new QPushButton();
    registButton->setText("注册");
    registButton->setFixedSize(70, 25);
    registButton->setCursor(Qt::PointingHandCursor);
    registButton->setStyleSheet(
                "QPushButton{color:rgb(0,212,86);background-color:transparent;}"
                "QPushButton:hover{ color:rgb(33,231,130);}"
                "QPushButton:pressed{color:rgb(22,205,103);}"
                );

    QHBoxLayout *registLayout = new QHBoxLayout();
    registLayout->addStretch();
    registLayout->addWidget(registButton);
    registLayout->setSpacing(0);
    registLayout->setContentsMargins(10, 0, 10, 10);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(titleLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(contentLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(loginLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(registLayout);
    mainLayout->setSpacing(0);

    mainLayout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

    setLayout(mainLayout);


    connect(closeButton, QPushButton::clicked, this, close);
    connect(loginButton, QPushButton::clicked, this, on_Login);
    connect(registButton, QPushButton::clicked, this, on_Regist);
}

LLoginDlg::~LLoginDlg()
{

}

void LLoginDlg::paintEvent(QPaintEvent *event)
{
    LShadowWidget::paintEvent(event);

    int width = this->width();
    int height = this->height();

    int titleHeight = 35;

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(34,203,100));
    painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, width-2*SHADOW_WIDTH, titleHeight));

    painter.setBrush(Qt::white);
    painter.drawRect(QRect(SHADOW_WIDTH, titleHeight, width-2*SHADOW_WIDTH, height-titleHeight-SHADOW_WIDTH));
}

//登录按钮
void LLoginDlg::on_Login()
{
    onDropWindow();
}

//注册按钮
void LLoginDlg::on_Regist()
{
    onShakeWindow();
}

void LLoginDlg::onDropWindow()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    QDesktopWidget *desktopWidget = QApplication::desktop();
    int x = (desktopWidget->availableGeometry().width() - width()) / 2;
    int y = (desktopWidget->availableGeometry().height() - height()) / 2;

    animation->setDuration(1000);
    animation->setStartValue(QRect(x, 0, width(), height()));
    animation->setEndValue(QRect(x, y, width(), height()));
    animation->setEasingCurve(QEasingCurve::OutElastic);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    connect(animation, SIGNAL(finished()), this, SLOT(hide()));
}

void LLoginDlg::onShakeWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
    pAnimation->setDuration(500);
    pAnimation->setLoopCount(2);
    pAnimation->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(1, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}
