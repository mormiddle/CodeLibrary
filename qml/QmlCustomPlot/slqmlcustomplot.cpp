#include "slqmlcustomplot.h"
#include "qcustomplot.h"
#include <QDebug>

SlQmlCustomPlot::SlQmlCustomPlot( QQuickItem* parent) : QQuickPaintedItem( parent)
  , m_CustomPlot(new QCustomPlot())
{
    setFlag( QQuickItem::ItemHasContents, true );//绘制标志
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptHoverEvents(true);


}

SlQmlCustomPlot::~SlQmlCustomPlot()
{
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
}

/***************************************************************
* 函数名称:paint
* 函数功能:CustomPlot的绘图函数
* 参　  数: 无
* 返 回 值: 无
***************************************************************/
void SlQmlCustomPlot::paint(QPainter *painter)
{
    if(m_CustomPlot)
    {
        QPixmap picture(boundingRect().size().toSize());//使用当前对象的边界矩形大小
        QCPPainter qcpPainter(&picture);

        m_CustomPlot->toPainter( &qcpPainter );//将 qcustomplot绘制到QCPPainter中
                                               //将最终绘制好的内容添加到QPixmap中
        painter->drawPixmap(QPoint(), picture);

    }
}

/***************************************************************
* 函数名称:getPlot
* 函数功能:获取一个customplot指针
* 参　  数: 无
* 返 回 值: 无
***************************************************************/
QCustomPlot *SlQmlCustomPlot::getPlot()
{
    if( !m_CustomPlot){
        m_CustomPlot = new QCustomPlot;
    }
    return m_CustomPlot;
}

 void SlQmlCustomPlot::mousePressEvent(QMouseEvent *event)
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents(event);//将 事件转发给 customplot
 }

 void SlQmlCustomPlot::mouseReleaseEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::mouseMoveEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::mouseDoubleClickEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::wheelEvent( QWheelEvent *event )
 {
     routeWheelEvents( event );
 }

 void SlQmlCustomPlot::graphClicked( QCPAbstractPlottable* plottable )
 {
     qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
 }

 void SlQmlCustomPlot::routeMouseEvents(QMouseEvent *event)
 {
     if(m_CustomPlot)
     {
         QMouseEvent* newEvent = new QMouseEvent(event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers());
         QCoreApplication::postEvent(m_CustomPlot, newEvent);//将指定的事件添加到事件队列中等待处理
     }
 }

 void SlQmlCustomPlot::routeWheelEvents( QWheelEvent* event )
 {
     if (m_CustomPlot)
     {
         QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
         QCoreApplication::postEvent( m_CustomPlot, newEvent );
     }
 }

 void SlQmlCustomPlot::hoverMoveEvent(QHoverEvent *event)
 {
     //qDebug() << Q_FUNC_INFO<<event->pos();
 }


 void SlQmlCustomPlot::updateCustomPlotSize()
 {
     if (m_CustomPlot)
     {
         m_CustomPlot->setGeometry(0, 0, (int)width(), (int)height());
         m_CustomPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));
     }
 }

 void SlQmlCustomPlot::onCustomReplot()
 {
     //qDebug() << Q_FUNC_INFO;
     update();
 }


 ////
 /// \brief CustomPlotItem::CustomPlotItem
 /// \param parent
 ///
 CustomPlotItem::CustomPlotItem( QQuickItem* parent ) : SlQmlCustomPlot( parent )
    , m_timerId( 0 )
 {
 }

 CustomPlotItem::~CustomPlotItem()
 {
     if(m_timerId != 0) {
         killTimer(m_timerId);
     }
 }

void CustomPlotItem::initCustomPlot()
{
    updateCustomPlotSize();
    getPlot()->addGraph();
    getPlot()->graph(0)->setPen(QPen(Qt::red));
    getPlot()->xAxis->setLabel("t");
    getPlot()->yAxis->setLabel("s");
    getPlot()->xAxis->setRange(0, 10);
    getPlot()->yAxis->setRange(0, 5);
    getPlot()->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    startTimer(500);

    connect(getPlot(), &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot);

    getPlot()->replot();
}

