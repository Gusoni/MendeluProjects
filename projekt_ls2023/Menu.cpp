//
// Created by tomas on 27.03.2023.
//

#include "Menu.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

Menu::Menu() {
    choise = 0;
    menu = { "Play", "Info", "Controls" };
}

void Menu::showMenu() {
    choise = 0;
    printMenu();

    while (int character = _getch()) {
        if (character == 'W' || character == 'w') {
            choise--;
            if (choise < 0) {
                choise = 2;
            }
        }
        if (character == 'S' || character == 's') {
            choise++;
            if (choise > 2) {
                choise = 0;
            }
        }
        if (character == VK_RETURN && choise == 0 || character == 'q' || character == 'Q') {
            break;
        }
        printMenu();
        printMenuOption();
    }
}

void Menu::printMenu() {
    std::system("cls");
    std::cout << " - Dungeon -\n\n";

    for (int i = 0; i < menu.size(); i++) {
        if (choise == i) {
            std::cout << " >> ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            std::cout << menu[i];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            std::cout << " << " << "\n";
        } else {
            std::cout << "    " << menu[i] << "    " << "\n";
        }
    }

    std::cout << "\nNavigate menu with W, S and ENTER.";
}

void Menu::printMenuOption() {
    if(choise == 1) {
        std::cout << "\nCreated by Tomas, Marian , Tereza, Denisa.\n\n";
    }
    if(choise == 2) {
        std::cout << "\nYou can move using W, A, S, D.";
        std::cout << "\nYou can show inventory using I.";
        std::cout << "\nYou can use potion using P.";
        std::cout << "\nYou can quit game after play using Q.";
    }
}


