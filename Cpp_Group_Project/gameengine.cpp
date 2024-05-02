#include "gameengine.h"

GameEngine::GameEngine(QObject *parent)
    : QObject{parent}
{
    m_world = new World();
    GameObject* parentplayer = new GameObject();
    Player* hero = new Player(parentplayer, "Bob",1,2,3,4,5);
    m_player = hero;
    m_entities.push_back(hero);
}

void GameEngine::startNewGame(){
    qDebug("GameEngine - startNewGame funkce");
    std::cout << "GameEngine: Pocet lokaci "<< m_world->getAllLocations().size() << std::endl;


    getCurrentLocation()->insertEntity(m_player->getPosition(), m_player); //vlozi do lokace s indexem 0 na druhe policko hrdinu

    emit allLocationsGenerated();
    emit locationChanged();
}

Location* GameEngine::getCurrentLocation() const{
    qDebug("GameEngine: getCurrentLocation");
    return m_world->getCurrentLocation();
}

void GameEngine::movePlayer(int direction){
    qDebug() << "GameEngine: move hero locations print";
    qDebug() << m_world->getAllLocations();
    int key = direction;
    switch(key){
    case 1:
        checkDirectionForInteraction(getCurrentLocation(), -19);
        if(checkDirectionForObstacles(getCurrentLocation(), m_player->getPosition()-19)){
            // TODO checknout pokud nebude obstacle, tak zda je to kraj mapy -> přesun na novou lokaci nebo zda tam je nějaká entita -> interakce s entitou pak
            if((m_player->getPosition()-19) < 19){
                // TODO zmenit lokace
                changeLocation(-5, 304);
                qDebug() << "GameEngine: Presun na novou currentLocation ve smeru -5 v ramci indexu lokaci";
            }else{
                getCurrentLocation()->updatePlayerLocation(m_player->getPosition()-19, m_player);
                m_player->setPosition(m_player->getPosition()-19);
                qDebug() << "GameEngine: w is working";
            }
        }
        break;
    case 2:
        checkDirectionForInteraction(getCurrentLocation(), -1);
        if(checkDirectionForObstacles(getCurrentLocation(), m_player->getPosition()-1)){
            // TODO checknout pokud nebude obstacle, tak zda je to kraj mapy -> přesun na novou lokaci nebo zda tam je nějaká entita -> interakce s entitou pak
            if((m_player->getPosition()-1) % 19 == 0){
                // TODO zmenit lokace
                changeLocation(-1, 16);
                qDebug() << "GameEngine: Presun na novou currentLocation ve smeru -1 v ramci indexu lokaci";
            }else{
                getCurrentLocation()->updatePlayerLocation(m_player->getPosition()-1, m_player);
                m_player->setPosition(m_player->getPosition()-1);
                qDebug() << "GameEngine: a is working";
            }
        }
        break;
    case 3:
        checkDirectionForInteraction(getCurrentLocation(), 19);
        if(checkDirectionForObstacles(getCurrentLocation(), m_player->getPosition()+19)){
            // TODO checknout pokud nebude obstacle, tak zda je to kraj mapy -> přesun na novou lokaci nebo zda tam je nějaká entita -> interakce s entitou pak
            if((m_player->getPosition()+19) > 342){
                // TODO zmenit lokace
                changeLocation(+5, -304);
                qDebug() << "GameEngine: Presun na novou currentLocation ve smeru +5 v ramci indexu lokaci";
            }else{

                getCurrentLocation()->updatePlayerLocation(m_player->getPosition()+19, m_player);
                m_player->setPosition(m_player->getPosition()+19);
                qDebug() << "GameEngine: s is working";
            }
        }
        break;
    case 4:
        checkDirectionForInteraction(getCurrentLocation(), 1);
        if(checkDirectionForObstacles(getCurrentLocation(), m_player->getPosition()+1)){
            // TODO checknout pokud nebude obstacle, tak zda je to kraj mapy -> přesun na novou lokaci nebo zda tam je nějaká entita -> interakce s entitou pak
            if((m_player->getPosition()+1) % 19 == 18){
                // TODO zmenit lokace
                changeLocation(1, -16);
                qDebug() << "GameEngine: Presun na novou currentLocation ve smeru +1 v ramci indexu lokaci";
            }else{

                getCurrentLocation()->updatePlayerLocation(m_player->getPosition()+1, m_player);
                m_player->setPosition(m_player->getPosition()+1);
                qDebug() << "GameEngine: d is working";
            }
        }
        break;
    default:
        qDebug() << "GameEngine: wrong key = " << key;
    }
    emit playerMoved();
    emit locationChanged();
}

bool GameEngine::checkDirectionForObstacles(Location* loc, int directionIndex){
    QVariant objectType = loc->getLayoutObject(directionIndex)->getType();
    if(objectType != "obstacle" && objectType != "npc"){
        return true; // Neni obstacle
    }
    return false;    // Je obstacle
}

void GameEngine::checkDirectionForInteraction(Location* loc, int directionIndex){
    GameObject* temp = getCurrentLocation()->getLayoutObject(m_player->getPosition()+directionIndex);
    QString type = temp->getType();
    //doplnit u vsech metody ktere se provedou
    if(type == "monster"){
        Monster(temp);
        //vytvorit funkci combat a ten system mno xd
        qDebug()<<"GameEngine: monster was found";
    }
    if(type == "potion"){
        Potion* pointer = new Potion(temp); //inventar jenom prijima pointery na itemy a ne ty itemy, proto musim vytvorit pointer xdddd
        m_player->getInventory()->addToInventory(pointer);

        qDebug()<<"GameEngine: potion was found";
    }
    if(type == "npc"){
        NPC* pointer = new NPC(temp);
        pointer->interact();
        qDebug()<<"GameEngine: npc was found";
    }
    if(type == "weapon"){
        Weapon* pointer = new Weapon(temp);
        m_player->getInventory()->addToInventory(pointer);
        qDebug()<<"GameEngine: weapon was found";
    }
}

QString GameEngine::determineTileObject(Location* loc, int index){
    return loc->getLayoutObject(index)->getType();
}


QVariant GameEngine::getPlayer() const {
    qDebug()<<"GameEngine: getPlayer";
    return QVariant::fromValue(m_player);
}

void GameEngine::changeLocation(int direction, int tileInd) {
    qDebug()<<"GameEngine: change location";
    int oldPos = m_player->getPosition();
    m_player->setPosition(m_player->getPosition()+tileInd);
    m_world->changeCurrentLocation(direction, m_player, oldPos);
    emit locationChanged();
}

Inventory* GameEngine::getPlayerInventory() const{
    return m_player->getInventory();
}
