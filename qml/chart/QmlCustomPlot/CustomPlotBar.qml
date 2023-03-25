import QtQuick 2.0
import CustomPlot 1.0

Item {
    CustomPlotBarItem {
        id: customPlotBar
        anchors.fill: parent
        barColor: "#00ff00"
        Component.onCompleted: customPlotBar.initCustomPlot()
    }

    Text {
        id: text
        text: qsTr("CustomPlotBar Form")
    }
}
