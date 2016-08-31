import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "myControls"
import QtQuick.Window 2.2

import com.riftekit.Containers 1.0

DefaultPanelPF{
    id: root
    title: "Registration"
    showNextButton: true
    content: Column{
        anchors.fill: parent
        spacing: 16 * global_scale_factor
        property int marginValue: parent.width * 0.1
        anchors.leftMargin: marginValue
        anchors.rightMargin: marginValue

        TextBoxPF{
            placeHolderText: qsTr("Name")
            text: global_scale_factor
        }

//        WindowHeader{
//            Layout.fillWidth: true
//            id: panelHeader
//            text: "Registration"
//            Component{
//                id: cameraFormComponent
//                CameraForm{

//                }
//            }

//            onBackClicked: {
////                sucRes.show()
//                stack.push(cameraFormComponent)
//            }
//        }

        TextBoxPF{
            placeHolderText: qsTr("Email")
        }

        TextBoxPF{
            placeHolderText: qsTr("Phone number")
        }
    }

//    onBackClicked: mainWorker.buttonClicked() //sucRes.show()
    onBackClicked: sucRes.show()
    onNextClicked: stack.push(cameraFormComponent)

    Component{
        id: cameraFormComponent
        CameraForm{

        }
    }

    RegistrationFormData{
        id: registrationData
    }

    MessageDialog{
        id: sucRes
        Component{
            SuccessRegistration{
//                anchors.verticalCenter: sucRes.verticalCenter
            }
        }
    }
}
