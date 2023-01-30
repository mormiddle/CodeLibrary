import QtQuick 2.12
import QtQuick.Controls 2.5

Item {


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


    SLImageBtn {
        id: imagBtn1
        x: 100
        width: 50
        height: 50
        normalUrl: "qrc:/emotion-happy.png"
        hoveredUrl: "qrc:/smiling-face.png"
        pressedUrl: "qrc:/upside-down-face.png"
        disabledUrl: "qrc:/worried-face.png"
        property color btnColor : "#009688"
    }

    SLImgTextBtn {
        x: imagBtn1.x + 70
        width: 100
        height: 100
        text: qsTr("文本按钮")
        normalUrl: "qrc:/emotion-happy.png"
        hoveredUrl: "qrc:/smiling-face.png"
        pressedUrl: "qrc:/upside-down-face.png"
        disabledUrl: "qrc:/worried-face.png"
        imageWidth: 20
        imageHeight: 20
    }
}
