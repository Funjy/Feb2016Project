import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

import ca.riftekit.Controllers 1.0

Page {
    id: root
    title: global_appTitle

    header: ToolBar {
        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                id: menuButton
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/close-128.png"
                    sourceSize.height: 40
                }
                onClicked: drawer.open()
            }

            Label {
                id: titleLabel
                text: root.title
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            Item{
                width: menuButton.width
            }

        }
    }

    Drawer {
        id: drawer
        width: Math.min(
                   Math.min(root.width, root.height) / 3 * 2,
                   listView.contentWidth)
        height: root.height

        ListView {
            id: listView
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    if (listView.currentIndex != index) {
                        listView.currentIndex = index
                        //                        titleLabel.text = model.title
                        //                        stackView.replace(model.source)
                    }
                    drawer.close()
                }
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    GridLayout{
        columns: 1
        anchors.fill: parent
//        Item {
//            anchors.left: parent.left
//            anchors.right: parent.right
//            Layout.fillHeight: true

//            AwesomeIcon{
//                name: "image"
//                anchors.centerIn: parent
//                size: parent.height / 2
//                Ink {
//                    anchors.fill: parent
//                    onClicked: mainWorker.selectImageFromGallery()
//                }
//            }


//        }
//        Item {
//            anchors.left: parent.left
//            anchors.right: parent.right
//            Layout.fillHeight: true
//            AwesomeIcon{
//                name: "camera"
//                anchors.centerIn: parent
//                size: parent.height / 2
//                Ink {
//                    anchors.fill: parent
//                    onClicked: mainWorker.openCamera()
//                }
//            }
//        }
    }

}
