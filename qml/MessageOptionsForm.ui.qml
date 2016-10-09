import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

import "myScripts/Styles.js" as ScriptStyles
import "myControls"

Page {
    id: root
//    width: 400
//    height: 400
    property alias secondName: secondName
    property alias firstName: firstName
    property alias photoSizeBox: photoSizeBox
    wheelEnabled: false

    property alias backButton: backButton
    property alias sendButton: sendButton
    property alias postalAddress: postalAddress

    header: ToolBar {
        id: toolBar1
        Material.primary: "white"

        RowLayout {
            spacing: ScriptStyles.toolBarRowSpacing * global_scale_factor
            anchors.fill: parent

            ToolButton {
                id: backButton
                contentItem: Item {
                    height: ScriptStyles.toolButtonSize * global_scale_factor
                    width: ScriptStyles.toolButtonSize * global_scale_factor
                    Image {
                        id: backImage
                        fillMode: Image.PreserveAspectFit
                        horizontalAlignment: Image.AlignHCenter
                        verticalAlignment: Image.AlignVCenter
                        source: "qrc:/images/close-128.png"
                        anchors.fill: parent
                    }
                }
            }

            Label {
                id: titleLabel
                text: root.title
                font.pixelSize: ScriptStyles.titleFontSize * global_scale_factor
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                id: sendButton
                contentItem: Item {
                    height: ScriptStyles.toolButtonSize * global_scale_factor
                    width: ScriptStyles.toolButtonSize * global_scale_factor
                    Image {
                        id: sendImage
                        fillMode: Image.PreserveAspectFit
                        horizontalAlignment: Image.AlignHCenter
                        verticalAlignment: Image.AlignVCenter
                        source: "qrc:/images/close-128.png"
                        anchors.fill: parent
                    }
                }
            }
        }

    }

    ColumnLayout {
        id: grid1
        anchors.fill: parent
        anchors.margins: ScriptStyles.commonMargins * global_scale_factor
        spacing: ScriptStyles.spacingInColumn * global_scale_factor

        RowLayout{
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: ScriptStyles.spacingInRow * global_scale_factor

            Item{
                implicitHeight: labelPF1.implicitHeight
                Layout.fillWidth: true
                anchors.verticalCenter: parent.verticalCenter
                LabelPF {
                    id: labelPF1
                    text: qsTr("Photo size")
                }
            }

            Item{
                implicitHeight: photoSizeBox.implicitHeight
                Layout.fillWidth: true
                ComboBox {
                    id: photoSizeBox
//                    Layout.alignment: Grid.AlignHCenter | Grid.AlignVCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    model: [
                        "24x24",
                        "48x48",
                    ]
                }
            }

        }

        RowLayout{
            anchors.left: parent.left
            anchors.right: parent.right

            TextFieldWithLabel {
                id: firstName
                title: qsTr("First name")
                Layout.fillWidth: true
                onNextClickedItem: secondName
                enterKeyType: Qt.EnterKeyNext
                isValid: text.length > 0

            }

            TextFieldWithLabel {
                id: secondName
                title: qsTr("Second name")
                Layout.fillWidth: true
                enterKeyType: Qt.EnterKeyNext
                onNextClickedItem: postalAddress
                isValid: text.length > 0

            }
        }

        TextFieldWithLabel {
            id: postalAddress
            title: qsTr("Postal address")
            Layout.fillWidth: true
            isValid: text.length > 0

//            enterKeyType: Qt.EnterKeyNext
        }

        Item{
            Layout.fillHeight: true
        }
    }
}
