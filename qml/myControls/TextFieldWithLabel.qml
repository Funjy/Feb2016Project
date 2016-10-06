import QtQuick 2.7
import QtQuick.Layouts 1.1

FocusScope{
    id: root
    property alias title: label.text
    property alias text: textBox.text
    property bool expandWidth: false
    property int enterKeyType: Qt.EnterKeyDefault
    property var onNextClickedItem: null

    height: grid.height
    width: if(!root.Layout.fillWidth) grid.width

    signal doneClicked()

    GridLayout{
        id: grid
        rows: 2
        columns: 1

        anchors.left: if(root.Layout.fillWidth) root.left
        anchors.right: if(root.Layout.fillWidth) root.right

        LabelPF{
            id: label
        }
        TextBoxPF{
            id: textBox
            focus: true
            placeholderText: label.text
            Layout.fillWidth: true
            EnterKey.type: root.enterKeyType

            Keys.onEnterPressed:    moveFocus()
            Keys.onReturnPressed:   moveFocus()

            function moveFocus(){
                if(root.enterKeyType === Qt.EnterKeyNext && root.onNextClickedItem !== null){
                    console.log("invoked next")
                    root.onNextClickedItem.forceActiveFocus()
                } else if (root.enterKeyType === Qt.EnterKeyDone) {
                    root.focus = false
                    root.doneClicked()
                }
            }
        }
    }
}
