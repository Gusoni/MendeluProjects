#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QVariant>

#include <vector>

#include "world.h"
#include "location.h"
#include "gameobject.h"
#include "player.h"
#include "cctype"

class GameEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant player READ getPlayer CONSTANT)
    Q_PROPERTY(Location* location READ getCurrentLocation NOTIFY locationChanged)
    Q_PROPERTY(Inventory* playerInventory READ getPlayerInventory CONSTANT)

private:
    World* m_world;
    Player* m_player;
    std::vector<GameObject*> m_entities;
public:
    explicit GameEngine(QObject *parent = nullptr);

    Q_INVOKABLE void startNewGame();


    Q_INVOKABLE Location* getCurrentLocation() const;

    QVariant getPlayer() const;

    Q_INVOKABLE void movePlayer(int direction);

    Q_INVOKABLE QString determineTileObject(Location* loc, int index);

    void changeLocation(int direction, int tileInd);

    Q_INVOKABLE Inventory* getPlayerInventory() const;

private:
    bool checkDirectionForObstacles(Location* loc, int directionIndex);
    void checkDirectionForInteraction(Location* loc, int directionIndex);
signals:
    void allLocationsGenerated();
    void locationChanged();
    void playerMoved();
};

#endif // GAMEENGINE_H
