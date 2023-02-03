//日历

import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("SLCalender")

    function dayValid(data) {
        var myArray = new Array();
        myArray[0] = "13";
        myArray[1] = "17"
        myArray[2] = "26"

        for (var i = 0; i < myArray.length; i++)
        {
            if (myArray[i] === date)
            {
                return (false);
            }
        }
        return (true);
    }

    Calendar {
        anchors.centerIn: parent

        style: CalendarStyle {
            gridVisible: false
            dayDelegate: Rectangle {
                property bool dayIsValid: dayValid(styleData.date.getDate().toString())

                gradient: Gradient {
                    GradientStop {
                        position: 0.00
                        color: styleData.selected && dayIsValid ? "#148014" : (styleData.visibleMonth && styleData.valid ? (dayIsValid ? "#CCCCCC" : "#FFFFFF") : "#FFFFFF");
                    }
                }

                Label {
                    text: styleData.date.getDate()
                    anchors.centerIn: parent
                }

                Rectangle { //横条
                    width: parent.width
                    height: 1
                    color: "#FF4500"
                    anchors.bottom: parent.bottom
                }

                Rectangle { //纵条
                    width: 1
                    height: parent.height
                    color: "#00CED1"
                    anchors.right: parent.right
                }
            }

        }
    }
}
