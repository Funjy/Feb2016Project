import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Dialogs 1.2

import "myScripts/Styles.js" as ScriptStyles
import "myControls"

import ca.riftekit.Controllers 1.0
//import ca.riftekit.Behaviours 1.0

Page {
    id: root
    title: global_appTitle

//    property MainFormController formController: global_mainWorker.mainFormController

    property var imagesProvider: global_mainWorker.mainFormController.imagesProvider

    header: ToolBar {

        Material.primary: "white"

        RowLayout {
            spacing: 20 * global_scale_factor
            anchors.fill: parent

            ToolButton {
                id: menuButton
                contentItem: Item {
                    height: 40 * global_scale_factor
                    width: 40 * global_scale_factor
                    Image {
                        id: menuImage
                        fillMode: Image.PreserveAspectFit
                        horizontalAlignment: Image.AlignHCenter
                        verticalAlignment: Image.AlignVCenter
                        source: "qrc:/images/close-128.png"
                        anchors.fill: parent
                    }
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
        anchors.margins: ScriptStyles.commonMargins * global_scale_factor

        ListView{
            id: selectedPhotosView
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: -1

            delegate: SwipeDelegate {
                id: delRoot
                width: parent.width
                text: modelData.title
                highlighted: ListView.isCurrentItem

                contentItem: RowLayout {
                    width: delRoot.width - 2 * (ScriptStyles.commonMargins * global_scale_factor)
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 20 * global_scale_factor
                    Item{
                        Layout.fillWidth: true
                        height: 70 * global_scale_factor
                        Image{
                            id: dImage
                            fillMode: Image.PreserveAspectFit
                            source: modelData.imagePath
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            sourceSize.height: parent.height
//                            anchors.fill: parent
                        }
                    }
                    Item{
                        Layout.fillWidth: true
                        implicitHeight: parent.height
                        LabelPF{
                            id: imTitle
                            width: parent.width
                            maximumLineCount: 1
                            text: dImage.status === Image.Error ? qsTr("Loading error") : delRoot.text
//                            wrapMode: Label.WrapAnywhere
                            elide: Label.ElideMiddle
                            horizontalAlignment: Label.AlignHCenter
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }

                }

            }

            model: global_mainWorker.mainFormController.photos

//            model: ListModel{
//                ListElement{
//                    source: "file:/C:/Users/Antony/Pictures/fOq9QNU.jpg"
//                    title: "Halo"
//                }
//                ListElement{
//                    source: "file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg"
//                    title:  "file:/C:/Users/Antony/Pictures/temporal_flux_wallpaper_version_by_magicnaanavi-d671cua.jpg"
//                }
//            }
        }

    }

    footer: ToolBar{
        Material.primary: "white"
        RowLayout{
            spacing: 20 * global_scale_factor
            anchors.fill: parent

            Item{
                Layout.fillWidth: true
                height: cameraButton.implicitHeight
                ToolButton {
                    id: cameraButton
                    text: "Camera"
                    width: parent.width
                    onClicked: root.imagesProvider.openCamera()
                }
            }

            Item{
                Layout.fillWidth: true
                height: nextButton.implicitHeight
                ToolButton {
                    id: nextButton
                    text: "Next"
                    width: parent.width
                }
            }
        }
    }

}
