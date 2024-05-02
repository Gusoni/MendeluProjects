import QtQuick

Rectangle{
    id: map
    anchors.fill: parent
    visible: false
    anchors.centerIn: parent

    Grid{
        columns: 19
        rows: 19
        spacing: 0

        Repeater{
            id: repeater
            model: game.location.layout

            Tile{
                tileIndex: index
                gameObject: modelData
            }
        }

    }
}
