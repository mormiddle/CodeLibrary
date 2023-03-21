import QtQuick 2.0
import CustomPlot 1.0

Item {
    CustomKLine {
        id: customKLine
        anchors.fill:parent
        Component.onCompleted: customKLine.initCustomPlot()
    }

    Text {
        id: text
        text: qsTr("CustomKLine Form")
    }
}
