import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
//import QtQuick.Controls.Styles 1.4
//import QtQuick.Window 2.2
//import Material 0.3

import "myControls"
//import "qrc:/Material"
import ca.riftekit.Containers 1.0

Page{
    id: root
    title: "Registration"

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
        backClicked()
    }

    GridLayout{
        anchors.fill: parent
        anchors.margins: Math.min(parent.width, parent.height) * 0.05
        columns: 1
        clip: true

        SwipeView {
            id: swipeView
            Layout.fillHeight: true
            anchors.left: parent.left
            anchors.right: parent.right
            currentIndex: tabBar.currentIndex

            Pane{
                width: swipeView.width
                height: swipeView.height

                function buildData(){
                    var rData = Qt.createQmlObject("import ca.riftekit.Containers 1.0; RegistrationFormData {}", this)
                    rData.email = loginEmail.text
                    rData.password = loginPassword.text
                    rData.sourceForm = RegistrationFormData.SF_Login
                    return rData
//                    registrationData.email = loginEmail.text
//                    registrationData.password = loginPassword.text
                }

                GridLayout{
//                    anchors.centerIn: parent
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    columns: 1
                    rowSpacing: 16 * global_scale_factor

                    TextFieldWithLabel{
                        id: loginEmail
                        title: qsTr("Email address")
                        expandWidth: true
                    }

                    TextFieldWithLabel{
                        id: loginPassword
                        title: qsTr("Password")
                        expandWidth: true
                    }

                }

            }

            Pane{
                width: swipeView.width
                height: swipeView.height

                function buildData(){
                    var rData = Qt.createQmlObject("import ca.riftekit.Containers 1.0; RegistrationFormData {}", this)
                    rData.name = registerName.text
                    rData.email = registerEmail.text
                    rData.password = registerPassword.text
                    rData.sourceForm = RegistrationFormData.SF_Registration
                    return rData
//                    registrationData.name = registerName.text
//                    registrationData.email = registerEmail.text
//                    registrationData.password = registerPassword.text
                }

                GridLayout{
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    columns: 1
                    rowSpacing: 16 * global_scale_factor

                    TextFieldWithLabel{
                        id: registerName
                        title: qsTr("Name")
                        expandWidth: true
                    }

                    TextFieldWithLabel{
                        id: registerEmail
                        title: qsTr("Email address")
                        expandWidth: true
                    }

                    TextFieldWithLabel{
                        id: registerPassword
                        title: qsTr("Password")
                        expandWidth: true
                    }

//                    Item{
//                        Layout.fillHeight: true
//                    }

                }
            }

        }

        GridLayout{
//            ButtonPF{
//                id: skipButton
//                visible: root.firstLaunch
//                text: "Skip"
//                Layout.fillWidth: true
//                onClicked: backClicked()
//            }
            ButtonPF{
                id: acceptButton
                text: "Accept"
                highlighted: true
                Layout.fillWidth: true
                onClicked: {

                    var rData = swipeView.currentItem.buildData()

                    global_mainWorker.testFunc(rData)

                    rData.destroy()

//                    sucRes.open()
                }
            }
        }
    }

//    RegistrationFormData{
//        id: registrationData
//    }

    PopupPF{
        id: sucRes
        width: root.width
        height: sucResColumn.height + topPadding + bottomPadding

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
