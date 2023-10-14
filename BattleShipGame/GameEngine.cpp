//
// Created by denis on 13.10.2023.
//

#include "GameEngine.h"

GameEngine::GameEngine(Loader* loader, GameLogic* logic) : loader(loader), logic(logic) {
    konec = logic->vyhodnotKonec();
}

void GameEngine::play() {
    int x, y;
    introForGame();
    while (!konec) {
        std::cout << "Zadej souradnici radku: ";
        std::cin >> x;
        std::cout << "Zadej souradnici sloupce: ";
        std::cin >> y;
        loader->printMapForPlayer();
        logic->strel(x, y);
        konec = logic->vyhodnotKonec();  // Update konec based on the game logic
    }
    loader->printMap();
}

void GameEngine::introForGame() {
    std::cout << "Celkove je ve hre " << loader->getNumberOfShips() << " casti lodi.\n" << std::endl;
    std::cout << "Cilem hry je zniceni nepratelskych lodich" << std::endl;
    std::cout << "Pro ukonceni hry stiskni q\nPro hru pozij souradnice ve tvaru cisel" << std::endl;
    std::cout << "Mas: " << logic->getPocetKol() << " pokusu o utok nez nas nepratele znici" << std::endl;
}




