import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
//import QtQuick.Window 2.2
//import Material 0.3

import "myControls"
//import "qrc:/Material"
import ca.riftekit.Containers 1.0

Page{
    id: root
    title: "Registration"
    //    header: ToolBar {
    //        RowLayout {
    //            spacing: 20
    //            anchors.fill: parent

    //            ToolButton {
    //                id: menuButton
    //                contentItem: Image {
    //                    fillMode: Image.Pad
    //                    horizontalAlignment: Image.AlignHCenter
    //                    verticalAlignment: Image.AlignVCenter
    //                    source: "qrc:/images/close.svg"
    //                }
    //                onClicked: backClicked()
    //            }

    //            Label {
    //                id: titleLabel
    //                text: root.title
    //                font.pixelSize: 20
    //                elide: Label.ElideRight
    //                horizontalAlignment: Qt.AlignHCenter
    //                verticalAlignment: Qt.AlignVCenter
    //                Layout.fillWidth: true
    //            }

    //            Item{
    //                width: menuButton.width
    //            }

    //        }
    //    }

    header: TabBar{
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton{ text: qsTr("Login") }
        TabButton{ text: qsTr("Registration") }
    }

    property bool firstLaunch: false

    Keys.onEnterPressed: {
        acceptButton.clicked()
    }

    Keys.onEscapePressed: {
        skipButton.clicked()
    }

    GridLayout{
        anchors.fill: parent
        columns: 1

        SwipeView {
            id: swipeView
//            anchors.fill: parent
            Layout.fillHeight: true
            anchors.left: parent.left
            anchors.right: parent.right
            currentIndex: tabBar.currentIndex

            Pane{
                width: swipeView.width
                height: swipeView.height

                GridLayout{
                    anchors.centerIn: parent
                    columns: 1
                    rowSpacing: 16 * global_scale_factor

                    Column{
                        LabelPF{
                            id: emailLabel
                            text: qsTr("Email address")
                        }
                        TextBoxPF{
                            placeholderText: emailLabel.text
                        }
                    }

                    Column{
                        LabelPF{
                            id: passwordLabel
                            text: qsTr("Password")
                        }
                        TextBoxPF{
                            placeholderText: passwordLabel.text
                        }
                    }

                }

            }

            Pane{
                width: swipeView.width
                height: swipeView.height
                GridLayout{
//                    anchors.fill: parent
//                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.centerIn: parent
                    columns: 1
                    rowSpacing: 16 * global_scale_factor
                    property int marginValue: parent.width * 0.1
                    anchors.leftMargin: marginValue
                    anchors.rightMargin: marginValue

                    TextBoxPF{
                        placeholderText: qsTr("Name")
                        text: global_scale_factor
                    }

                    TextBoxPF{
                        placeholderText: qsTr("Email address")
                    }

                    TextBoxPF{
                        placeholderText: qsTr("Phone number")
                    }

                    Item{
                        Layout.fillHeight: true
                    }




                }
            }

        }

        GridLayout{
            ButtonPF{
                id: skipButton
                visible: root.firstLaunch
                text: "Skip"
                Layout.fillWidth: true
                onClicked: backClicked()
            }
            ButtonPF{
                id: acceptButton
                text: "Accept"
                highlighted: true
                Layout.fillWidth: true
                onClicked: sucRes.open()
            }
        }
    }



    RegistrationFormData{
        id: registrationData
    }

    PopupPF{
        id: sucRes
        width: root.width
        //        width: Math.min(root.width, root.height) / 3 * 2
        contentHeight: sucResColumn.height

        Column{
            id: sucResColumn
            spacing: 20

            LabelPF{
                width: sucRes.availableWidth
                text: qsTr("Successful registration!")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            LabelPF{
                width: sucRes.availableWidth
                text: qsTr("You can now take pictures or select them from gallery to send.")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

        }

    }
}
