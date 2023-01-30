import QtQuick 2.12
import QtQuick.Controls 2.5

Item {
    width: 800
    height: 600

    SLTextBtn {
        width: 80
        height: 40
        text: qsTr("文本按钮")
        property color btnColor : "#009688"
        color: containsPress ? Qt.darker(btnColor, 1.2) : (containsMouse ? Qt.lighter(btnColor, 1.2) : btnColor)
        onClicked: {
            console.log("按下了按钮")
        }
    }
}
