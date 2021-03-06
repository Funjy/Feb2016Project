import QtQuick 2.4
import QtQuick.Layouts 1.3

Item {
    id: root
//    anchors.fill: if(parent) parent

    property alias content: contentItem.data
    property string title:  ""
    property alias showNextButton: panelHeader.showNextButton
    property alias showBackButton: panelHeader.showBackButton
//    property WindowHeader header: panelHeader
    property alias backButtonImageSource: panelHeader.backButtonImageSource

    signal backClicked()
    signal nextClicked()

    GridLayout{
        anchors.fill: parent
        columns: 1
        flow: GridLayout.TopToBottom

        rowSpacing: 16 * global_scale_factor

        WindowHeader{
            id: panelHeader
            Layout.fillWidth: true
            text: root.title
            onBackClicked: root.backClicked()
            onNextClicked: root.nextClicked()

        }

        Item {
            id: contentItem
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

}
