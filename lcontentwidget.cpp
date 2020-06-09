#include "lcontentwidget.h"
#include <QLabel>

LContentWidget::LContentWidget(QWidget *parent) : QWidget(parent)
{
    //创建导航
    creatNavBar();

    //创建页面
    creatStackWidget();

    //界面布局
    hLayout = new QHBoxLayout(this);
    hLayout->addLayout(vLayout);
    hLayout->addWidget(stackWidget);
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(hLayout);
}

//创建导航
void LContentWidget::creatNavBar()
{
    LNavButton* btn1 = new LNavButton(this);
    btn1->setText("主页");
    btn1->setIconPix(QPixmap(":/res/home"));
    LNavButton* btn2 = new LNavButton(this);
    btn2->setText("供应商管理");
    btn2->setIconPix(QPixmap(":/res/supplier"));
    LNavButton* btn3 = new LNavButton(this);
    btn3->setText("商品管理");
    btn3->setIconPix(QPixmap(":/res/goods"));
    LNavButton* btn4 = new LNavButton(this);
    btn4->setText("库存管理");
    btn4->setIconPix(QPixmap(":/res/stock"));
    LNavButton* btn5 = new LNavButton(this);
    btn5->setText("信息管理");
    btn5->setIconPix(QPixmap(":/res/info"));
    LNavButton* btn6 = new LNavButton(this);
    btn6->setText("用户管理");
    btn6->setIconPix(QPixmap(":/res/user"));

    vLayout = new QVBoxLayout();
    vLayout->addWidget(btn1);
    vLayout->addWidget(btn2);
    vLayout->addWidget(btn3);
    vLayout->addWidget(btn4);
    vLayout->addStretch();
    vLayout->addWidget(btn5);
    vLayout->addWidget(btn6);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0, 0, 0, 0);

    btns << btn1 << btn2 << btn3 << btn4 << btn5 << btn6;
    for (int i = 0; i < btns.count(); i++) {
        LNavButton *btn = btns.at(i);
        btn->setFixedSize(100,70);
        btn->setIconSize(QSize(45, 45));
        connect(btn, SIGNAL(clicked()), this, SLOT(switchPages()));
    }

    btn1->setChecked(true);
}

//创建页面
void LContentWidget::creatStackWidget()
{
    stackWidget = new QStackedWidget;
    homePage = new LHomePage(this);
    supplierPage = new LSupplierPage(this);
    QLabel *label3 = new QLabel("3");
    QLabel *label4 = new QLabel("4");
    QLabel *label5 = new QLabel("5");
    QLabel *label6 = new QLabel("6");
    stackWidget->addWidget(homePage);
    stackWidget->addWidget(supplierPage);
    stackWidget->addWidget(label3);
    stackWidget->addWidget(label4);
    stackWidget->addWidget(label5);
    stackWidget->addWidget(label6);
}

//页面切换
void LContentWidget::switchPages()
{
    LNavButton *b = (LNavButton *)sender();
    if(b->text() == "主页")
        stackWidget->setCurrentIndex(0);
    if(b->text() == "供应商管理")
        stackWidget->setCurrentIndex(1);
    if(b->text() == "商品管理")
        stackWidget->setCurrentIndex(2);
    if(b->text() == "库存管理")
        stackWidget->setCurrentIndex(3);
    if(b->text() == "信息管理")
        stackWidget->setCurrentIndex(4);
    if(b->text() == "用户管理")
        stackWidget->setCurrentIndex(5);

    for (int i = 0; i < btns.count(); i++)
    {
        LNavButton *btn = btns.at(i);
        btn->setChecked(b == btn);
    }
}
