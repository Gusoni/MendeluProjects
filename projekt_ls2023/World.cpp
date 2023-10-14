//
// Created by denis on 08.04.2023.
//

#include "World.h"
#include <windows.h>

World::World() {
    h = new Hero();
    currentPosition = 0;
    Map* newMap = new Map(h, 1, generateEnemy(), true);
    m_world.push_back(newMap);
}

Enemy World::generateEnemy() {
    return Enemy(currentPosition+1, rand()%20+1, rand()%15+1, rand()%10, rand()%100);
}

void World::printMap() {
    m_world.at(currentPosition)->printMap();
}

void World::movePlayer(int i) {
    int decision = m_world.at(currentPosition)->movePlayer(i);
    if (decision == 1) {
        if(m_world.size() <= currentPosition+1){
            if(currentPosition == 9){
                m_world.push_back(new Map(h, 1, generateEnemy(),false));
            }else {
                m_world.push_back(new Map(h, 2, generateEnemy(), false));
            }
        }
        currentPosition+=1;
        m_world.at(currentPosition)->setHeroPosition();
    }
    if (decision == -1) {
        currentPosition-=1;
        m_world.at(currentPosition)->setHeroPosition();
    }
}

void World::showInventory() {
    h->printInventory();
}

void World::usePotion() {
    h->usePotion();
}

bool World::isHeroDead() {
    return h->getHealth()<=0;
}

void World::printGameOver() {
    std::system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout<<"Game Over";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

bool World::isClear() {
    return currentPosition == 10 && m_world.at(currentPosition)->isEnemyDead();
}

void World::printVictory() {
    std::system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout<<"VICTORY";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
