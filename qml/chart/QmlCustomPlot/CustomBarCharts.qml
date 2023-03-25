import QtQuick 2.0
import CustomPlot 1.0

Item {
    CustomBarChart {
        id: customBar
        anchors.fill: parent
        Component.onCompleted: customBar.iniCustomPlot()
    }

    Text {
        id: text
        text: qsTr("CustomBarChart Form")
    }
}
