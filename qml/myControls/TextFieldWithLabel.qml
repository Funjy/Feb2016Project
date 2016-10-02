import QtQuick 2.7

Column{
    id: root
    property alias title: label.text
    property alias text: textBox.text
    property bool expandWidth: false

    anchors {left: expandWidth ? parent.left : undefined; right: expandWidth ? parent.right : undefined}

    LabelPF{
        id: label
    }
    TextBoxPF{
        id: textBox
        placeholderText: label.text
        anchors {left: root.left; right: root.right}
//        anchors.left: parent.left
//        anchors.right: parent.right
    }
}
