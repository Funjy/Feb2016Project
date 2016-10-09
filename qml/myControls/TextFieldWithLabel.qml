import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.0

FocusScope{
    id: root
    property alias title: label.text
    property alias text: textBox.text
//    property bool expandWidth: false
    property int enterKeyType: Qt.EnterKeyDefault
    property var onNextClickedItem: null
    property bool isValid: true

    height: grid.height
    width: if(!root.Layout.fillWidth) grid.width

    signal doneClicked()

    Behavior on y {NumberAnimation{easing.type: Easing.InOutQuad}}

    GridLayout{
        id: grid
        rows: 2
        columns: 1
        rowSpacing: 0

        anchors.left: if(root.Layout.fillWidth) root.left
        anchors.right: if(root.Layout.fillWidth) root.right

        Item{
            id: labelItem
            implicitHeight: label.implicitHeight
            implicitWidth: label.implicitWidth

            LabelPF{
                id: label
                opacity: textBox.length > 0 ? 1 : 0

                color: root.isValid ? Material.foreground : "red"

                Behavior on opacity { NumberAnimation{ easing.type: Easing.InOutQuad } }
                Behavior on color { ColorAnimation{ easing.type: Easing.InOutQuad } }

                states: [
                    State{
                        when: textBox.length > 0
                        AnchorChanges { target: label; anchors.top: labelItem.top }
                    },
                    State{
                        when: textBox.length == 0
                        AnchorChanges { target: label; anchors.top: labelItem.bottom }
                    }
                ]

                transitions: Transition {
                    AnchorAnimation{easing.type: Easing.InOutQuad}
                }

            }
        }
        TextBoxPF{
            id: textBox
            focus: true
            placeholderText: label.text
            Layout.fillWidth: true
            EnterKey.type: root.enterKeyType

            Keys.onEnterPressed:    moveFocus()
            Keys.onReturnPressed:   moveFocus()

            function moveFocus() {
                if(root.enterKeyType === Qt.EnterKeyNext && root.onNextClickedItem !== null){
                    root.onNextClickedItem.forceActiveFocus()
                } else if (root.enterKeyType === Qt.EnterKeyDone) {
                    root.focus = false
                    root.doneClicked()
                }
            }
        }
    }
}
