import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "myControls"
import com.riftekit.RegistrationFormData 1.0
import QtQuick.Window 2.2

DefaultPanelPF{
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

        TextBoxPF{
            placeHolderText: qsTr("Surname")
        }

        TextBoxPF{
            placeHolderText: qsTr("Email")
        }

        TextBoxPF{
            placeHolderText: qsTr("Phone number")
        }
    }

    onBackClicked: sucRes.show()

    RegistrationFormData{
        id: registrationData
    }

    MessageDialog{
        id: sucRes
        messageComponent:
            Component{
            SuccessRegistration{
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
