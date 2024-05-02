import QtQuick

Rectangle{
    property int tileIndex: 0
    width: 50
    height: 50
    color: "red"

    property var gameObject

    function displayCorrectTile(type){
        switch(type){
        case "player":
            playerTile.visible = true
            break
        case "monster":
            monsterTile.visible = true
            break
        case "armor":
            armorTile.visible = true
            break
        case "weapon":
            weaponTile.visible = true
            break
        case "npc":
            npcTile.visible = true
            break
        case "obstacle":
            obstacleTile.visible = true
            break
        case "potion":
            potionTile.visible = true
            break
        default:
            playerTile.visible = false
            monsterTile.visible = false
            armorTile.visible = false
            weaponTile.visible = false
            npcTile.visible = false
            obstacleTile.visible = false
            potionTile.visible = false
            break
        }
    }

    Image {
        id: defaultTile
        anchors.fill: parent
        source: "images/grass.png"
        visible: true
    }

    Image{
        id: armorTile
        anchors.fill: parent
        source: "images/armor.png"
        visible: gameObject.type === "armor"
    }

    Image{
        id: weaponTile
        anchors.fill: parent
        source: "images/weapon.png"
        visible: gameObject.type === "weapon"
    }

    Image{
        id: potionTile
        anchors.fill: parent
        source: "images/potion.png"
        visible: gameObject.type === "potion"
    }

    Image{
        id: monsterTile
        anchors.fill: parent
        source: "images/monster.png"
        visible: gameObject.type === "monster"
    }

    Image{
        id: npcTile
        anchors.fill: parent
        source: "images/npc.png"
        visible: gameObject.type === "npc"
    }

    Image{
        id: obstacleTile
        anchors.fill: parent
        source: "images/wall.png"
        visible: gameObject.type === "obstacle"
    }

    Image{
        id: playerTile
        anchors.fill: parent
        source: "images/player.png"
        visible: gameObject.type === "player"
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            print(tileIndex)
            /*location.layout[tileIndex].testP()      tohle sice bude na pozadi hazet error, ale v pripade ze kliknu na policko
                                                    kde by mel byt object Armor, tak se funkce provola a vypise neco do konzole */
            }

    Connections{
        target: game
        function onPlayerMoved(){
            //implementace zobrazeni spravnych img podle typu objektu
            displayCorrectTile(gameObject.type)
            }
        }
    }
}

