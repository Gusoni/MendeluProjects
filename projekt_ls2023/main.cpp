#include <conio.h>
#include "Menu.h"
#include "World.h"

int main() {

    Menu* menu = new Menu();
    menu->showMenu();
    World* world = new World();
    world->printMap();

    while (int input = _getch()) {
        if (input == 'q' || input == 'Q') {
            break;
        }
        if(world->isHeroDead()){
            world->printGameOver();
        }
        else if (input == 'm' || input == 'M') {
            menu->showMenu();
        }
        else if (input == 'i' || input == 'I') {
            world->showInventory();
        }
        else if (input == 'p' || input == 'P') {
            world->usePotion();
            world->printMap();
        }
        else {
            world->movePlayer(input);
            if(world->isHeroDead()){
                world->printGameOver();
            }
            else if(world->isClear()){
                world->printVictory();
            }
            else {
                world->printMap();
            }
        }
    }
    delete menu;
    delete world;
    return 0;

}