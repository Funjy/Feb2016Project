import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "myControls"
import com.riftekit.RegistrationFormData 1.0

Item {
    id: root
    anchors.fill: parent

    GridLayout{
        anchors.fill: parent
        columns: 1
        flow: GridLayout.TopToBottom

        rowSpacing: 100 * global_scale_factor

        WindowHeader{
            Layout.fillWidth: true
            id: panelHeader
            text: "Registration"
            property int i: 0
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
//            Rectangle{
//                anchors.fill: parent
//                color: "magenta"
//            }

            Column{
                anchors.fill: parent
                spacing: 100 * global_scale_factor
                property int marginValue: parent.width * 0.1
                anchors.leftMargin: marginValue
                anchors.rightMargin: marginValue

                TextBoxPF{
                    placeHolderText: qsTr("Name")                    
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
