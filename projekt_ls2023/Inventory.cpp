//
// Created by denis on 09.04.2023.
//

#include "Inventory.h"
#include <iostream>
#include <windows.h>

Inventory::Inventory() {
    potions=1;
    items.push_back(new Item("Basic sword", 1, 1));
}

void Inventory::print() {
    std::system("cls");
    for (int i = 0; i < items.size(); i++) {
        std::cout << items[i]->getMItemName();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        std::cout << " Attack: " + std::to_string(items[i]->getMAttack()) + " Defense: " + std::to_string(items[i]->getMDefense()) +"\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    }
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "Potions: " + std::to_string(potions);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Inventory::generateItem() {
    if((rand() % 3) == 0){
        potions+=1;
    } else {
        generateInventoryItem();
    }
}

void Inventory::generateInventoryItem() {
    int attack=rand() % 4;
    int defense = rand() % 4;
    std::string item_name="";
    if(attack>0 && defense>0){
        item_name="Ultimate scroll";
    }
    else if(attack>0){
        item_name="Apple of power";
    }
    else if(defense>0){
        item_name="Piece of armor";
    }
    else {
        item_name = "Lucky socks";
    }
    Item* item = new Item(item_name, attack, defense);
    items.push_back(item);
}

int Inventory::getItemDefense() {
    int defense = 0;
    for (int i = 0; i < items.size(); i++) {
        defense+=items[i]->getMDefense();
    }
    return defense;
}

int Inventory::getItemAttack() {
    int attack = 0;
    for (int i = 0; i < items.size(); i++) {
        attack+=items[i]->getMAttack();
    }
    return attack;
}

int Inventory::getNumberOfPotions() {
    return potions;
}

void Inventory::consumePotion() {
    potions-=1;
}


