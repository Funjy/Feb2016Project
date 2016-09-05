import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0 as Controls
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2
import Material 0.3

import "myControls"
import "qrc:/Material"
import com.riftekit.Containers 1.0

Page{
    id: root
    title: "Registration"

    property bool firstLaunch: false

    GridLayout{
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
                visible: root.firstLaunch
                text: "Skip"
                Layout.fillWidth: true
                onClicked: root.pop()
            }
            Button{
                text: "Accept"
                Layout.fillWidth: true
                onClicked: sucRes.show()
            }
        }


    }

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
