#include "weapon.h"

Weapon::Weapon(GameObject *parent, int attack, float crit)
    : GameObject{parent}, m_attack{attack}, m_critical_chance{crit}
{
    qDebug() << m_attack;
    m_type = "weapon";
}

int Weapon::getAttack(){
    return m_attack;
}

float Weapon::getCrit(){
    return m_critical_chance;
}

void Weapon::setAttack(int attack){
    m_attack = attack;
}

void Weapon::setCrit(float crit){
    m_critical_chance = crit;
}

QString Weapon::getType() const{
    return m_type;
}
