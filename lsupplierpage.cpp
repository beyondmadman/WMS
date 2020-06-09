#include "lsupplierpage.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>

LSupplierPage::LSupplierPage(QWidget *parent) : QWidget(parent)
{
    QLabel *titleLabel = new QLabel("供应商信息");
    QPushButton *addButton = new QPushButton("添加");

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleLabel);
    titleLayout->addStretch();
    titleLayout->addWidget(addButton);

    QLabel *idLabel = new QLabel("商家编号");
    QLineEdit *idEdit = new QLineEdit;
    QLabel *nameLabel = new QLabel("商家名称");
    QLineEdit *nameEdit = new QLineEdit;
    QLabel *addrLabel = new QLabel("所在地");
    QComboBox *addrEdit = new QComboBox;
    QLabel *dateLabel = new QLabel("添加日期");
    QDateEdit *dateEdit = new QDateEdit;
    QLabel *cateLabel = new QLabel("经营品类");
    QComboBox *cateEdit = new QComboBox;
    QPushButton *searchButton = new QPushButton("搜索");

    QHBoxLayout *sLayout_1 = new QHBoxLayout;
    sLayout_1->addWidget(idLabel);
    sLayout_1->addWidget(idEdit);
    sLayout_1->addStretch();
    sLayout_1->addWidget(nameLabel);
    sLayout_1->addWidget(nameEdit);
    sLayout_1->addStretch();
    sLayout_1->addWidget(addrLabel);
    sLayout_1->addWidget(addrEdit);
    sLayout_1->addStretch();
    sLayout_1->addWidget(dateLabel);
    sLayout_1->addWidget(dateEdit);

    QHBoxLayout *sLayout_2 = new QHBoxLayout;
    sLayout_2->addWidget(cateLabel);
    sLayout_2->addWidget(cateEdit);
    sLayout_2->addStretch();
    sLayout_2->addWidget(searchButton);

    QVBoxLayout *sLayout = new QVBoxLayout;
    sLayout->addLayout(sLayout_1);
    sLayout->addLayout(sLayout_2);
    QFrame *sFrame = new QFrame;
    sFrame->setFrameStyle(QFrame::StyledPanel);
    sFrame->setLayout(sLayout);

//    supplierModel = new QSqlTableModel(this, NULL);//关联数据库
//    supplierModel->setTable("supplier");//选择数据表
//    supplierModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//设置保存策略为手动提交
//    supplierModel->setHeaderData(0,Qt::Horizontal, "序号");
//    supplierModel->setHeaderData(1,Qt::Horizontal, "商家名称");
//    supplierModel->setHeaderData(2,Qt::Horizontal, "所在地");
//    supplierModel->setHeaderData(3,Qt::Horizontal, "添加日期");
//    supplierModel->setHeaderData(4,Qt::Horizontal, "经营类目");
//    supplierModel->setHeaderData(5,Qt::Horizontal, "商品数量");
//    supplierModel->setHeaderData(6,Qt::Horizontal, "联系人");
//    supplierModel->setHeaderData(7,Qt::Horizontal, "联系方式");
//    supplierModel->select(); //选取整个表的所有行

    QTableView *tableView = new QTableView(this);
    tableView->setModel(supplierModel);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(titleLayout);
    layout->addWidget(sFrame);
    layout->addWidget(tableView);
    setLayout(layout);
}
