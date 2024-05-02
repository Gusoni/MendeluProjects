#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <QVariant>

#include <vector>

#include "location.h"
#include "player.h"

class World : public QObject
{
    Q_OBJECT
private:
    std::vector<Location*> m_locations;
    Location* m_currentLocation;
public:
    explicit World(QObject *parent = nullptr);

    Location* getLocationByIndex(int index) const;
    std::vector<Location*> getAllLocations() const;
    Location* getCurrentLocation() const;

    void changeCurrentLocation(int directionNewIndex, Player* player, int oldPos);
    // TODO udělat funkci na zmenu currentLocations pošle se index směru a podle toho se udělá logika kam se pohne v rámci mapy
signals:
};

#endif // WORLD_H
