#ifndef LSUPPLIERPAGE_H
#define LSUPPLIERPAGE_H

#include <QWidget>
#include <QSqlTableModel>

class LSupplierPage : public QWidget
{
    Q_OBJECT
public:
    explicit LSupplierPage(QWidget *parent = 0);

private:
    QSqlTableModel*        supplierModel;

signals:

public slots:
};

#endif // LSUPPLIERPAGE_H
