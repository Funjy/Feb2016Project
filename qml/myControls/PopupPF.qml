import QtQuick 2.6
import QtQuick.Controls 2.0

Popup{
    id: root
    modal: true
    focus: true

    property var sizeSource: null

    property var _useSource: sizeSource ? sizeSource : parent

    x: (_useSource.width - width) / 2
    y: (_useSource.height - height) / 2
    width: Math.min(_useSource.width, _useSource.height) / 3 * 2
//    height: Math.max(_useSource.width, _useSource.height) / 3 * 2
//    height: parent.implicitHeight + topPadding + bottomPadding

}
