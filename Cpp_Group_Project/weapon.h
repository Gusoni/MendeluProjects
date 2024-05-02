#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include "gameobject.h"
#include <QVariant>
#include <QDebug>
class Weapon : public GameObject
{
    Q_OBJECT
public:
    explicit Weapon(GameObject *parent = nullptr, int attack = 0, float crit = 0);
    int getAttack();
    float getCrit();
    void setAttack(int attack);
    void setCrit(float crit);
    QString getType() const override;
private:
    int m_attack;
    float m_critical_chance;
    QString m_type;
signals:



};

#endif // WEAPON_H
