#ifndef LSHADOWWIDGET_H
#define LSHADOWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

class LShadowWidget : public QWidget
{
	Q_OBJECT

public:

    explicit LShadowWidget(QWidget *parent = 0);
    ~LShadowWidget();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:

    QPoint               movePoint;
    bool                 mousePress;

};

#endif //LSHADOWWIDGET_H
