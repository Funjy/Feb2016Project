import QtQuick 2.4
import QtQuick.Window 2.2

import "../myScripts/Styles.js" as ScriptStyles

Item {
    id: root
//    anchors.top: parent.top
//    anchors.left: parent.left
//    anchors.right: parent.right

//    height: Screen.height * 0.12
    implicitHeight: Screen.height * 0.12 + shadowHeight

    property double shadowHeight: 60
    property alias text: textItem.text

    signal backClicked()

    BorderImage {
        id: bImage
        source: "qrc:/images/window-header-w-shadow.png"
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: root.shadowHeight
        anchors.fill: parent
        anchors.bottomMargin: -root.shadowHeight
        property double dif: (60/152)*root.height
    }

    Item{
        id: closeItem
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height
        MouseArea{
            anchors.fill: parent
            onClicked: root.backClicked()
        }

        Image{
            fillMode: Image.Pad
            anchors.centerIn: parent
            mipmap: true
            height: Screen.height * 0.06
            width: height
            source: "qrc:/images/close.svg"
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
        text: "Header "// + root.height + " : " + bImage.dif.toFixed(1)
        font.family: ScriptStyles.DefaultStyle.headerFont
        font.weight: Font.Bold
    }

}
