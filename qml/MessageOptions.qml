import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0

import "myControls"

MessageOptionsForm {
    id: root
    title: qsTr("Options")
//    anchors.fill: parent
    property var controller

    backButton.onClicked: backClicked()
    sendButton.onClicked: {
        if (!firstName.isValid ||
            !secondName.isValid ||
            !postalAddress.isValid) {
            messagePopup.open()
            return
         }
        controller.sendRequested(prepareData())
    }

    function prepareData() {
        var data2send = {};
        data2send["fName"] = firstName.text
        data2send["sName"] = secondName.text
        data2send["photoSize"] = photoSizeBox.currentIndex
        data2send["postalAddress"] = postalAddress.text
        return data2send
    }

    PopupPF{
        id: messagePopup

        LabelPF{
            id: headerLabel
            width: messagePopup.availableWidth
            text: qsTr("Incorrect data")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

    }



}
