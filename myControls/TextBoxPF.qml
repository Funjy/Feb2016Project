import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

import "../myScripts/Styles.js" as ScriptStyles

Rectangle {

    color: "orange"
    property alias text: textBox.text

    anchors.left: parent.left
    anchors.right: parent.right
    implicitHeight: global_scale_factor * 140

    TextInput{
        id: textBox
        clip: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 10 * global_scale_factor
        font.family: ScriptStyles.DefaultStyle.textInputFont

    }

}
