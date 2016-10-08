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

    property var formController: global_mainWorker.mainFormController

    property var imagesProvider: formController.imagesProvider

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
                height: proceedButton.implicitHeight
                ToolButton {
                    id: proceedButton
                    text: "Proceed"
                    width: parent.width
                }
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

            readonly property int containsAmount: 6
            readonly property int delegateHeight: height / containsAmount

            delegate: SwipeDelegate {
                id: delRoot
                width: parent.width
                height: selectedPhotosView.delegateHeight
                text: modelData.title
                onClicked: if (swipe.complete) formController.removePhoto(index)
//                highlighted: ListView.isCurrentItem

//                ListView.onRemove: SequentialAnimation {
//                    PropertyAction {
//                        target: delRoot
//                        property: "ListView.delayRemove"
//                        value: true
//                    }
//                    NumberAnimation {
//                        target: delRoot
//                        property: "height"
//                        to: 0
//                        easing.type: Easing.InOutQuad
//                    }
//                    PropertyAction {
//                        target: delRoot
//                        property: "ListView.delayRemove"
//                        value: false
//                    }
//                }

                contentItem: Item{
                    RowLayout {
                        width: delRoot.width - 2 * (ScriptStyles.commonMargins * global_scale_factor)
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: 20 * global_scale_factor
//                        height: 70 * global_scale_factor
                        height: parent.height
                        Item{
                            id: imItem
                            Layout.fillWidth: true
                            anchors.bottom: parent.bottom
                            anchors.top: parent.top

                            Image{
                                id: dImage
                                cache: false
                                fillMode: Image.PreserveAspectFit
                                source: modelData.imagePath
                                //                            horizontalAlignment: Image.AlignHCenter
                                verticalAlignment: Image.AlignVCenter
                                sourceSize.height: parent.height
                                anchors.horizontalCenter: parent.horizontalCenter
//                                anchors.centerIn: parent
//                                mipmap: true
                            }
                        }
                        Item{
                            Layout.fillWidth: true
                            //                        height: parent.height

                            anchors.bottom: parent.bottom
                            anchors.top: parent.top
                            LabelPF{
                                id: imTitle
//                                width: parent.width
//                                height: parent.height
                                maximumLineCount: 1
//                                text: dImage.status === Image.Error ? qsTr("Loading error") : delRoot.text
                                text: modelData.title
//                                wrapMode: Label.WrapAnywhere
//                                elide: Label.ElideLeft
                                horizontalAlignment: Label.AlignHCenter
                                verticalAlignment: Label.AlignVCenter
                                anchors.bottom: parent.bottom
                                anchors.top: parent.top
                                anchors.fill: parent
//                                anchors.right: parent.right
//                                contentWidth: parent.width
//                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                    }
                    Behavior on x {
                        enabled: !delRoot.down
                        NumberAnimation {
                            easing.type: Easing.InOutCubic
                            duration: 400
                        }
                    }
                }

                Component {
                    id: removeComponent

                    Rectangle {
//                        color: delRoot.swipe.complete && delRoot.pressed ? "#333" : "#444"
                        color: delRoot.swipe.complete && delRoot.pressed ? global_selectedStyle.pressedColor : Material.primary
                        width: parent.width
                        height: parent.height
//                        clip: true

                        LabelPF {
                            font.pixelSize: delRoot.font.pixelSize
                            text: qsTr("Remove")
                            color: Material.background
                            anchors.centerIn: parent
                        }
                    }
                }

                swipe.behind: removeComponent
//                swipe.right: removeComponent

            }

            model: formController.photos

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

            ScrollIndicator.vertical: ScrollIndicator { }
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
                height: galleryButton.implicitHeight
                ToolButton {
                    id: galleryButton
                    text: "Gallery"
                    width: parent.width
                    onClicked: formController.morePhotos()
                }
            }
        }
    }

}
