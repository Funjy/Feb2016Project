import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Button {
    style: ButtonStyle{
        background: Item {
                property bool down: control.pressed || (control.checkable && control.checked)
                implicitWidth: imageItem.implicitWidth
                implicitHeight: imageItem.implicitHeight
                Image {
                    id: imageItem
                    source: "images/arrow-down.png"
                    anchors.verticalCenter:     parent.verticalCenter
                    anchors.horizontalCenter:   parent.horizontalCenter
//                    anchors.right: parent.right
//                    anchors.rightMargin: 4
                    opacity: control.enabled ? 1 : 0.5
                }
            }
    }
}

