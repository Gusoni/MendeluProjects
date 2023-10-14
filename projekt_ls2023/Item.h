//
// Created by denis on 09.04.2023.
//

#include <string>

class Item {
    std::string m_itemName;
    int m_attack;
    int m_defense;
public:
    Item(std::string itemName, int attack, int defense);

    std::string getDescription();

    const std::string &getMItemName() const;

    void setMItemName(const std::string &mItemName);

    int getMAttack() const;

    void setMAttack(int mAttack);

    int getMDefense() const;

    void setMDefense(int mDefense);


};

