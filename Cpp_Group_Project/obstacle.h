#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>

#include "gameobject.h"

class Obstacle: public GameObject
{
    Q_OBJECT
public:
    Obstacle();
    QString getType() const override;
private:
    QString m_type;
};

#endif // OBSTACLE_H
