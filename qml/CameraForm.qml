import QtQuick 2.5
import QtMultimedia 5.6
import QtQuick.Window 2.0

Rectangle {
    id: root
//    anchors.fill: parent
    color: "black"

    Component.onCompleted: {
        global_requestedFullScreen = true
    }

    Component.onDestruction: {
        global_requestedFullScreen = false
    }

    Camera{
        id: camera

        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview  // Show the preview in an Image
            }
        }

    }

    VideoOutput {
        source: camera
        anchors.fill: parent
//        anchors.left: Screen.primaryOrientation === Qt.PortraitOrientation ? parent.left : parent.bottom
//        anchors.top: Screen.primaryOrientation === Qt.PortraitOrientation ? parent.top : parent.left
//        anchors.right: Screen.primaryOrientation === Qt.PortraitOrientation ? parent.right : parent.top
//        anchors.bottom: Screen.primaryOrientation === Qt.PortraitOrientation ? parent.bottom : parent.right
//        rotation: Screen.primaryOrientation === Qt.LandscapeOrientation ? -90 : 0
        focus : visible // to receive focus and capture key events when visible
        orientation: Screen.primaryOrientation === Qt.LandscapeOrientation ? 0 : camera.orientation
//        orientation: 0
        fillMode: VideoOutput.PreserveAspectCrop
    }

    Image {
        id: photoPreview
        anchors.centerIn: parent
        source: ""
        MouseArea{
            anchors.fill: parent
            enabled: photoPreview.source !== ""
            onClicked: photoPreview.source = ""

        }
    }

    Rectangle{
        id: clickRect
        color: "orange"

        anchors.bottom: parent.bottom
        anchors.bottomMargin: root.height * 0.08
        anchors.horizontalCenter: root.horizontalCenter
        width: root.width * 0.08
        height: width
        radius: 8


        MouseArea{
            id: clickArea
            anchors.fill: parent
            onClicked: {
                camera.imageCapture.capture()
            }
        }
    }

    Rectangle{
        id: clickRect2
        color: "green"

        anchors.left: parent.left
        anchors.leftMargin: root.width * 0.08
        anchors.verticalCenter: root.verticalCenter
        width: root.width * 0.08
        height: width
        radius: 8


        MouseArea{
            id: clickArea2
            anchors.fill: parent
            onClicked: {
                camera.position =
                        camera.position === Camera.FrontFace ?
                            Camera.BackFace : Camera.FrontFace
            }
        }
    }


}
