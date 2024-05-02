import QtQuick

Rectangle {
    id: menu
    visible: true
    anchors.centerIn: parent

    Grid{
        anchors.centerIn: parent
        columns: 1
        rows: 4
        spacing: 10

        Repeater{
            model: ListModel {
                ListElement{
                    buttonId: "newGame"
                    mGameText: "New Game"
                }
                ListElement{
                    buttonId: "continueGame"
                    mGameText: "Continue"
                }
                ListElement{
                    buttonId: "optionsGame"
                    mGameText: "Options"
                }
                ListElement{
                    buttonId: "exitGame"
                    mGameText: "Exit"
                }
            }

            MenuButton{
                gameText: mGameText
            }
        }
    }
}