void CustomPlotItem::timerEvent(QTimerEvent *event)
{
    static double t, U;
    U = ((double)rand() / RAND_MAX) * 5;
    getPlot()->graph(0)->addData(t, U);
    t++;
    getPlot()->replot();
}

///
/// \brief CustomPlotBarItem::CustomPlotBarItem
/// \param parent
///
CustomPlotBarItem::CustomPlotBarItem(QQuickItem* parent) : SlQmlCustomPlot(parent)
{
}

CustomPlotBarItem::~CustomPlotBarItem()
{
}

void CustomPlotBarItem::initCustomPlot()
{
    updateCustomPlotSize();
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);

    for(int i = 0; i < x1.size(); ++i)
    {
        x1[i] = i/(double)(x1.size() - 1)*10;
        y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    QCPGraph *graph1 = getPlot()->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = getPlot()->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars(getPlot()->xAxis, getPlot()->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars(getPlot()->xAxis, getPlot()->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::NoPen);
    bars2->setBrush(QColor(mBarColor));
    bars2->moveAbove(bars1);

    //将柱状图放在曲线之上，并将网格放在柱状图之下
    // getPlot()->addLayer() 函数添加两个新的图层
    getPlot()->addLayer("abovemain", getPlot()->layer("main"), QCustomPlot::limAbove);
    getPlot()->addLayer("belowmain", getPlot()->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    getPlot()->xAxis->grid()->setLayer("belowmain");
    getPlot()->yAxis->grid()->setLayer("belowmain");

    getPlot()->xAxis->setBasePen(QPen(Qt::white, 1));//白色，像素点为1
    getPlot()->yAxis->setBasePen(QPen(Qt::white, 1));
    getPlot()->xAxis->setTickPen(QPen(Qt::white, 1));
    getPlot()->yAxis->setTickPen(QPen(Qt::white, 1));
    getPlot()->xAxis->setSubTickPen(QPen(Qt::white, 1));
    getPlot()->yAxis->setSubTickPen(QPen(Qt::white, 1));
    getPlot()->xAxis->setTickLabelColor(Qt::white);
    getPlot()->yAxis->setTickLabelColor(Qt::white);
    getPlot()->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    getPlot()->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    getPlot()->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    getPlot()->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    getPlot()->xAxis->grid()->setSubGridVisible(true);
    getPlot()->yAxis->grid()->setSubGridVisible(true);
    getPlot()->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    getPlot()->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    getPlot()->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    getPlot()->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    getPlot()->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(50, 50, 50));
    getPlot()->axisRect()->setBackground(axisRectGradient);

    getPlot()->rescaleAxes();
    getPlot()->yAxis->setRange(0, 2);

    connect(getPlot(), &QCustomPlot::afterReplot, this, &CustomPlotBarItem::onCustomReplot);

    getPlot()->replot();
}

QColor CustomPlotBarItem::barColor()
{
    return mBarColor;
}

void CustomPlotBarItem::setBarColor(const QColor &color)
{
    mBarColor = color;
    if(getPlot())
    {
        getPlot()->replot();
    }
}

///////////////////////////////
/// \brief CustomKLine::CustomKLine
/// \param parent
///
CustomKLine::CustomKLine(QQuickItem *parent) : SlQmlCustomPlot(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void CustomKLine::initCustomPlot()
{
    updateCustomPlotSize();
    QCustomPlot *plot = getPlot();
    plot->legend->setVisible(true);

    //生成两组随机游走数据（一组用于烛台，一组用于 ohlc 图表）：
    int n = 500;
    QVector<double> time(n), value1(n), value2(n);
    QDateTime start = QDateTime(QDate(2014, 6, 11));
    start.setTimeSpec(Qt::UTC);
    double startTime = start.toTime_t();
    double binSize = 3600*24;
    time[0] = startTime;
    value1[0] = 60;
    value2[0] = 20;
    qsrand(9);
    for (int i = 1; i < n; ++i)
    {
        time[i] = startTime + 3600 * i;
        value1[i] = value1[i - 1] + (qrand() / (double)RAND_MAX - 0.5) * 10;
        value2[i] = value2[i - 1] + (qrand() / (double)RAND_MAX - 0.5) * 3;
    }

    //创建一个candlestick图表
    QCPFinancial *candlesticks = new QCPFinancial(plot->xAxis, plot->yAxis);
    candlesticks->setName("Candlestick");
    candlesticks->setChartStyle(QCPFinancial::csCandlestick);
    candlesticks->data()->set(QCPFinancial::timeSeriesToOhlc(time, value1, binSize, startTime));
    candlesticks->setWidth(binSize*0.9);
    candlesticks->setTwoColored(true);
    candlesticks->setBrushPositive(QColor(245, 245, 245));
    candlesticks->setBrushNegative(QColor(40, 40, 40));
    candlesticks->setPenPositive(QPen(QColor(0, 0, 0)));
    candlesticks->setPenNegative(QPen(QColor(0, 0, 0)));

    //创建ohlc图表
    QCPFinancial *ohlc = new QCPFinancial(plot->xAxis, plot->yAxis);
    ohlc->setName("OHLC");
    ohlc->setChartStyle(QCPFinancial::csOhlc);
    ohlc->data()->set(QCPFinancial::timeSeriesToOhlc(time, value2, binSize/3.0, startTime));
    ohlc->setWidth(binSize * 0.2);
    ohlc->setTwoColored(true);

    //为图表创建底层矩阵
    QCPAxisRect *volumeAxisRect = new QCPAxisRect(plot);
    plot->plotLayout()->addElement(1, 0, volumeAxisRect);
    volumeAxisRect->setMaximumSize(QSize(QWIDGETSIZE_MAX, 100));
    volumeAxisRect->axis(QCPAxis::atBottom)->setLayer("axes");
    volumeAxisRect->axis(QCPAxis::atBottom)->grid()->setLayer("grid");

    //将底部和主轴 rect 靠得更近
    plot->plotLayout()->setRowSpacing(0);
    volumeAxisRect->setAutoMargins(QCP::msLeft | QCP::msRight | QCP::msBottom);
    volumeAxisRect->setMargins(QMargins(0, 0, 0, 0));

    //创建两个条形图，用于正（绿色）和负（红色）体积条
    plot->setAutoAddPlottableToLegend(false);
    QCPBars *volumePos = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    QCPBars *volumeNeg = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    for (int i=0; i<n/5; ++i)
    {
      int v = qrand()%20000+qrand()%20000+qrand()%20000-10000*3;
      (v < 0 ? volumeNeg : volumePos)->addData(startTime+3600*5.0*i, qAbs(v)); // add data to either volumeNeg or volumePos, depending on sign of v
    }
    volumePos->setWidth(3600*4);
    volumePos->setPen(Qt::NoPen);
    volumePos->setBrush(QColor(100, 180, 110));
    volumeNeg->setWidth(3600*4);
    volumeNeg->setPen(Qt::NoPen);
    volumeNeg->setBrush(QColor(180, 90, 90));

    //互连主轴和底轴矩形的 x 轴范围
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
    connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), plot->xAxis, SLOT(setRange(QCPRange)));

    //配置主轴和底轴矩形的轴
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeSpec(Qt::UTC);//设置 dateTimeTicker 的日期时间规范为 Qt::UTC
    dateTimeTicker->setDateTimeFormat("dd. MMMM");
    volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(dateTimeTicker);
    volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
    plot->xAxis->setBasePen(Qt::NoPen);
    plot->xAxis->setTickLabels(false);
    plot->xAxis->setTicks(false);
    plot->xAxis->setTicker(dateTimeTicker);
    plot->rescaleAxes();
    plot->xAxis->scaleRange(1.025, plot->xAxis->range().center());
    plot->yAxis->scaleRange(1.1, plot->yAxis->range().center());

    //使轴矩形的左侧对齐：
    QCPMarginGroup *group = new QCPMarginGroup(plot);
    plot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight, group);
    volumeAxisRect->setMarginGroup(QCP::msLeft | QCP::msRight, group);
}


