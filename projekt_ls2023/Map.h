//
// Created by terez on 11.03.2023.
//
#include <iostream>
#include <vector>
#include <string>
#include "Hero.h"
#include "Enemy.h"

class Map {
    std::vector<std::vector<std::string>> m_map;
    Hero *h;
    Enemy enemy;
    int m_width;
    int m_height;
public:
    explicit Map(Hero *h, int exitNum, Enemy enemy, bool isFirst);

    void printMap() ;
    int movePlayer(char direction);

    void generateMap(int, bool);

    void setHeroPosition();

    void generateObjectOnMap(int height, int width, char string);

    void printStats() ;

    void printAttributes(int health, int defense, int attack, int lvl, int exp, int nextLvlExp);

    void generateWalls(int exitNum, bool isFirst);

    int movePlayerOnMap(int new_x, int new_y);

    void movePlayerToFreeSpot(int new_x, int new_y);

    bool isEnemyDead();
};
