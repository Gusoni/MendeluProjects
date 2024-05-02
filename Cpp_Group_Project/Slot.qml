import QtQuick

Rectangle{
    property int tileIndex: 0
    property var gameObject

    width: 110
    height: 110
    color: "red"




    MouseArea{
        anchors.fill: parent
        onClicked: {
            print(tileIndex)

        }
    }

    function displayCorrectTile(type){
        switch(type){
        case "armor":
            armorTile.visible = true
            break
        case "weapon":
            weaponTile.visible = true
            break
        case "potion":
            potionTile.visible = true
            break
        default:
            armorTile.visible = false
            weaponTile.visible = false
            potionTile.visible = false
            break
        }
    }

    Image {
        id: defaultTile
        anchors.fill: parent
        source: "images/slot.png"
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



}
