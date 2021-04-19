import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.12
import Classify.utils 1.0
import QtMultimedia 5.12

Window {
    width: 1048
    height: 960
    visible: true
    title: "垃圾分类识别系统"
    Component.onCompleted: clsfy.loadConfig()

    ToolButton {
        text: "\u2638"
        anchors.right: parent.right
        anchors.top: parent.top
        onClicked: clsfy.loadConfig()
    }

    Text {
        id: label
        text: "您想要做什么？"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 24
        font.pixelSize: 24
        wrapMode: Text.Wrap
    }

    Button {
        id: upload_set
        width: 200
        text: "上传训练集"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: label.bottom
        anchors.topMargin: 24
        onClicked: {
            clsfy.upload_set()
        }
    }

    Slider {
        id: photos_num
        width: 250
        from: 1
        to: 20
        stepSize: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: upload_set.bottom
        anchors.topMargin: 24
    }

    Button {
        id: to_classify
        width: 200
        text: "云端识别" + photos_num.value + "个物品"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: photos_num.bottom
        anchors.topMargin: 24
        onClicked: {
            cap_img.imageCapture.capture()
        }
    }

    Frame {
        height: 640
        width: 920
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 24
        anchors.top: to_classify.bottom
        Frame {
            id: alert_frame
            anchors.left: parent.left
            height: parent.height
            width: parent.width / 2
            Text {
                id: alert
                anchors.fill: parent
                font.pixelSize: 20
            }
        }
        Frame {
            id: img_frame
            anchors.left: alert_frame.right
            height: parent.height
            width: parent.width / 2
            VideoOutput {
                id: cap_out
                anchors.top: parent.top
                source: cap_img
                height: parent.height / 2
                width: parent.width
            }
            Image {
                id: img_prev
                anchors.top: cap_out.bottom
                height: parent.height / 2
                width: parent.width
            }
        }
    }

    ProgressBar {
        id: pgress
        width: parent.width
        anchors.bottom: parent.bottom
        from: 0
        to: 100
        value: 100
    }

    Classify {
        id: clsfy

        onInfoChanged: {
            alert.text = info
        }
        onProgressChanged: {
            pgress.value = progress
        }
    }
    Camera {
        id: cap_img
        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceAuto

        exposure {
            exposureCompensation: 0
            exposureMode: Camera.ExposurePortrait
        }
        flash.mode: Camera.FlashRedEyeReduction

        imageCapture {
            onImageCaptured: {
                img_prev.source = preview
                console.log(preview)
            }
        }

        Component.onCompleted: {
            if (cap_img.CameraError) {
                setCameraAvailable(false)
            }
        }
    }
}
