import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

import "myScripts/Styles.js" as ScriptStyles
import "myControls"
//import "qrc:/Material"
//import Material 0.3
//import Material.ListItems 0.1 as ListItem

import ca.riftekit.Workers 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 360
    height: 520
    title: global_appTitle
    visibility: global_requestedFullScreen ? Window.FullScreen : Window.AutomaticVisibility

    Material.primary: Material.Blue
    Material.accent: Material.LightBlue
    Material.theme: Material.Light

    property string global_appTitle: "PhotoFly"

    property bool   global_requestedFullScreen: false
    property int    global_scale_factor: 1

    property MainWorker global_mainWorker: mainWorker
    property StackView  global_stackView: stackView

//    header: ToolBar {
//        RowLayout {
//            spacing: 20
//            anchors.fill: parent

//            ToolButton {
//                id: menuButton
//                contentItem: Image {
//                    fillMode: Image.Pad
//                    horizontalAlignment: Image.AlignHCenter
//                    verticalAlignment: Image.AlignVCenter
//                    source: "qrc:/icons/navigation/menu.svg"
//                }
//                onClicked: drawer.open()
//            }

//            Label {
//                id: titleLabel
//                text: root.title
//                font.pixelSize: 20
//                elide: Label.ElideRight
//                horizontalAlignment: Qt.AlignHCenter
//                verticalAlignment: Qt.AlignVCenter
//                Layout.fillWidth: true
//            }

//            Item{
//                width: menuButton.width
//            }

//        }
//    }

//    Drawer {
//        id: drawer
//        width: Math.min(root.width, root.height) / 3 * 2
//        height: root.height

//        ListView {
//            id: listView
//            currentIndex: -1
//            anchors.fill: parent

//            delegate: ItemDelegate {
//                width: parent.width
//                text: model.title
//                highlighted: ListView.isCurrentItem
//                onClicked: {
//                    if (listView.currentIndex != index) {
//                        listView.currentIndex = index
////                        titleLabel.text = model.title
////                        stackView.replace(model.source)
//                    }
//                    drawer.close()
//                }
//            }

//            ScrollIndicator.vertical: ScrollIndicator { }
//        }
//    }

    function backClicked(){
        if(stackView.depth > 1)
            stackView.pop()
        else
            Qt.quit()
    }

    function registrationComplete(){
        stackView.replace(mainFormComponent)
    }

    Component.onCompleted: {
        global_scale_factor = ApplicationSettings.ratio

        var key = ApplicationSettings.getSettingsKeyString(ApplicationSettings.SK_IsRegistered)
        var isRegistered = ApplicationSettings.getBoolValue(key)

        if(!isRegistered)
            stackView.push(regFormComponent)
        else
            stackView.push(mainFormComponent)
    }

    StackView{
        id: stackView
        anchors.fill: parent

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

//    Component{
//        id: initComp
//        MainForm{
//            id: initPage
//            menuList: root.menuList
//        }
//    }

    FontLoader{ id: msp_ul;     source: "qrc:/fonts/myriad-set-pro_ultralight.ttf"; }   // Light
    FontLoader{ id: msp_th;     source: "qrc:/fonts/myriad-set-pro_thin.ttf"; }         // Bold
//    FontLoader{ source: "qrc:/fonts/myriad-set-pro_text.ttf"; }

}
