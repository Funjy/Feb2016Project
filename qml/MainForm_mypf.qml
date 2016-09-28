import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0 as Controls
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2
import Material 0.3

import "myControls"
import "qrc:/Material"
import ca.riftekit.Containers 1.0
import ca.riftekit.Workers 1.0

DefaultPanelPF {
    id: root
    title: "PHOTOFLY"
    backButtonImageSource: "qrc:/icons/navigation/menu.svg"

    onBackClicked: nav.toggle()

    NavigationDrawer{
        z: 1
        id: nav
        Flickable {
            anchors.fill: parent

            contentHeight: Math.max(content.implicitHeight, height)
            Column {
                id: content
                anchors.fill: parent

                TextField {
                    placeholderText: "Search..."
                    anchors.horizontalCenter: parent.horizontalCenter
                }

            }
        }
    }

    content: GridLayout{
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

//                    onClicked: overlayView.open(image)
                }
            }
        }
    }

}
