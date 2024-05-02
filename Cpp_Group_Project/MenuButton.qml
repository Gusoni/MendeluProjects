import QtQuick

Rectangle{
    property alias gameText: myText.text;

    id: menuButton
    width: 200
    height: 40
    color: "red"

    Text {
        id: myText
        text: "button"
        font.pixelSize: 20
        color: "white"

        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (buttonId === "newGame") {
                print("newGame click")
                gameMenu.visible = false
                gameMap.visible = true
                playerStats.visible = true
                game.startNewGame()
                gameMovement.focus = true
                playerInventory.visible = true
            }
            if (buttonId === "continueGame") {
                print("continueGame click")
            }
            if (buttonId === "optionsGame") {
                print("optionsGame click")
            }
            if (buttonId === "exitGame") {
                Qt.quit()
            }
        }
    }
}
