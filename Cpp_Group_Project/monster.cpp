#include "monster.h"

Monster::Monster(GameObject *parent, int health, int attack, int defense, QString name)
    : GameObject{parent}, m_health{health}, m_attack{attack}, m_defense{defense}, m_name{name}
{
    m_type = "monster";
}



int Monster::getHealth() const {
    return m_health;
}

int Monster::getAttack() const {
    return m_attack;
}

int Monster::getDefense() const {
    return m_defense;
}

QString Monster::getName() const {
    return m_name;
}

QString Monster::getType() const{
    return m_type;
}

void Monster::setInventory(Inventory* inventory) {
    m_inventory = inventory;
}

void Monster::setHealth(int health){
    m_health = health;
}
