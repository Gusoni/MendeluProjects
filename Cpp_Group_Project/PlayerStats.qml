import QtQuick

Rectangle {
    id: playerStatsWrapper
    anchors.right: gameMap.right
    width: 550
    height: 510
    visible: false
    color: "#ecffe0"
    property var playerName
    property var playerHealth
    property var playerStrength
    property var playerDefense

    Column {
        anchors.fill: parent
        anchors.topMargin: 50
        spacing: 15

        Image {
            id: playerIcon
            anchors.horizontalCenter: parent.horizontalCenter
            source: "images/player.png"
            visible: true
            width: 100
            height: 100
        }

        Text {
            id: playerNameId
            font.pixelSize: 30
            anchors.horizontalCenter: playerIcon.horizontalCenter
        }

        StatsRow {
            imageSource: "images/heart.png"
            labelText: "Počet životů: " + playerHealth
        }

        StatsRow {
            imageSource: "images/weapon.png"
            labelText: "Síla: " + playerStrength
        }

        StatsRow {
            imageSource: "images/armor.png"
            labelText: "Obrana: " + playerDefense
        }

        // bez BE, pozdeji tu bude equippedArmor
        Row {
            spacing: 5
            anchors.horizontalCenter: parent.horizontalCenter

                Rectangle {
                    width: 50
                    height: 50
                    color: "transparent"
                    border.color: "black"
                    border.width: 2
                    radius: 5

                    Image {
                        anchors.fill: parent
                        source: "images/armor.png"
                        visible: true
                    }
                }

                Rectangle {
                    width: 50
                    height: 50
                    color: "transparent"
                    border.color: "black"
                    border.width: 2
                    radius: 5

                    Image {
                        anchors.fill: parent
                        source: "images/armor.png"
                        visible: true
                    }
                }

                Rectangle {
                    width: 50
                    height: 50
                    color: "transparent"
                    border.color: "black"
                    border.width: 2
                    radius: 5

                    Image {
                        anchors.fill: parent
                        source: "images/armor.png"
                        visible: true
                    }
                }

                Rectangle {
                    width: 50
                    height: 50
                    color: "transparent"
                    border.color: "black"
                    border.width: 2
                    radius: 5

                    Image {
                        anchors.fill: parent
                        source: "images/armor.png"
                        visible: true
                    }
                }

        }
    }

    function displayStats() {
        playerName = game.player.name
        playerHealth = game.player.health
        playerStrength = game.player.strength
        playerDefense = game.player.defense

        playerNameId.text = playerName
    }


    Connections {
        target: game
        function onAllLocationsGenerated() {
            displayStats();
        }
    }
}

