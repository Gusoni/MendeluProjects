//
// Created by denis on 18.03.2023.
//

#ifndef MAIN_CPP_HERO_H
#define MAIN_CPP_HERO_H


#include "Inventory.h"
#include "Enemy.h"

class Hero {
    int health;
    int defense;
    int attack;
    int exp;
    int nextLvlExp;
    int lvl;
    int x;
    int y;
    Inventory* inventory;
public:
    Hero();

    int getHealth();

    int getDefense();

    int getAttack();

    int getHeroY();
    int getHeroX();

    void setHeroX(int i);

    void setHeroY(int i);

    void printInventory();

    void generateItem();

    void fightEnemy(Enemy *enemy);

    void takeDamage(int attack);

    void usePotion();

    int getExp() ;

    int getLvl() ;

    void addExp(int i);

    int getNextLvlExp();
};


#endif //MAIN_CPP_HERO_H
