#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initHeatMaps(ui->widget);

    ui->widget->installEventFilter(this);

    /*connect(ui->widget, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(onWidgetMouseWheel(QWheelEvent*)));*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<double> labelPositions(const QVector<QString>& labels, double offset = 0)
{
    QVector<double> result(labels.size());
    for (int i = 0; i < labels.size(); ++i)
        result[i] = i + offset;
    return result;
}

void MainWindow::initHeatMaps(QCustomPlot* customPlot)
{
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget->axisRect()->setRangeDrag(Qt::Horizontal );
    ui->widget->axisRect()->setRangeZoom(Qt::Horizontal );


    heatmap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);  // ����һ����ɫͼ
    heatmap->data()->setSize(hours.size(), days.size());   // ������ɫͼ����ά�ȣ����ڲ�ά����һ��һά���飨һ�����Ϊ��ά���飩������������Ϊ�ж��ٸ�С����
    heatmap->data()->setRange(QCPRange(0.5, hours.size() - 0.5), QCPRange(0.5, days.size() - 0.5));  // ��ɫͼ��x��y���ϵķ�Χ

    // ���������ʾ������ʹ�������ᣬ����ⲿ�ֻ�������뿴 QCustomPlot֮���Ի���ۣ��������½�
    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
    QSharedPointer<QCPAxisTickerText> yTicker(new QCPAxisTickerText);
    xTicker->setTicks(labelPositions(hours, 0.5), hours);
    yTicker->setTicks(labelPositions(days, 0.5), days);
    xTicker->setSubTickCount(1);
    yTicker->setSubTickCount(1);
    customPlot->xAxis->setTicker(xTicker);
    customPlot->yAxis->setTicker(yTicker);
    customPlot->xAxis->grid()->setPen(Qt::NoPen);
    customPlot->yAxis->grid()->setPen(Qt::NoPen);
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->setSubTicks(true);
    customPlot->yAxis->setSubTicks(true);
    customPlot->xAxis->setTickLength(0);
    customPlot->yAxis->setTickLength(0);
    customPlot->xAxis->setSubTickLength(6);
    customPlot->yAxis->setSubTickLength(6);
    customPlot->xAxis->setRange(hours.size() - m_visibleLabels, hours.size());
    customPlot->yAxis->setRange(0, days.size());


    QCPColorScale* colorScale = new QCPColorScale(customPlot);  // ����һ��ɫ��
    colorScale->setType(QCPAxis::atBottom);   // ˮƽ��ʾ
    customPlot->plotLayout()->addElement(1, 0, colorScale); // ����ɫͼ������ʾ
    heatmap->setColorScale(colorScale);
    QCPColorGradient gradient;  // ɫ��ʹ�õ���ɫ����
    gradient.setColorStopAt(0.0, QColor("#f6efa6"));   // ����ɫ����ʼʱ����ɫ
    gradient.setColorStopAt(1.0, QColor("#bf444c"));  // ����ɫ������ʱ����ɫ
    heatmap->setGradient(gradient);
    //    colorMap->rescaleDataRange();        // �Զ��������ݷ�Χ�����ݷ�Χ��������Щ����ֵӳ�䵽QCPColorGradient����ɫ���䵱��
    heatmap->setDataRange(QCPRange(0, 10));     // Ϊ�˱�����echart������һ�£����������ֶ��������ݷ�Χ
    heatmap->setInterpolate(false);         // Ϊ����ʾС���飬���ǽ��ò�ֵ

    // ����ɫ��������α߾�һ��
    QCPMarginGroup* marginGroup = new QCPMarginGroup(customPlot);
    customPlot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
    colorScale->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);

    
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() <<"pushbutton is clicked"<< endl;
    
    //������
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QVector<double> trynumbers;
    for (int i = 0; i < 10; i++)
    {
        trynumbers.append(qrand() % 10);
    }
    myArray.prepend(trynumbers);
 
    heatmap->data()->setSize(hours.size(), days.size());   // ������ɫͼ����ά�ȣ����ڲ�ά����һ��һά���飨һ�����Ϊ��ά���飩������������Ϊ�ж��ٸ�С����
    heatmap->data()->setKeyRange(QCPRange(0.5, hours.size() - 0.5));
    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
    xTicker->setTicks(labelPositions(hours, 0.5), hours);
    xTicker->setSubTickCount(1);
    ui->widget->xAxis->setTicker(xTicker);
    ui->widget->xAxis->grid()->setPen(Qt::NoPen);
    ui->widget->xAxis->grid()->setSubGridVisible(true);
    ui->widget->xAxis->setSubTicks(true);
    ui->widget->xAxis->setTickLength(0);
    ui->widget->xAxis->setSubTickLength(6);
    ui->widget->xAxis->setRange(0, hours.size());

    for (int i = 0; i < m_px; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int z = myArray[i][j];
            if (z)
                heatmap->data()->setCell(m_px - 1 - i, j, z);  // Change this line
            else
                heatmap->data()->setAlpha(m_px - 1 - i, j, 0); // Change this line
        }

    }

    ++m_px;
    hours.append(QString::number(m_px));
    updateXAxisSpacing();

    ui->widget->replot();

}

void MainWindow::updateXAxisSpacing()
{
    QVector<double> positions;
    QVector<QString> labels;
    int skip = qMax(1, hours.size() / m_visibleLabels);
    for (int i = 0; i < hours.size(); i += skip)
    {
        positions.append(i + 0.5);
        labels.append(hours.at(i));
    }

    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
    xTicker->setTicks(positions, labels);
    xTicker->setSubTickCount(1);
    ui->widget->xAxis->setTicker(xTicker);
}


void MainWindow::onWidgetMouseWheel(QWheelEvent* event)
{
    qDebug() << "onWidgetMouseWheel is running" << endl;
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    int newVisibleLabels = m_visibleLabels + numSteps; // Change the sign to +
    newVisibleLabels = qBound(1, newVisibleLabels, hours.size());

    if (newVisibleLabels != m_visibleLabels)
    {
        m_visibleLabels = newVisibleLabels;
        ui->widget->xAxis->range();
        updateXAxisSpacing();
        ui->widget->replot();
    }
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == ui->widget && event->type() == QEvent::Wheel)
    {
        // Call onWidgetMouseWheel function when a WheelEvent is intercepted
        onWidgetMouseWheel(static_cast<QWheelEvent*>(event));

        // Let QCustomPlot handle the event to perform its default zoom functionality
        return QMainWindow::eventFilter(obj, event);
    }
    else
    {
        // Standard event processing
        return QMainWindow::eventFilter(obj, event);
    }
}