///////////////////////////////
/// \brief CustomColorMap::CustomColorMap
/// \param parent
///
CustomColorMap::CustomColorMap(QQuickItem *parent) : SlQmlCustomPlot(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void CustomColorMap::initCustomPlot()
{
    updateCustomPlotSize();

    QCustomPlot *plot = getPlot();
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    plot->axisRect()->setupFullAxesBox(true);
    plot->xAxis->setLabel("x");
    plot->yAxis->setLabel("y");

    //创建一个颜色图
    QCPColorMap *colorMap = new QCPColorMap(plot->xAxis, plot->yAxis);
    int nx = 200;
    int ny = 200;
    colorMap->data()->setSize(nx, ny);
    colorMap->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4));

    double x, y, z;
    for(int xIndex = 0; xIndex < nx; ++xIndex)
    {
        for(int yIndex = 0; yIndex < ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
            double r = 3 * qSqrt(x * x + y * y) + 1e-2;
            z = 2*x*(qCos(r+2)/r - qSin(r+2)/r);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }

    //添加一个渐变色
    QCPColorScale *colorScale = new QCPColorScale(plot);
    plot->plotLayout()->addElement(0, 1, colorScale);
    colorScale->setType(QCPAxis::atRight);
    colorMap->setColorScale(colorScale);
    colorScale->axis()->setLabel("Magnetic Field Strength");

    //设置 colorMap 的渐变，使其呈现极坐标颜色映射效果
    colorMap->setGradient(QCPColorGradient::gpPolar);

    colorMap->rescaleDataRange();

    QCPMarginGroup *marginGroup = new QCPMarginGroup(plot);
    plot->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);

    plot->rescaleAxes();
}

