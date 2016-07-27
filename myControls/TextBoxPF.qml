import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

import "../myScripts/Styles.js" as ScriptStyles

Item {

//    color: "orange"
    property alias text: textBox.text
    property alias placeHolderText: textBox.placeholderText

    anchors.left: parent.left
    anchors.right: parent.right
    implicitHeight: Math.max(global_scale_factor * 140, textBox.implicitHeight)
    activeFocusOnTab: true

//    Rectangle{
//        id: rect
//        visible: textBox.activeFocus
//        anchors.fill: parent
////        color: "transparent"
////        layer.enabled: true
////        layer.effect: DropShadow {
////            transparentBorder: true
////            verticalOffset: 12 * global_scale_factor
////            anchors.margins: 12 * global_scale_factor
////            radius: 100
////            samples: 201
////            smooth: true
////        }
//    }

    TextField{
        id: textBox
        clip: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 20 * global_scale_factor
        font.family: ScriptStyles.DefaultStyle.textInputFont
        font.pixelSize: 160 * global_scale_factor

        style: TextFieldStyle{
            background: null
        }
    }

}
