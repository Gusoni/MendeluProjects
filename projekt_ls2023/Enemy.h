//
// Created by Marian on 27.03.2023.
//

#ifndef PROJEKT_LS2023_ENEMY_H
#define PROJEKT_LS2023_ENEMY_H


class Enemy {

private:
    int m_health;
    int m_attack;
    int m_defense;
    int m_experience;
    int m_lvl;

public:
    Enemy(int lvl, int health, int attack, int defense, int experience);
    int attack();
    int takeDamage(int attack);


    int getHealth();

    int getMAttack();

    int getMDefense();

    int getExp();

    int getLvl();
};


#endif //PROJEKT_LS2023_ENEMY_H
