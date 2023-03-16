#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initHeatMaps(QCustomPlot* customPlot);
    void updateXAxisSpacing();//更新x轴可见范围
    void onWidgetMouseWheel(QWheelEvent* event);//设置滚轮所发和拖拽

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCPColorMap* heatmap;
    int m_px = 0;
    int m_py = 0;
    QVector<QString> hours ;
    QVector<QString> days = { "通道1", "通道2", "通道3","通道4", "通道5",
                            "通道6", "通道7", "通道8", "通道9", "通道10" };
    QVector<QVector<double>> myArray;
    int m_psetupPlot = 0;
    int m_visibleLabels = 10;//x轴可见范围
    int m_minSpacing = 1;

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;


};
#endif // MAINWINDOW_H
