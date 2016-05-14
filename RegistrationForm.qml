import QtQuick 2.4
import "myControls"

Item {
    anchors.fill: parent

    WindowHeader{
//        text: "Registration"
        property int i: 0
        onBackClicked: {
            text = ++i
        }
    }

}
