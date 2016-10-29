import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

import "qrc:/qml/myScripts/Styles.js" as ScriptStyles

ToolBar {
    id: root

//    signal leftButtonClicked()
//    signal rightButtonClicked()

    property string title: ""
    property alias leftButton: menuButton
    property alias rightButton: proceedButton

    Material.primary: "white"

    RowLayout {
        spacing: ScriptStyles.toolBarRowSpacing * global_scale_factor
        anchors.fill: parent

        ToolButton {
            id: menuButton
            contentItem: Item {
                height: ScriptStyles.toolButtonSize * global_scale_factor
                width: ScriptStyles.toolButtonSize * global_scale_factor
                Image {
                    id: menuImage
                    fillMode: Image.PreserveAspectFit
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/close-128.png"
                    anchors.fill: parent
                }
            }
//            onClicked: drawer.open()
//            onClicked: root.leftButtonClicked()
        }

        Item{
            Layout.fillWidth: true
        }

        Item{
            width: Math.max(proceedButton.implicitWidth, menuButton.width)
            height: proceedButton.implicitHeight
            ToolButton {
                id: proceedButton
                opacity: selectedPhotosView.count > 0 ? 1 : 0
                visible: opacity > 0
                enabled: opacity == 1
                font.pixelSize: titleLabel.font.pixelSize * 0.8
//                text: qsTr("Proceed")
                width: parent.width
                Behavior on opacity {NumberAnimation{easing.type: Easing.InOutQuad}}
                onClicked: {
//                    openComponent(messageOptionsComponent)
//                    root.rightButtonClicked()
                }
            }
        }

    }

    LabelPF {
        id: titleLabel
        text: root.title
        //            font.pixelSize: ScriptStyles.titleFontSize * global_scale_factor
        font.pixelSize: parent.height * 0.5
        elide: Label.ElideRight
        //                horizontalAlignment: Qt.AlignHCenter
        //                verticalAlignment: Qt.AlignVCenter
        //                anchors.verticalCenter: parent.verticalCenter
        //                Layout.fillWidth: true
        anchors.centerIn: parent
    }
}
