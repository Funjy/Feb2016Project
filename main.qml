import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0 as Controls
import QtQuick.Layouts 1.3

import "myScripts/Styles.js" as ScriptStyles
import "myControls"
import "qrc:/Material"
import com.riftekit.Workers 1.0
import Material 0.3
import Material.ListItems 0.1 as ListItem

ApplicationWindow {
    id: root
    visible: true
//    width: 800
//    height: 600
    visibility: global_requestedFullScreen ? Window.FullScreen : Window.AutomaticVisibility

    property bool global_requestedFullScreen: false

    property int global_scale_factor: 1
    property int global_scale_font_factor: 1

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
        global_scale_font_factor = ApplicationSettings.fontRatio

        var isFirstLaunch = ApplicationSettings.isFirstLaunch()

        if(isFirstLaunch){
            root.pageStack.push(regFormComponent)
        }
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

    TabbedPage {
        id: initPage
        title: "PhotoFly"

        backAction: navDrawer.action
        NavigationDrawer {
            id: navDrawer
            Flickable {
                anchors.fill: parent

                contentHeight: Math.max(content.implicitHeight, height)

                Column {
                    id: content
                    anchors.fill: parent
                    spacing: 20 * global_scale_factor

                    Item{
                        height: 1
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }

                    Rectangle{
                        color: Theme.tabHighlightColor
                        height: 160 * global_scale_factor
                        anchors.left: parent.left
                        anchors.right: parent.right
                        Row{
                            anchors.fill: parent
                            spacing: 16 * global_scale_factor
                            Icon{
                                name: "navigation/more_vert"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Label{
                                text: "Anton Kustou"
                                anchors.verticalCenter: parent.verticalCenter
                                font.pixelSize: 32 * global_scale_factor
                            }
                        }
                    }

                    ThinDivider { }

                    Repeater {
                        model: menuList.length
                        Button{
                            id: menuButton
                            implicitHeight: 60 * global_scale_factor

                            text: action.name
                            enabled: action.enabled

                            property Action action: menuList[index]

                            onClicked: {
                                action.trigger(menuButton)
                                navDrawer.close()
                            }
                        }
                    }
                }
            }

        }

        GridLayout{
                columns: 1
                anchors.fill: parent
                Item {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    Layout.fillHeight: true

                    AwesomeIcon{
                        name: "image"
                        anchors.centerIn: parent
                        size: parent.height / 2
                        Ink {
                            anchors.fill: parent
                            onClicked: mainWorker.selectImageFromGallery()
                        }
                    }


                }
                Item {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    Layout.fillHeight: true
                    AwesomeIcon{
                        name: "camera"
                        anchors.centerIn: parent
                        size: parent.height / 2
                        Ink {
                            anchors.fill: parent

                            onClicked: mainWorker.openCamera()
                        }
                    }
                }
            }

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
//    FontLoader{ id: materialFont;   source: "qrc:/fonts/MaterialIcons-Regular.ttf"; }

}
