import QtQuick 2.6
import QtQuick.Controls 2.0

Popup{
    id: root
    modal: true
    focus: true

    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    width: Math.min(parent.width, parent.height) / 3 * 2
//    height: Math.max(parent.width, parent.height) / 3 * 2
//    height: parent.implicitHeight + topPadding + bottomPadding

}
