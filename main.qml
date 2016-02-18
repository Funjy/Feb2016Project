import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 800
    height: 600

    MainForm {
        id: form
        anchors.fill: parent

        mouseArea1.onClicked: {
            mainWorker.buttonClicked()
        }

    }


    Connections{
        target: mainWorker
        onSetMessage: form.text1.text = message
    }
}
