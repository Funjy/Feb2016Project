import QtQuick 2.0

Item{
    id: root
    anchors.fill: parent
    opacity: 0
    enabled: opacity === 1
    visible: opacity !== 0

    property var messageComponent: undefined

    Rectangle{
        anchors.fill: parent
        opacity: 0.6
        color: "black"
        MouseArea{
            anchors.fill: parent
            onClicked: root.hide()
        }
    }

    Loader{
        anchors.fill: parent
        sourceComponent: root.messageComponent
    }

    Behavior on opacity { NumberAnimation{}}

    function show(){
        opacity = 1
    }
    function hide(){
        opacity = 0
    }
}
