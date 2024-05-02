#ifndef POTION_H
#define POTION_H

#include <QObject>
#include "gameobject.h"
#include <QVariant>
#include "player.h"

class Potion : public GameObject
{
    Q_OBJECT
public:
    explicit Potion(GameObject *parent = nullptr, int healing = 0);
    int getHealing() const;
    void setHealing(int healing);
    QString getType() const override;
    void use(Player* hero);
private:
    int m_healing;
    QString m_type;
signals:

};

#endif // POTION_H
