import QtQuick 2.4
import QtQuick.Layouts 1.3
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
        }
    }

    RegistrationFormData{
        id: registrationData
    }

}
