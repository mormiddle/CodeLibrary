// SLResizeBorder.qml
import QtQuick 2.7

Rectangle {
    id: root
    color: "transparent"
    border.width: 4
    border.color: "black"
    width: parent.width
    height: parent.height
    property var control: parent
    SLDragRect {
        posType: posLeftTop
        onPosChange: {
            //不要简化这个判断条件，至少让以后维护的人能看懂。化简过后我自己都看不懂了。
            if (control.x + xOffset < control.x + control.width)
                control.x += xOffset;
            if (control.y + yOffset < control.y + control.height)
                control.y += yOffset;
            if (control.width - xOffset > 0)
                control.width-= xOffset;
            if (control.height -yOffset > 0)
                control.height -= yOffset;
        }
    }
    SLDragRect {
        posType: posMidTop
        x: (parent.width - width) / 2
        onPosChange: {
            if (control.y + yOffset < control.y + control.height)
                control.y += yOffset;
            if (control.height - yOffset > 0)
                control.height -= yOffset;
        }
    }
    SLDragRect {
        posType: posRightTop
        x: parent.width - width
        onPosChange: {
            //向左拖动时，xOffset为负数
            if (control.width + xOffset > 0)
                control.width += xOffset;
            if (control.height - yOffset > 0)
                control.height -= yOffset;
            if (control.y + yOffset < control.y + control.height)
                control.y += yOffset;
        }
    }
    SLDragRect {
        posType: posLeftMid
        y: (parent.height - height) / 2
        onPosChange: {
            if (control.x + xOffset < control.x + control.width)
                control.x += xOffset;
            if (control.width - xOffset > 0)
                control.width-= xOffset;
        }
    }
    SLDragRect {
        posType: posRightMid
        x: parent.width - width
        y: (parent.height - height) / 2
        onPosChange: {
            if (control.width + xOffset > 0)
                control.width += xOffset;
        }
    }
    SLDragRect {
        posType: posLeftBottom
        y: parent.height - height
        onPosChange: {
            if (control.x + xOffset < control.x + control.width)
                control.x += xOffset;
            if (control.width - xOffset > 0)
                control.width-= xOffset;
            if (control.height + yOffset > 0)
                control.height += yOffset;
        }
    }
    SLDragRect {
        posType: posMidBottom
        x: (parent.width - width) / 2
        y: parent.height - height
        onPosChange: {
            if (control.height + yOffset > 0)
                control.height += yOffset;
        }
    }
    SLDragRect {
        posType: posRightBottom
        x: parent.width - width
        y: parent.height - height
        onPosChange: {
            if (control.width + xOffset > 0)
                control.width += xOffset;
            if (control.height + yOffset > 0)
                control.height += yOffset;
        }
    }
}
