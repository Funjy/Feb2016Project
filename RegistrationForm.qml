import QtQuick 2.4

Item {
    anchors.left: parent.left
    anchors.right: parent.right

    height: 212

    BorderImage {
        id: bImage
        source: "qrc:/images/window-header-w-shadow.png"
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
        anchors.fill: parent
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
            source: "qrc:/images/close.svg"
            verticalAlignment: Image.AlignVCenter
            horizontalAlignment: Image.AlignHCenter
        }
    }

    Text{
        anchors.left: closeItem.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        font.pointSize: 56
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Header"
    }
}
