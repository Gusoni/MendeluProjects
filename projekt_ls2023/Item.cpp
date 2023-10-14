//
// Created by denis on 09.04.2023.
//

#include "Item.h"
#include <string>

const std::string &Item::getMItemName() const {
    return m_itemName;
}

void Item::setMItemName(const std::string &mItemName) {
    m_itemName = mItemName;
}

int Item::getMAttack() const {
    return m_attack;
}

void Item::setMAttack(int mAttack) {
    m_attack = mAttack;
}

int Item::getMDefense() const {
    return m_defense;
}

void Item::setMDefense(int mDefense) {
    m_defense = mDefense;
}

Item::Item(std::string itemName, int attack, int defense) {
    m_itemName=itemName;
    m_attack=attack;
    m_defense=defense;
}

std::string Item::getDescription() {
    return m_itemName;
}


