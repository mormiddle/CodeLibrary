import QtQuick 2.12
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.XmlListModel 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QCustomPlot在qml中的使用")

    //SwipeView一种滑动页面视图
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        interactive: false

        PlotView {

        }

        CustomPlotBar {

        }

        CustomKLine {

        }

        CustomColorMap {

        }

        CustomBarCharts {

        }
    }

    //footer: TabBar是QML中的一个元素，用于在屏幕底部显示一组标签页，每个标签页代表一个不同的页面
    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Plot")
        }
        TabButton {
            text: qsTr("Bar")
        }
        TabButton {
            text: qsTr("KLine")
        }
        TabButton {
            text: qsTr("ColorMap")
        }
        TabButton {
            text: qsTr("BarChart")
        }
    }
}
