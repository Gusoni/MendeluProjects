//
// Created by denis on 08.04.2023.
//

#include <vector>
#include "Map.h"

class World {
public:
    World();

    void printMap();

    void movePlayer(int i);

    void showInventory();

    void usePotion();

    bool isHeroDead();

    void printGameOver();

    bool isClear();

    void printVictory();

private:
    std::vector<Map*> m_world;
    int currentPosition;
    Hero* h;

    Enemy generateEnemy() ;
};



