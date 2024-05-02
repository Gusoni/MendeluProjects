#ifndef MONSTER_H
#define MONSTER_H
#include "gameobject.h"
#include <QObject>
#include <QVariant>
#include <QString>
#include <iostream>
#include "gameobject.h"
#include "inventory.h"
#include "quest.h"

class Monster : public GameObject
{
    Q_OBJECT
    Q_PROPERTY(int health READ getHealth NOTIFY healthChange)
    Q_PROPERTY(int attack READ getAttack NOTIFY attackChange)
    Q_PROPERTY(int defense READ getDefense NOTIFY defenseChange)
    Q_PROPERTY(QString name READ getName CONSTANT)
public:
    explicit Monster(GameObject *parent = nullptr,
                     int health = 0, int attack = 0, int defense = 0, QString name = "");

    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    QString getName() const;
    QString getType() const override;


    void setInventory(Inventory* inventory);
    void setHealth(int health);

private:
    int m_health;
    int m_attack;
    int m_defense;
    QString m_name;
    QString m_type;

    Inventory* m_inventory;


signals:
    void healthChange();
    void attackChange();
    void defenseChange();
};

#endif // MONSTER_H
