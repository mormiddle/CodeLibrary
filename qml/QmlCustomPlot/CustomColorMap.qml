import QtQuick 2.0
import CustomPlot 1.0

Item {
    CustomColorMap {
        id: customColorMap
        anchors.fill: parent
        Component.onCompleted: customColorMap.initCustomPlot()
    }

    Text {
        id: text
        text: qsTr("CustomColorMap Form")
    }
}
