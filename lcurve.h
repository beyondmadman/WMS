#ifndef LCURVE_H
#define LCURVE_H

#include <QWidget>
#include <QVector>
#include <QPointF>

class LCurve : public QWidget
{
    Q_OBJECT
public:
    explicit LCurve(QWidget *parent = 0);

private:
    //绘制背景
    void drawBg(QPainter *painter);
    //绘制提示
    void drawTips(QPainter *painter);
    //绘坐标轴
    void drawAxis(QPainter *painter);
    //绘坐曲线
    void drawCurve(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public:
    //设置X轴
    void setXAxis(int count,double minValue,double maxValue);
    //设置Y轴
    void setYAxis(int count,double minValue,double maxValue);
    //设置数据
    void setData(const QStringList &xNames, const QStringList &yNames, const QVector<QPointF> &values);

private:
    QPointF                 homePoint;          //原点坐标
    QPointF                 xPoint;             //X点坐标
    QPointF                 yPoint;             //Y点坐标

    int                     xCount;
    int                     yCount;
    double                  xminValue;
    double                  xmaxValue;
    double                  yminValue;
    double                  ymaxValue;
    QVector<QPointF>        values;             //数据

    QStringList             xNames;
    QStringList             yNames;

    QString                 tipsName;
    double                  tipsValue;

signals:

public slots:
};

#endif // LCURVE_H
