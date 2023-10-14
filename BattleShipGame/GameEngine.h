//
// Created by denis on 13.10.2023.
//

#ifndef BATTLESHIPGAME_GAMEENGINE_H
#define BATTLESHIPGAME_GAMEENGINE_H
#include "GameLogic.h"

class GameEngine {
    Loader* loader;  // Pointer to Loader
    GameLogic* logic;  // Pointer to GameLogic
    bool konec;
public:
    GameEngine(Loader* loader, GameLogic* logic);
    void play();
    void introForGame();
};


#endif //BATTLESHIPGAME_GAMEENGINE_H
