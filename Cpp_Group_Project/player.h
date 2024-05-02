#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <iostream>
#include "gameobject.h"
#include "inventory.h"
#include "quest.h"
#include "weapon.h"
#include "armor.h"
#include "monster.h"

class Player : public GameObject
{
    Q_OBJECT
    Q_PROPERTY(int health READ getHealth NOTIFY healthChange)
    Q_PROPERTY(int strength READ getStrength NOTIFY strenghtChange)
    Q_PROPERTY(int defense READ getDefense NOTIFY defenseChange)
    Q_PROPERTY(int level READ getLevel NOTIFY levelChange)
    Q_PROPERTY(int exp READ getExp NOTIFY expChange)
    Q_PROPERTY(QString name READ getName NOTIFY nameChange)


public:
    explicit Player(GameObject *parent = nullptr,
                    QString name = "", int strength = 0, int defense = 0,
                    int level = 0, int exp = 0, int health = 100);

    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    int getLevel() const;
    int getExp() const;
    int getPosition() const;
    QString getName() const;
    QString getType() const override;
    Inventory* getInventory();
    QVariant getEquippedItems();
    Q_INVOKABLE void equipItem(GameObject* item);


    void setStrength(int strenght);
    void setHealth(int health);
    void setDefense(int defense);
    void setExp(int exp);
    void setQuest(Quest* quest);
    void setInventory(Inventory* quest);
    void setPosition(int index);

    void addLevel();
    void fight(Monster* monster);

private:
    int m_health;
    int m_strength;
    int m_defense;
    int m_level;
    int m_exp;
    QString m_name;
    QString m_type;

    Inventory* m_inventory;
    Quest* m_quest;
    std::vector<GameObject*> m_equipped_items;


signals:
    // vsechny zmeny se budou propisovat ve hre
    void healthChange();
    void strenghtChange();
    void defenseChange();
    void levelChange();
    void expChange();
    void nameChange();

};

#endif // PLAYER_H
