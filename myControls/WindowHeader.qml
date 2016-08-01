import QtQuick 2.4
import QtQuick.Window 2.2

import "../myScripts/Styles.js" as ScriptStyles

Item {
    id: root
//    anchors.top: parent.top
//    anchors.left: parent.left
//    anchors.right: parent.right

//    height: Screen.height * 0.12
//    implicitHeight: Screen.height * 0.1 + shadowHeight

    property bool showNextButton: false

    property int height_no_shadow: 150*global_scale_factor
    implicitHeight: height_no_shadow + shadowHeight

//    property double shadowHeight: 60
    property double shadowHeight: 24*global_scale_factor
    property alias text: textItem.text

    signal backClicked()

    onBackClicked: stack.pop()

    BorderImage {
        id: bImage
        source: "qrc:/images/window-header-w-shadow.png"
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: root.shadowHeight
        anchors.fill: parent
        anchors.bottomMargin: -root.shadowHeight
//        property double dif: (60/152)*root.height
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
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            mipmap: true
//            height: Screen.height * 0.06
            height: 30 * global_scale_factor
            width: height
            source: "qrc:/images/close.svg"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter            
        }
    }

    Text{
        id: textItem
        anchors.fill: parent
//        font.pixelSize: Screen.height * 0.06
        font.pixelSize: 40 * global_scale_factor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Header "// + root.height + " : " + bImage.dif.toFixed(1)
        font.family: ScriptStyles.DefaultStyle.headerFont
        font.weight: Font.Bold
    }

    ClickableImage{
        visible: root.showNextButton
        enabled: visible
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height
        iconSource: "qrc:/images/close.svg"
//        text:
    }


}
