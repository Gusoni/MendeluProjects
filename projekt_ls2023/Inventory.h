//
// Created by denis on 09.04.2023.
//




#include <vector>
#include "Item.h"

class Inventory {
private:
    void generateInventoryItem();
    int potions;
    std::vector<Item*> items;
public:
    Inventory();

    void print();

    void generateItem();

    int getItemDefense();

    int getItemAttack();

    int getNumberOfPotions();

    void consumePotion();
};



