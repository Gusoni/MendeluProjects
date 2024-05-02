#include "potion.h"

Potion::Potion(GameObject *parent, int healing)
    : GameObject{parent}, m_healing{healing}
{
    m_healing = 10;
    m_type = "potion";
}

int Potion::getHealing() const{
    return m_healing;
}

void Potion::setHealing(int healing){
    this->m_healing = healing;
}

QString Potion::getType() const{
    return m_type;
}

void Potion::use(Player* hero){

}
