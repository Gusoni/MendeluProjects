import QtQuick

Row {
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter

    property alias imageSource: rowImage.source
    property alias labelText: rowText.text

    Image {
        id: rowImage
        visible: true
        width: 25
        height: 25
    }

    Text {
        id: rowText
        font.pixelSize: 20
    }
}
