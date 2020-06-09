#include "wmswidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include "ltitlebar.h"
#include "ltoolbar.h"
#include "lcontentwidget.h"

WMSWidget::WMSWidget(QWidget *parent) :
    QWidget(parent)
{

    //设置样式
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);

    //标题栏
    LTitleBar *wmsTitleBar = new LTitleBar(this);
    wmsTitleBar->setFixedHeight(25);
    installEventFilter(wmsTitleBar);

    //设置窗口
    setMinimumSize(900, 600);
    setWindowTitle("仓库管理系统-v1.0");
    setWindowIcon(QIcon(":/res/wms"));

    //标题栏背景
    QPalette palette;
    wmsTitleBar->setAutoFillBackground(true);
    palette.setColor(QPalette::Background, QColor(34,203,100));
    wmsTitleBar->setPalette(palette);

    //工具栏
    LToolBar* wmsToolBar = new LToolBar(this);
    wmsToolBar->setAutoFillBackground(true);
    palette.setColor(QPalette::Background, Qt::white);
    wmsToolBar->setPalette(palette);

    //客户区
    LContentWidget* wmsContetWidget = new LContentWidget(this);
    wmsContetWidget->setAutoFillBackground(true);
    palette.setColor(QPalette::Background, QColor(221,221,221));
    wmsContetWidget->setPalette(palette);

    //窗口布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(wmsTitleBar);
    layout->addWidget(wmsToolBar);
    layout->addWidget(wmsContetWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

WMSWidget::~WMSWidget()
{
    //removeEventFilter();
}
