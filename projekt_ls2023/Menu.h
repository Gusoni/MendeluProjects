//
// Created by tomas on 27.03.2023.
//

#ifndef PROJEKT_TEST_MENU_H
#define PROJEKT_TEST_MENU_H


#include <vector>
#include <string>

class Menu {
    int choise;
    std::vector<std::string> menu;
public:
    Menu();
    void printMenu();

    void printMenuOption();

    void showMenu();
};




#endif //PROJEKT_TEST_MENU_H
