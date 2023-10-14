//
// Created by denis on 18.03.2023.
//

#include "Hero.h"

Hero::Hero() {
    health=10;
    defense=3;
    attack=3;
    exp = 0;
    lvl = 1;
    nextLvlExp=30;
    inventory = new Inventory();
}

int Hero::getExp()  {
    return exp;
}

int Hero::getLvl() {
    return lvl;
}

int Hero::getHeroY() {
    return y;

}

int Hero::getHeroX() {
    return x;
}

void Hero::setHeroX(int i) {
    x = i;
}

void Hero::setHeroY(int i) {
    y = i;
}

int Hero::getHealth() {
    return health;
}

int Hero::getDefense(){
    return defense + inventory->getItemDefense();
}

int Hero::getAttack(){
    return attack + inventory->getItemAttack();
}

void Hero::printInventory() {
    inventory->print();
}

void Hero::generateItem() {
    inventory->generateItem();
}

void Hero::fightEnemy(Enemy *enemy) {
    enemy->takeDamage(getAttack());
    takeDamage(enemy->attack());
}

void Hero::takeDamage(int attack) {
    attack -= getDefense();
    //check if the attack does damage
    if(attack > 0)
    {
        health -= attack;
        //check if we died
        if (health <=0)
        {
            health = 0;
        }
    }
}

void Hero::usePotion() {
     if(inventory->getNumberOfPotions()>0){
         health+=3;
         inventory->consumePotion();
     }
}

void Hero::addExp(int gainedExp) {
    if((gainedExp+exp)>=nextLvlExp){
        lvl+=1;
        attack+=3;
        defense+=3;
        nextLvlExp*=2;
        exp=0;
    }
    else{
        exp+=gainedExp;
    }
}

int Hero::getNextLvlExp() {
    return nextLvlExp;
}
