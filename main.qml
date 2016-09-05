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

    property var menuList: [
        qsTr("Payment"), qsTr("History"), qsTr("Settings")
    ]
    property string selectedComponent: menuList[0]

    function openItem(openItem, props)
    {
        stack.push(openItem, {destroyOnPop: true, properties: props})
    }
    function closeItem()
    {
        console.log("depth: " + stack.depth)
        if ( stack.depth > 1 )
            stack.pop();
    }

    Component.onCompleted: {
        global_scale_factor = ApplicationSettings.ratio
        global_scale_font_factor = ApplicationSettings.fontRatio

        var isFirstLaunch = ApplicationSettings.isFirstLaunch()

        if(isFirstLaunch){
            root.pageStack.push(regFormComponent)
//            initPage.push(regFormComponent)
        }


//        if(isFirstLaunch){
//            openItem(regFormComponent)
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

                    Repeater {
                        model: menuList
                        delegate: ListItem.Standard {
                            text: modelData
//                            selected: modelData == root.selectedComponent
                            onClicked: {
//                                root.selectedComponent = modelData
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

        //                    onClicked: overlayView.open(image)
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
