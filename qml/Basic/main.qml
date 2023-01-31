import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
            x: 100
            y: 200
            width: 400
            height: 300
            color: "darkred"
            //实例化一个MoveArea
            SLMoveArea {
                //指定control为parent。 其实默认就是parent，写出来示意一下
                control: parent
                anchors.fill: parent
            }

            SLResizeBorder {
                control: parent     //默认就是parent，可以不写。这里写出来示意一下。
                anchors.fill: parent

            }
        }
}
