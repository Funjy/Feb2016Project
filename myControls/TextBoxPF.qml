import QtQuick 2.4
import QtQuick.Layouts 1.3

import "../myScripts/Styles.js" as ScriptStyles

Rectangle {

    color: "orange"
    property alias text: textBox.text

    implicitHeight: global_scale_factor * 40
    anchors.left: parent.left
    anchors.right: parent.right
    property int marginValue: parent.width * 0.1
    anchors.leftMargin: marginValue
    anchors.rightMargin: marginValue

    TextInput{
        id: textBox
        anchors.fill: parent
        anchors.margins: 4
        font.family: ScriptStyles.DefaultStyle.textInputFont
    }

}
