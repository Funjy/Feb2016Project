import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

import "myScripts/Styles.js" as ScriptStyles
import "myControls"
import com.riftekit.Workers 1.0

Window {
    id: root
    visible: true
    width: 800
    height: 600

    property int global_scale_factor: 1
    property int global_scale_font_factor: 1

    property MainWorker global_mainWorker: mainWorker

    Component.onCompleted: {
        global_scale_factor = mainWorker.ratio()
        global_scale_font_factor = mainWorker.ratioFont()        
    }

//    property var font1: msp_th

//    MainForm {
//        id: form
//        anchors.fill: parent

//        mouseArea1.onClicked: {
//            mainWorker.buttonClicked()
//        }

//    }

    StackView{
        id: stack
        anchors.fill: parent
        initialItem: RegistrationForm{}
        focus: true
        Keys.onReleased: if (event.key === Qt.Key_Back && stack.depth > 1) {
                             stack.pop();
                             event.accepted = true;
                         }
    }

//    RegistrationForm{

//    }

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

    FontLoader{ id: msp_ul;     source: "qrc:/fonts/myriad-set-pro_ultralight.ttf"; }   // Light
    FontLoader{ id: msp_th;     source: "qrc:/fonts/myriad-set-pro_thin.ttf"; }         // Bold
//    FontLoader{ source: "qrc:/fonts/myriad-set-pro_text.ttf"; }
    FontLoader{ id: materialFont;   source: "qrc:/fonts/MaterialIcons-Regular.ttf"; }

}
