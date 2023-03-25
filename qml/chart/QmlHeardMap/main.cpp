#include <QtPrintSupport/QPrinter>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "slqmlcustomplot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<CustomColorMap>("CustomPlot", 1, 0, "CustomColorMap");
    qmlRegisterType<SlQmlCustomPlot>("SlQmlCustomPlot", 1, 0, "SlQmlCustomPlot");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}
