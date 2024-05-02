#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>
#include <QVariant>

#include <vector>
#include <random>

#include "gameobject.h"
#include "player.h"
#include "obstacle.h"
#include "monster.h"
#include "npc.h"
#include "armor.h"
#include "weapon.h"
#include "potion.h"


class Location : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant layout READ getLayout CONSTANT)
private:
    std::vector<GameObject*> m_layout;
public:
    explicit Location(QObject *parent = nullptr);
    Location(int index);
    QVariant getLayout();
    void insertEntity(int index, GameObject* object);

    void updatePlayerLocation(int targetloc, Player* player);
    GameObject* getLayoutObject(int index);
signals:
};

#endif // LOCATION_H
