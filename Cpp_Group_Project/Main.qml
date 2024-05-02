import QtQuick
import QtQuick.Window

Window {
    width: 1500
    height: 950
    visible: true
    title: qsTr("Cpp Projekt - HRA")

    Image {
        id: homeScreen
        anchors.fill: parent
        anchors.centerIn: parent
        source: "images/homescreen.png"
    }

    Rectangle {
        id: gameMovement
        anchors.fill: parent
        visible: false
        focus: false

        Keys.onPressed: {
            switch(event.key){
            case Qt.Key_W:
                print("pressed W button - Pohyb nahoru")
                game.movePlayer(1)
                break
            case Qt.Key_A:
                print("pressed A button - Pohyb doleva")
                print("")
                game.movePlayer(2)
                break
            case Qt.Key_S:
                print("pressed S button - Pohyb dolů")
                game.movePlayer(3)
                break
            case Qt.Key_D:
                print("pressed D button - Pohyb doprava")
                game.movePlayer(4)
                break
            case Qt.Key_I:
                print("pressed I button - Inventář")
                break
            case Qt.Key_Escape:
                print("pressed ESC button - Pozastav hru")
                gameMenu.visible = true
                gameMap.visible = false
                playerStats.visible = false
                focus = false
                break
            default:
                break
            }
        }
    }

    Menu {
        id: gameMenu
    }

    Location{
        id: gameMap

    }

    PlayerStats {
        id: playerStats
    }

    Inventory{
        id: playerInventory
    }
}
