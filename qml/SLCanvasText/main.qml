import QtQuick 2.12
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Canvas {
        id: canvas
        width: 300
        height: 100
        onPaint: {
            var ctx = getContext("2d")
            ctx.fillStyle = "red"
            ctx.font = fontMetrics.getFontToContext2D()

            ctx.beginPath()
            ctx.text(qsTr("Canvas 这是一段文字"), 20, 40)
            ctx.fill()
        }
    }

    Text {
        id: text
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 60
        font: fontMetrics.font
        color: "red"
        text: qsTr("text")
    }

    //自定义字体
    FontMetrics {
        id: fontMetrics
        font.family: "Microsoft Yahei"
        font.pixelSize: 16
        font.italic: false
        font.bold: false

        //该函数从对象“fontMetrics”中获取字体属性(粗体、斜体、像素大小和家族)。
        //并创建一个由函数返回的CSS字体字符串。
        function getFontToContext2D() {
            var cssFontString = "";
            if (fontMetrics.font.italic) {
                cssFontString += "italic";
            }
            else {
                cssFontString += "normal";
            }

            if(fontMetrics.font.bold) {
                cssFontString += "bold ";
            } else {
                cssFontString += "normal ";
            }

            cssFontString += (fontMetrics.font.pixelSize+"px ");
            cssFontString += fontMetrics.font.family;
            return cssFontString;
        }
    }
}
