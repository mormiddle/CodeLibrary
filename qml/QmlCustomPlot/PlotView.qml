import QtQuick 2.0
import CustomPlot 1.0

Item {
    id: plotForm

    CustomPlotItem {
        id: customPlot
        anchors.fill: parent
        Component.onCompleted: customPlot.initCustomPlot()
    }

    Text {
        id: text
        text: qsTr("Plot Form")
    }
}
