#include "world.h"

World::World(QObject *parent)
    : QObject{parent}
{
    const int layoutSize = 5;
    const int totalSize = layoutSize * layoutSize;

    for(int i = 0; i < totalSize; i++){
        Location* newLoc = new Location(i);
        m_locations.push_back(newLoc);
    }
    m_currentLocation = m_locations.at(0);
    qDebug("World: konstr");
}

Location* World::getLocationByIndex(int index) const{
    qDebug("World: GetLocByID");
    return m_locations.at(index);
}

std::vector<Location*> World::getAllLocations() const{
    return m_locations;
}

Location* World::getCurrentLocation() const{
    return m_currentLocation;
}

void World::changeCurrentLocation(int directionNewIndex, Player* player, int oldPos) {
    qDebug() << "World: adresa current location";
    qDebug() << m_currentLocation;
    qDebug() << "World: vektor location adres !PRED!";
    qDebug() << m_locations;
    auto it = std::find(m_locations.begin(), m_locations.end(), m_currentLocation);
    int currentIndex = std::distance(m_locations.begin(), it);
    int newIndex = currentIndex + directionNewIndex;
    qDebug("World: Nový world Index - %d", newIndex);
    if (newIndex >= 0 && newIndex < m_locations.size()) {
        Location* newLocation = m_locations.at(newIndex);
        if (newLocation) {
            m_currentLocation->insertEntity(oldPos, new GameObject()); // Vložení prázdného objektu na starou pozici hráče
            m_currentLocation = newLocation;
            qDebug() << "World: adresa new current location";
            qDebug() << m_currentLocation;
            int newPos = player->getPosition();
            qDebug("World: Nová pozice index - %d", newPos);
            newLocation->insertEntity(newPos, player);
            qDebug() << "World: vektor location adres !PO!";
            qDebug() << m_locations;
        }
    }
}
