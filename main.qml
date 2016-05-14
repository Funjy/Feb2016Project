import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600

//    property var font1: msp_th

//    MainForm {
//        id: form
//        anchors.fill: parent

//        mouseArea1.onClicked: {
//            mainWorker.buttonClicked()
//        }

//    }

    RegistrationForm{

    }

//    Text{
//        anchors.centerIn: parent
//        text: name1.name + " - " + name2.name
//    }

//    WindowHeader{
//        anchors.top: parent.top
////        text: textFont.name
//    }

    Connections{
        target: mainWorker
        onSetMessage: form.text1.text = message
    }

    FontLoader{ id: msp_ul; source: "qrc:/fonts/myriad-set-pro_ultralight.ttf"; }   // Light
    FontLoader{ id: msp_th; source: "qrc:/fonts/myriad-set-pro_thin.ttf"; }         // Bold
//    FontLoader{ source: "qrc:/fonts/myriad-set-pro_text.ttf"; }

}