void CustomBarChart::iniCustomPlot()
{
    updateCustomPlotSize();
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));

    QCustomPlot *plot = getPlot();
    plot->setBackground(QBrush(gradient));

    //创造一个空的条形矩形对象
    QCPBars *regen = new QCPBars(plot->xAxis, plot->yAxis);
    QCPBars *nuclear = new QCPBars(plot->xAxis, plot->yAxis);
    QCPBars *fossil = new QCPBars(plot->xAxis, plot->yAxis);
    regen->setAntialiased(false);//关闭抗锯齿功能，提供更清晰、像素对齐的条形边框
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);//设置了堆积条之间的间隔为 1 个像素
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);

    //设置名字和颜色
    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));

    //堆叠条彼此叠加
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    //准备带有标签的 x 轴
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    plot->xAxis->setTicker(textTicker);
    plot->xAxis->setTickLabelRotation(60);
    plot->xAxis->setSubTicks(false);
    plot->xAxis->setTickLength(0, 4);
    plot->xAxis->setRange(0, 8);
    plot->xAxis->setBasePen(QPen(Qt::white));
    plot->xAxis->setTickPen(QPen(Qt::white));
    plot->xAxis->grid()->setVisible(true);
    plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    plot->yAxis->setRange(0, 12.1);
    plot->yAxis->setPadding(5); // a bit more space to the left border
    plot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    plot->yAxis->setBasePen(QPen(Qt::white));
    plot->yAxis->setTickPen(QPen(Qt::white));
    plot->yAxis->setSubTickPen(QPen(Qt::white));
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);
    plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
    nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    plot->legend->setVisible(true);
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    plot->legend->setBrush(QColor(255, 255, 255, 100));
    plot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = qApp->font();
    legendFont.setPointSize(10);
    plot->legend->setFont(legendFont);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}










