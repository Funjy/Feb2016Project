import QtQuick 2.0

Item{
    id: root
    anchors.fill: parent
    opacity: 0
    enabled: opacity === 1
    visible: opacity !== 0

    default property var messageComponent: undefined

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
        id: loader
        anchors.fill: parent
        sourceComponent: root.messageComponent

        Binding{
            target: loader.item
            property: "anchors.left"
            value: loader.left
        }
        Binding{
            target: loader.item
            property: "anchors.right"
            value: loader.right
        }
        Binding{
            target: loader.item
            property: "anchors.verticalCenter"
            value: loader.verticalCenter
        }
    }

    Behavior on opacity { NumberAnimation{}}

    function show(){
        opacity = 1
    }
    function hide(){
        opacity = 0
    }
}
