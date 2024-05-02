#include "obstacle.h"

Obstacle::Obstacle()
{
    m_type = "obstacle";
}

QString Obstacle::getType() const{
    return m_type;
}
