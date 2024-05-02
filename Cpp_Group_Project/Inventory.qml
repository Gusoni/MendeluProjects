import QtQuick

Rectangle{
    id: inventory
    visible: false

    anchors{
        top: playerStats.bottom
        left: playerStats.left
    }



    Grid{
        columns: 5
        rows: 4
        spacing: 1


        Repeater{
            id: repeater
            model: game.playerInventory.inventory

            Slot{
            tileIndex: index
            gameObject: modelData
            }


        }

    }
}
