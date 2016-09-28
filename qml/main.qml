import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.3

import "myScripts/Styles.js" as ScriptStyles
import "myControls"
import "qrc:/Material"
import Material 0.3
import Material.ListItems 0.1 as ListItem

import ca.riftekit.Workers 1.0

ApplicationWindow {
    id: root
    visible: true
//    width: 800
//    height: 600
    visibility: global_requestedFullScreen ? Window.FullScreen : Window.AutomaticVisibility

    property bool   global_requestedFullScreen: false
    property int    global_scale_factor: 1

    property MainWorker global_mainWorker: mainWorker

    property list<Action> menuList: [
        Action{
            name: qsTr("Payment")
            onTriggered: console.log("pay")
        },
        Action{
            name: qsTr("History")
            onTriggered: console.log("hist")
        },
        Action{
            name: qsTr("Settings")
        }
    ]


//    function openItem(openItem, props)
//    {
//        stack.push(openItem, {destroyOnPop: true, properties: props})
//    }
//    function closeItem()
//    {
//        console.log("depth: " + stack.depth)
//        if ( stack.depth > 1 )
//            stack.pop();
//    }

    Component.onCompleted: {
        global_scale_factor = ApplicationSettings.ratio

        var isFirstLaunch = ApplicationSettings.isFirstLaunch()

        overlay.open(initPage)

//        if(isFirstLaunch){
//            root.pageStack.push(regFormComponent)
//        }
    }

    Component{
        id: regFormComponent
        RegistrationForm{
            firstLaunch: true
        }
    }

    Component{
        id: mainFormComponent
        MainForm{}
    }

    initialPage: initPage

    MainForm{
        id: initPage
        menuList: root.menuList
    }

    OverlayView{
        id: overlay
        width: root.width
        height: root.height

        RegistrationFormContent{
            firstLaunch: true
            onSkipClicked: overlay.close()
        }

//        Text {
//            anchors.centerIn: parent
//            text: qsTr("tap to close")
//        }
//        MouseArea{
//            anchors.fill: parent
//            onClicked: overlay.close()
//        }
    }

//    StackView{
//        id: stack
//        anchors.fill: parent
//        initialItem: mainFormComponent
//        focus: true
//        Keys.onReleased: {
//            if (event.key === Qt.Key_Back && stack.depth > 1)
//            {
//                stack.pop();
//                event.accepted = true;
//            }
//        }
//    }

    FontLoader{ id: msp_ul;     source: "qrc:/fonts/myriad-set-pro_ultralight.ttf"; }   // Light
    FontLoader{ id: msp_th;     source: "qrc:/fonts/myriad-set-pro_thin.ttf"; }         // Bold
//    FontLoader{ source: "qrc:/fonts/myriad-set-pro_text.ttf"; }

}
