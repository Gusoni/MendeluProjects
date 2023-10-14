//
// Created by Marian on 27.03.2023.
//
#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(int lvl, int health, int attack, int defense, int experience)
{

    m_attack = attack;
    m_defense = defense;
    m_health = health;
    m_experience = experience;
    m_lvl = lvl;
}

int Enemy::takeDamage(int attack)
{
    attack -= getMDefense();
    //check if the attack does damage
    if(attack > 0)
    {
        m_health -= attack;
        //check if he died
        if (m_health <=0)
        {
            return m_experience;
        }
    }
    return 0;
}

int Enemy::attack()
{
    // random attack chance engine
    static std::default_random_engine randomEngine(time(NULL));
    std::uniform_int_distribution<int> attackRoll(0, getMAttack());

    return attackRoll(randomEngine);
}

int Enemy::getHealth() {
    return m_health;
}

int Enemy::getMAttack()  {
    return m_attack + m_lvl;
}

int Enemy::getMDefense()  {
    return m_defense + m_lvl;
}

int Enemy::getExp() {
    return m_experience  + m_lvl*5;
}

int Enemy::getLvl() {
    return m_lvl;
}
