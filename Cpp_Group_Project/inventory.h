#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QVariant>
#include "vector"
#include "gameobject.h"
#include "weapon.h"

class Inventory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant inventory READ getInventorySlots CONSTANT)
 //   Q_PROPERTY(GameObject* inventorySlot READ getFromInventory NOTIFY inventoryChanged)
public:
    explicit Inventory(QObject *parent = nullptr);
    QVariant getInventorySlots();
    void addToInventory(GameObject* item);
    Q_INVOKABLE void removeFromInventory(int index);
   // Q_INVOKABLE GameObject* getFromInventory(int index);
private:
    std::vector<GameObject*> m_inventory_slots;
    void initInventory();

signals:
    void inventoryChanged();

};

#endif // INVENTORY_H
