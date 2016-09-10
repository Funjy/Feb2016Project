import QtQuick 2.5
import QtQuick.Layouts 1.3

import "qrc:/Material"
import Material 0.3

Page {
    id: root
    title: "PhotoFly"

    backAction: navDrawer.action
    property list<Action> menuList

    NavigationDrawer {
        id: navDrawer
        Flickable {
            anchors.fill: parent

            contentHeight: Math.max(content.implicitHeight, height)

            Column {
                id: content
                anchors.fill: parent
                spacing: 20 * global_scale_factor

                Item{
                    height: 1
                    anchors.left: parent.left
                    anchors.right: parent.right
                }

                Rectangle{
                    color: Theme.tabHighlightColor
                    height: 160 * global_scale_factor
                    anchors.left: parent.left
                    anchors.right: parent.right
                    Row{
                        anchors.fill: parent
                        spacing: 16 * global_scale_factor
                        Icon{
                            name: "navigation/more_vert"
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Label{
                            text: "Anton Kustou"
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 32 * global_scale_factor
                        }
                    }
                }

                ThinDivider { }

                Repeater {
                    model: root.menuList.length
                    Button{
                        id: menuButton
                        implicitHeight: 60 * global_scale_factor

                        text: action.name
                        enabled: action.enabled

                        property Action action: root.menuList[index]

                        onClicked: {
                            action.trigger(menuButton)
                            navDrawer.close()
                        }
                    }
                }
            }
        }

    }

    GridLayout{
        columns: 1
        anchors.fill: parent
        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            Layout.fillHeight: true

            AwesomeIcon{
                name: "image"
                anchors.centerIn: parent
                size: parent.height / 2
                Ink {
                    anchors.fill: parent
                    onClicked: mainWorker.selectImageFromGallery()
                }
            }


        }
        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            Layout.fillHeight: true
            AwesomeIcon{
                name: "camera"
                anchors.centerIn: parent
                size: parent.height / 2
                Ink {
                    anchors.fill: parent
                    onClicked: mainWorker.openCamera()
                }
            }
        }
    }
}
