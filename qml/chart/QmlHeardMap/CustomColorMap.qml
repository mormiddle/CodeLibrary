﻿import QtQuick 2.0
import QtQuick.Controls 2.0
import CustomPlot 1.0

Item {
    CustomColorMap {
        id: customColorMap
        anchors.fill: parent
        Component.onCompleted: customColorMap.initCustomPlot()
    }

    Button {
        text: "test"
        onClicked: {
            customColorMap.myTestDateCreate()
        }
    }
}