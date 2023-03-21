#ifndef SLQMLCUSTOMPLOT_H
#define SLQMLCUSTOMPLOT_H

#include <QtQuick>
class QCustomPlot;
class QCPAbstractPlottable;     //一个抽象基类
                                //是 Qt 开源绘图库 QCustomPlot 中的一个关键类

class SlQmlCustomPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    SlQmlCustomPlot(QQuickItem *parent = nullptr);
    virtual ~SlQmlCustomPlot();
    void paint( QPainter* painter );
    virtual void initCustomPlotUI(){}

    QCustomPlot *getPlot();

protected:
    virtual void hoverMoveEvent(QHoverEvent *event);
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );
    virtual void wheelEvent( QWheelEvent *event );

    void routeMouseEvents( QMouseEvent* event );
    void routeWheelEvents( QWheelEvent* event );

public slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onCustomReplot();
    void updateCustomPlotSize();
private:
    QCustomPlot*         m_CustomPlot;
};

class CustomPlotItem : public SlQmlCustomPlot
{
    Q_OBJECT
public:
    CustomPlotItem( QQuickItem* parent = nullptr );
    virtual ~CustomPlotItem();
    Q_INVOKABLE void initCustomPlot();
protected:
    virtual void timerEvent(QTimerEvent *event);
private:
    int m_timerId;
};

class CustomPlotBarItem : public SlQmlCustomPlot
{
    Q_OBJECT
    Q_PROPERTY(QColor barColor READ barColor WRITE setBarColor NOTIFY barColorChanged)
public:
    CustomPlotBarItem( QQuickItem* parent = nullptr );
    virtual ~CustomPlotBarItem();
    Q_INVOKABLE void initCustomPlot();
    QColor barColor();
    void setBarColor(const QColor &color);
signals:
    void barColorChanged(const QColor &color);
private:
    QColor mBarColor{Qt::blue};
};

class CustomKLine : public SlQmlCustomPlot{
  Q_OBJECT
public:
    explicit CustomKLine(QQuickItem* parent = nullptr);
    Q_INVOKABLE void initCustomPlot();
};

class CustomColorMap : public SlQmlCustomPlot{
  Q_OBJECT
public:
    explicit CustomColorMap(QQuickItem* parent = nullptr);
    Q_INVOKABLE void initCustomPlot();
};

class CustomBarChart: public SlQmlCustomPlot
{
  Q_OBJECT
public:
    explicit CustomBarChart(QQuickItem *parent = nullptr){}

    Q_INVOKABLE void iniCustomPlot();
};

#endif // SLQMLCUSTOMPLOT_H
