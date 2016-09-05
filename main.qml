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
    visibility: global_requestedFullScreen ? Window.FullScreen : Window.AutomaticVisibility

    property bool global_requestedFullScreen: false

    property int global_scale_factor: 1
    property int global_scale_font_factor: 1

    property MainWorker global_mainWorker: mainWorker

    function openItem(openItem, props)
    {
        stack.push(openItem, {destroyOnPop: true, properties: props})
    }

    Component.onCompleted: {
        global_scale_factor = ApplicationSettings.ratio
        global_scale_font_factor = ApplicationSettings.fontRatio

        var isReg = ApplicationSettings.getValue(ApplicationSettings.keyIsRegistered)
        if(isReg === undefined || !isReg){
            openItem("qrc:/RegistrationForm.qml")
        } else {
            openItem(mainFormComponent)
        }
    }

    Component{
        id: regFormComponent
        RegistrationForm{}
    }

    Component{
        id: mainFormComponent
        MainForm{}
    }

//    property var font1: msp_th

//    MainForm {
//        id: form
//        anchors.fill: parent

//        mouseArea1.onClicked: {
//            mainWorker.buttonClicked()
//        }

//    }
//    Connections{
//        target: mainWorker
//        onSetMessage: form.text1.text = message
//    }

    StackView{
        id: stack
        anchors.fill: parent
//        initialItem: RegistrationForm{}
        focus: true
        Keys.onReleased: {
            if (event.key === Qt.Key_Back && stack.depth > 1)
            {
                stack.pop();
                event.accepted = true;
            }
        }
    }



    FontLoader{ id: msp_ul;     source: "qrc:/fonts/myriad-set-pro_ultralight.ttf"; }   // Light
    FontLoader{ id: msp_th;     source: "qrc:/fonts/myriad-set-pro_thin.ttf"; }         // Bold
//    FontLoader{ source: "qrc:/fonts/myriad-set-pro_text.ttf"; }
//    FontLoader{ id: materialFont;   source: "qrc:/fonts/MaterialIcons-Regular.ttf"; }

}
