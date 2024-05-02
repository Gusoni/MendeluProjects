#include "npc.h"

NPC::NPC(GameObject *parent, QString name)
    : GameObject{parent}, m_name{name}
{
    m_type = "npc";
}

QString NPC::getName() const {
    return m_name;
}

QString NPC::getType() const{
    return m_type;
}

QVariant NPC::getQuests() const {
    return QVariant::fromValue(m_questList);
}

QVariant NPC::getInventory() const {
    return QVariant::fromValue(m_inventory);
}

void NPC::pushQuest(Quest* quest) {
    m_questList.push_back(quest);
}
void NPC::setInventory(Inventory* inventory) {
    m_inventory = inventory;
}

void NPC::interact(){
    qDebug()<< "NPC: interacting with NPC";
}
