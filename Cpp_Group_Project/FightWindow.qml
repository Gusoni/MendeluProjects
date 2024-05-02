import QtQuick

Rectangle {
    width: 450
    height: 350
    visible: false
    x: 300
    y: 450
    radius: 10
    border.color: "black"
    border.width: 2
    property var playerName
    property var playerHealth
    property var playerStrength
    property var playerDefense
    property var playerLevel

    property var monsterName
    property var monsterHealth
    property var monsterStrength
    property var monsterDefense
    property var monsterLevel


    Grid {
        columns: 2
        rows: 5
        spacing: 10
        anchors.centerIn: parent

        Text {
            font.pixelSize: 30
            text: "Hráč " + playerName
        }

        Text {
            font.pixelSize: 30
            text: "Hráč " + monsterName
        }

        Text {
            font.pixelSize: 30
            text: "Level " + playerLevel
        }

        Text {
            font.pixelSize: 30
            text: "Level " + monsterLevel
        }

        Text {
            font.pixelSize: 30
            text: "Život " + playerHealth
        }

        Text {
            font.pixelSize: 30
            text: "Život " + monsterHealth
        }

        Text {
            font.pixelSize: 30
            text: "Útok " + playerStrength
        }

        Text {
            font.pixelSize: 30
            text: "Útok " + monsterStrength
        }

        Text {
            font.pixelSize: 30
            text: "Obrana " + playerDefense
        }

        Text {
            font.pixelSize: 30
            text: "Obrana " + monsterDefense
        }
    }


    function displayStats() {
        playerName = game.player.name
        playerHealth = game.player.health
        playerStrength = game.player.strength
        playerDefense = game.player.defense
        playerLevel = game.player.level

        monsterName = game.monster.name
        monsterHealth = game.monster.health
        monsterStrength = game.monster.strength
        monsterDefense = game.monster.defense
        monsterLevel = game.monster.level
    }


    Connections {
        target: game
        function onCheckDirectionForInteraction() {
            displayStats();
        }
    }
}
