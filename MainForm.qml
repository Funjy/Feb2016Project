import QtQuick 2.0

Rectangle {
    id: rectangle1

    width: 300
    height: 300
    property alias mouseArea1: mouseArea1
    property alias text1: text1

    Column {
        id: testGetImageItem
//        opacity: 1
//        enabled: false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: rectangle2
            width: 300
            height: 300
            color: mouseArea1.pressed ? "orange" : "cyan"

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
            }
        }
        Text {
            id: text1
            text: qsTr("Text")
            font.pointSize: 16
        }
    }

}
