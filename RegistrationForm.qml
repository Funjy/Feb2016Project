import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "myControls"
import com.riftekit.RegistrationFormData 1.0
import QtQuick.Window 2.2

Item {
    id: root
    anchors.fill: parent

    MessageDialog{
        id: sucRes
        z: 1
        messageComponent:
            Component{
            SuccessRegistration{
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    GridLayout{
        anchors.fill: parent
        columns: 1
        flow: GridLayout.TopToBottom        

        rowSpacing: 16 * global_scale_factor

        WindowHeader{
            Layout.fillWidth: true
            id: panelHeader
            text: "Registration"
            onBackClicked: {
                sucRes.show()
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Column{
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

        }
    }

    RegistrationFormData{
        id: registrationData
    }

}
