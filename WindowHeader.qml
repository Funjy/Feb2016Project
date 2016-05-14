import QtQuick 2.4
import QtQuick.Window 2.2

import "Styles.js" as ScriptStyles

Item {
    id: root
    anchors.left: parent.left
    anchors.right: parent.right

//    height: 152
    height: Screen.height * 0.1


//    property int fullHeight: 212
//    property int noShadowHeight: 152

    property int shadowHeight: 60

    property alias text: textItem.text

    BorderImage {
        id: bImage
        height: root.height + root.shadowHeight
        source: "qrc:/images/window-header-w-shadow.png"
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    Item{
        id: closeItem
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height
        Image{
            fillMode: Image.Pad
            anchors.fill: parent
            source: "qrc:/images/cross-128.png"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Text{
        id: textItem
//        anchors.left: closeItem.right
//        anchors.right: parent.right
//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
        anchors.fill: parent
        font.pointSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Header"
        font.family: ScriptStyles.DefaultStyle.headerFont
    }
}
