import QtQuick 2.4
import QtQuick.Window 2.2

import "Styles.js" as ScriptStyles

Item {
    id: root
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right

    height: Screen.height * 0.12

    property int shadowHeight: 60
    property alias text: textItem.text

    signal bakcClicked()

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
            source: "qrc:/images/close.png"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Text{
        id: textItem
        anchors.fill: parent
        font.pixelSize: Screen.height * 0.06
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Header " + font.pixelSize
        font.family: ScriptStyles.DefaultStyle.headerFont
    }
}
