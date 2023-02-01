import QtQuick 2.12
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BusyIndicator {
        id: busyIndicator
        anchors.centerIn: parent
        implicitWidth: 96
        implicitHeight: 96
        opacity: running ? 0.0 : 1.0
        contentItem: SLBusyIndicator{}
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            busyIndicator.running = !busyIndicator.running
        }
    }
}
