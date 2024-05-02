#include "player.h"

Player::Player(GameObject *parent,
               QString name, int strength, int defense,
               int level, int exp, int health)
    : GameObject{parent}, m_name{name}, m_strength{strength}, m_defense{defense},
    m_level{level}, m_exp{exp}, m_health{health}
{
    m_tile_position = 180;
    m_type = "player";
    m_inventory = new Inventory();
}

QString Player::getName() const {
    return m_name;
}

QString Player::getType() const {
    return m_type;
}

Inventory* Player::getInventory(){
    return m_inventory;

}
int Player::getHealth() const {
    return m_health;
}

int Player::getStrength() const {
    return m_strength;
}

int Player::getDefense() const {
    return m_defense;
}

int Player::getLevel() const {
    return m_level;
}

int Player::getExp() const {
    return m_exp;
}

int Player::getPosition() const{
    return m_tile_position;
}

void Player::setStrength(int strenght) {
    m_strength = strenght;
    emit strenghtChange();
}

void Player::setDefense(int defense) {
    m_defense = defense;
    emit defenseChange();
}

void Player::setQuest(Quest* quest) {
    m_quest = quest;
}

void Player::setInventory(Inventory* inventory) {
    m_inventory = inventory;
}

void Player::setExp(int exp) {
    m_exp = exp;
    emit expChange();
}

void Player::setPosition(int index){
    m_tile_position = index;
}

void Player::addLevel() {
    // funkce se provola po pridani exp, napr. po dokonceni ukolu.:S

    int minimalExp = 20;

    if (getExp() > minimalExp) {
        m_level += 1;
        m_exp -= minimalExp;
    }
}

QVariant Player::getEquippedItems(){
    return QVariant::fromValue(m_equipped_items);
}

void Player::setHealth(int health){
    m_health = health;
}

void Player::equipItem(GameObject* item){ //funkce neresi oddelani itemu z inventare po nasazeni!!!
    if(item->getType()=="weapon"){
        if(!(m_equipped_items.at(0) == nullptr)){
            m_inventory->addToInventory(m_equipped_items.at(0)); //presun momentalni equipped weapon zpatky do inventare
        }
        Weapon* sword = new Weapon(item);
        m_equipped_items.at(0) = sword; //zbran bude vzdy jenom na indexu 0 ve vektoru m_equipped_items
    }
    if(item->getType()=="armor"){
        if(!(m_equipped_items.at(1) == nullptr)){
            m_inventory->addToInventory(m_equipped_items.at(1));
        }
        Armor* chestplate = new Armor(item);
        m_equipped_items.at(1) = chestplate;
    }
}

void Player::fight(Monster* monster){
    int damage_to_monster = m_strength*(100/(100+monster->getDefense()));
    monster->setHealth(monster->getHealth()-damage_to_monster);

    int damage_to_player = monster->getAttack()*(100/(100+m_defense));
    this->setHealth(m_health-damage_to_player);

}
