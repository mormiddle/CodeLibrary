#include <QtPrintSupport/QPrinter>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "slqmlcustomplot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<CustomPlotItem>("CustomPlot", 1, 0, "CustomPlotItem");
    qmlRegisterType<CustomPlotBarItem>("CustomPlot", 1, 0, "CustomPlotBarItem");
    qmlRegisterType<CustomKLine>("CustomPlot", 1, 0, "CustomKLine");
    qmlRegisterType<CustomColorMap>("CustomPlot", 1, 0, "CustomColorMap");
    qmlRegisterType<CustomBarChart>("CustomPlot", 1, 0, "CustomBarChart");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
