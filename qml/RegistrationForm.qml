import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
//import QtQuick.Controls.Styles 1.4
//import QtQuick.Window 2.2
//import Material 0.3
import QtQuick.Controls.Material 2.0

import "myControls"
//import "qrc:/Material"
import ca.riftekit.Containers 1.0
import ca.riftekit.Controllers 1.0

Page{
    id: root
    title: "Registration"

    readonly property int loginIndex:           0
    readonly property int registrationIndex:    1

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
        if(swipeView.focus)
            swipeView.focus = false
        else
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
            onCurrentIndexChanged: focus = false

            Pane{
                id: loginForm
                width: swipeView.width
                height: swipeView.height

//                Flickable{
//                    anchors.fill: parent

//                    contentHeight: loginFormLayout.implicitHeight

                    function buildData(){
                        var rData = Qt.createQmlObject("import ca.riftekit.Containers 1.0; RegistrationFormData {}", this)
                        rData.email = loginEmail.text
                        rData.password = loginPassword.text
                        return rData
                    }

                    GridLayout{
                        id: loginFormLayout
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                        columns: 1
                        rowSpacing: 16 * global_scale_factor

                        TextFieldWithLabel{
                            id: loginEmail
                            title: qsTr("Email address")
//                            expandWidth: true
                            Layout.fillWidth: true
                            KeyNavigation.tab: loginPassword
                        }

                        TextFieldWithLabel{
                            id: loginPassword
                            title: qsTr("Password")
//                            expandWidth: true
                            Layout.fillWidth: true
                            KeyNavigation.tab: acceptButton
                        }

                    }

//                    ScrollIndicator.vertical: ScrollIndicator { }

//                }

            }

            Pane{
                width: swipeView.width
                height: swipeView.height

                function buildData(){
                    var rData = Qt.createQmlObject("import ca.riftekit.Containers 1.0; RegistrationFormData {}", this)
                    rData.name = registerName.text
                    rData.email = registerEmail.text
                    rData.password = registerPassword.text
                    return rData
//                    registrationData.name = registerName.text
//                    registrationData.email = registerEmail.text
//                    registrationData.password = registerPassword.text
                }

                Flickable{
                    anchors.fill: parent
                    contentHeight: registrationLayout.implicitHeight
                    clip: true
                    ScrollIndicator.vertical: ScrollIndicator { }

                    GridLayout{
                        id: registrationLayout
//                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                        columns: 1
                        rowSpacing: 16 * global_scale_factor

                        GridLayout{
                            Layout.fillWidth: true
                            columns: 2
                            rows: 1

                            TextFieldWithLabel{
                                id: registerName
                                title: qsTr("Name")
                                KeyNavigation.tab: registerSurname
                                Layout.fillWidth: true
                            }

                            TextFieldWithLabel{
                                id: registerSurname
                                title: qsTr("Surname")
                                KeyNavigation.tab: registerAddress
                                Layout.fillWidth: true
                            }
                        }

                        TextFieldWithLabel{
                            id: registerAddress
                            title: qsTr("Postal address")
                            KeyNavigation.tab: registerPhone
                            Layout.fillWidth: true
                        }

                        TextFieldWithLabel{
                            id: registerPhone
                            title: qsTr("Phone number")
                            KeyNavigation.tab: registerEmail
                            Layout.fillWidth: true
                        }

                        TextFieldWithLabel{
                            id: registerEmail
                            title: qsTr("Email address")
                            KeyNavigation.tab: registerPassword
                            Layout.fillWidth: true
                        }

                        TextFieldWithLabel{
                            id: registerPassword
                            title: qsTr("Password")
                            KeyNavigation.tab: acceptButton
                            Layout.fillWidth: true
                        }

                        //                    Item{
                        //                        Layout.fillHeight: true
                        //                    }

                    }

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

                    if(swipeView.currentIndex === loginIndex)
//                        global_mainWorker.regFormController.processLogin(rData)
                        controller.processLogin(rData)
                    else if(swipeView.currentIndex === registrationIndex)
//                        global_mainWorker.regFormController.processRegistration(rData)
                        controller.processRegistration(rData)

                    rData.destroy()

//                    sucRes.open()
                }
            }
        }
    }

    RegistrationFormController{
        id: controller
        onRequestResult: {
            if (!status) {
                sucRes.errorMessage = message
                sucRes.showDialog(sucRes.error)
            } else {
                sucRes.showDialog(sucRes.successRegistration)
            }
        }
    }

    PopupPF{
        id: waitDialog
        closePolicy: Popup.NoAutoClose
        visible: controller.requstStatus === RegistrationFormController.S_InProgress

        contentItem: Column{
            id: waitDialogLayout
            spacing: 20 * global_scale_factor
            BusyIndicator{
                readonly property int size: waitDialog.availableWidth * 3/4
                running: waitDialog.visible
                width: size
                height: size
                anchors.horizontalCenter: parent.horizontalCenter
            }

            LabelPF{
                width: waitDialog.availableWidth
                text: qsTr("Sending data to server...")
                wrapMode: Label.Wrap
                horizontalAlignment: Qt.AlignHCenter
            }            
        }

    }

    PopupPF{
        id: sucRes
//        width: root.width
        height: sucResColumn.height + topPadding + bottomPadding

        readonly property int error:                0
        readonly property int successRegistration:  1

        property string errorMessage

        function showDialog(messageCode){
            switch(messageCode){
            case error:
                headerLabel.text = qsTr("Error")
                messageLabel.text = errorMessage
                break;
            case successRegistration:
                headerLabel.text = qsTr("Successful registration!")
                messageLabel.text = qsTr("You can now take pictures or select them from gallery to send.")
                break;
            default:
                return;
            }
            open()
        }

        Column{
            id: sucResColumn
            spacing: 30 * global_scale_factor

            LabelPF{
                id: headerLabel
                width: sucRes.availableWidth
                text: qsTr("Successful registration!")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            LabelPF{
                id: messageLabel
                width: sucRes.availableWidth
                text: qsTr("You can now take pictures or select them from gallery to send.")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            Item{
                width: sucRes.availableWidth
                height: okButton.height
                Button{
                    id: okButton
                    text: "Ok"
                    anchors.right: parent.right
                    onClicked: sucRes.close()

                    contentItem: Text {
                        text: okButton.text
                        font: okButton.font
                        opacity: enabled ? 1.0 : 0.3
                        color: okButton.down ? "#0277B8" : Material.primary
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight

                        Behavior on color {
                            ColorAnimation {  }
                        }

                    }

                    background: Item{}

                }
            }

        }

    }
}
