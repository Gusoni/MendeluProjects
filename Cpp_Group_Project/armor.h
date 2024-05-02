#ifndef ARMOR_H
#define ARMOR_H

#include <QObject>
#include <iostream>
#include "gameobject.h"
#include <QVariant>

class Armor : public GameObject
{
    Q_OBJECT

public:
    explicit Armor(GameObject *parent = nullptr, int def = 0);

    int getDefense();
    void setDefense(int defense);
    QString getType() const override;

private:
    int m_defense;
    QString m_type;

signals:

};

#endif // ARMOR_H
