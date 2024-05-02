#include "armor.h"

Armor::Armor(GameObject *parent, int def)
    : GameObject{parent}, m_defense{def}
{
    m_type = "armor";
}

int Armor::getDefense(){
    return m_defense;
}

void Armor::setDefense(int defense){
    m_defense = defense;
}

QString Armor::getType() const{
    return m_type;
}
