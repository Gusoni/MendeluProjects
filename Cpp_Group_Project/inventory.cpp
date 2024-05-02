#include "inventory.h"

Inventory::Inventory(QObject *parent)
    : QObject{parent}
{
    initInventory();
    qDebug() << "Inventory created";
}

void Inventory::initInventory(){
    for(int i =0;i<20;i++ ){
         m_inventory_slots.push_back(new GameObject());
    }
    m_inventory_slots.at(5) = new Weapon();
    qDebug() << "Inventory: init inventory";
}


QVariant Inventory::getInventorySlots(){
      qDebug() << "Inventory: got inventory";
    return QVariant::fromValue(m_inventory_slots);

}

/*GameObject* Inventory::getFromInventory(int index){
    return m_inventory_slots.at(index);
}*/

void Inventory::addToInventory(GameObject* item) {

    auto pos = std::find_if(m_inventory_slots.begin(), m_inventory_slots.end(),
                            [](GameObject* slot) -> bool { return typeid(*slot) == typeid(GameObject); });

    if (pos != m_inventory_slots.end()) {
         std::size_t index = std::distance(m_inventory_slots.begin(), pos);
         m_inventory_slots.at(index) = item;
    }
}


void Inventory::removeFromInventory(int index){
    int indexToRemove = index;
    if(indexToRemove < m_inventory_slots.size()){
    m_inventory_slots.erase(m_inventory_slots.begin() + indexToRemove);
    } else{
    qDebug() << "Invalid index";
    }
}
