#ifndef LHISTOGRAM_H
#define LHISTOGRAM_H

#include <QWidget>

class LHistogram : public QWidget
{
    Q_OBJECT
public:
    explicit LHistogram(QWidget *parent = 0);

private:
    //绘制背景
    void drawBg(QPainter *painter);
    //绘制提示
    void drawTips(QPainter *painter);
    //绘坐标轴
    void drawAxis(QPainter *painter);
    //绘柱状图
    void drawHistogram(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public:
    //设置Y轴
    void setYAxis(int count,double minValue,double maxValue);
    //设置数据
    void setData(const QStringList &xNames, const QStringList &yNames, const QVector<qreal> &values);

private:
    QPointF                 homePoint;          //原点坐标
    QPointF                 xPoint;             //X点坐标
    QPointF                 yPoint;             //Y点坐标

    int                     yCount;
    double                  yminValue;
    double                  ymaxValue;

    QVector<qreal>          values;

    QStringList             xNames;
    QStringList             yNames;

    QString                 tipsName;
    double                  tipsValue;

    quint32                 pillarWidth;
    qreal                   heightFact;

signals:

public slots:
};

#endif // LHISTOGRAM_H
