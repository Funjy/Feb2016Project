import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0 as Controls
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2
import Material 0.3

import "myControls"
import com.riftekit.Containers 1.0

DefaultPanelPF{
    id: root
    title: "Registration"
//    showBackButton: false
    showNextButton: true
    content: GridLayout{
        anchors.fill: parent
        columns: 1
        columnSpacing: 16 * global_scale_factor
        property int marginValue: parent.width * 0.1
        anchors.leftMargin: marginValue
        anchors.rightMargin: marginValue

        TextBoxPF{
            placeHolderText: qsTr("Name")
            text: global_scale_factor
        }

        TextBoxPF{
            placeHolderText: qsTr("Email")
        }

        TextBoxPF{
            placeHolderText: qsTr("Phone number")
        }

        Item{
            Layout.fillHeight: true
        }

        GridLayout{
            Button{
                text: "Skip"
                Layout.fillWidth: true
            }
            Button{
                text: "Accept"
                Layout.fillWidth: true
            }
        }


    }

//    onBackClicked: mainWorker.buttonClicked() //sucRes.show()
//    onBackClicked: sucRes.show()
//    onNextClicked: stack.push(cameraFormComponent)

//    Component{
//        id: cameraFormComponent
//        CameraForm{

//        }
//    }

    RegistrationFormData{
        id: registrationData
    }

    MessageDialog{
        id: sucRes
        Component{
            SuccessRegistration{
            }
        }
    }
}
