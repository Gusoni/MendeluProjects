#ifndef NPC_H
#define NPC_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <vector>
#include "gameobject.h"
#include "quest.h"
#include "inventory.h"
class NPC : public GameObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant quest READ getQuests CONSTANT)
    Q_PROPERTY(QVariant inventory READ getInventory CONSTANT)
public:
    explicit NPC(GameObject *parent = nullptr, QString name = "");
    void interact();

private:
    std::vector<Quest*> m_questList;
    Inventory* m_inventory;
    QString m_name;
    QString m_type;

    QString getName() const;
    QString getType() const override;
    QVariant getQuests() const;
    QVariant getInventory() const;

    void pushQuest(Quest* quest);
    void setInventory(Inventory* inventory);

signals:

};

#endif // NPC_H
