import QtQuick 2.4
import "qrc:/myControls"

Rectangle {
    height: 315 * global_scale_factor
    anchors.left: parent.left
    anchors.right: parent.right
    color: "white"

    Item{
        anchors.fill: parent
        anchors.margins: 20 * global_scale_factor
        LabelPF{
            text: qsTr("Successful registration!")
            font.pixelSize: 40 * global_scale_factor
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter
        }

        LabelPF{
            text: qsTr("You can now take pictures or select them from gallery to send.")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.verticalCenter
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }
    }

}
