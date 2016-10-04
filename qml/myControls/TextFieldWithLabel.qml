import QtQuick 2.7
import QtQuick.Layouts 1.1

GridLayout{
    id: root
    property alias title: label.text
    property alias text: textBox.text
    property bool expandWidth: false
    rows: 2
    columns: 1

//    anchors {left: expandWidth ? parent.left : undefined; right: expandWidth ? parent.right : undefined}

    LabelPF{
        id: label
    }
    TextBoxPF{
        id: textBox
        placeholderText: label.text
        Layout.fillWidth: true
//        anchors {left: root.left; right: root.right}
//        anchors.left: parent.left
//        anchors.right: parent.right
    }
}
