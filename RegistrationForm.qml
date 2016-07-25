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
                spacing: 10 * global_scale_factor
                property int marginValue: parent.width * 0.1
                anchors.leftMargin: marginValue
                anchors.rightMargin: marginValue

                LabelPF{
                    text: "Name"
                }

                TextBoxPF{
                }

                LabelPF{
                    text: "Surname"
                }

                TextBoxPF{
                }

                LabelPF{
                    text: "Email Address"
                }

                TextBoxPF{
                }

                LabelPF{
                    text: "Credit card"
                }

                TextBoxPF{
                }

                LabelPF{
                    text: "Home address"
                }

                TextBoxPF{
                }

            }

        }
    }

    RegistrationFormData{
        id: registrationData
    }

}
