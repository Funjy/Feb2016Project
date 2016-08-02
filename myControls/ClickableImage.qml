import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Button {
    style: ButtonStyle{
        background: Item {}

        label: Item {
            anchors.fill: control
            Image {
                id:                     imageItem
                source:                 control.iconSource
                verticalAlignment:      Image.AlignVCenter
                horizontalAlignment:    Image.AlignHCenter
                opacity:                control.enabled ? 1 : 0.5
                sourceSize.width:       parent.width
                sourceSize.height:      parent.height
            }
        }
    }
}

