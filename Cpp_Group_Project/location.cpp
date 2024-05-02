#include "location.h"
#include "npc.h"

Location::Location(QObject *parent)
    : QObject{parent}
{
}

Location::Location(int index){
    const int layoutSize = 19;
    const int totalSize = layoutSize * layoutSize;
    qDebug("Location: konstr with index %d", index);

    bool isTopRow = index < 5;
    bool isBottomRow = index > 19;
    bool isLeftColumn = index % 5 == 0;
    bool isRightColumn = index % 5 == 4;

    // TODO refaktorizace kodu do metod, aby se zmenšila velikost konstruktoru
    /*C++11 standard pro generování čísel, sám jsem na to koukal, když jsem to našel*/
    std::vector<int> monsterPositions;  // Vektor pro uchování pozic monster
    std::random_device rGenerator;      // Vytvoří náhodná čísla z náhody systému (seed pro generování pseudo náhodných čísel, ekvivalent srand ve starším řešení náhodnosti)
    std::mt19937 gen(rGenerator());     // Vytváří pseudo-náhodná čísla podle algoritmu, random_device nemusí vytvářet plně náhodná čísla (ekvivalent rand)
    std::uniform_int_distribution<> distrib(0, totalSize - 1);  // Stará se o rovnoměré rozložení čísel (filtr pro náš rozsah, ekvivalent %)

    while (monsterPositions.size() < 5) {
        int pos = distrib(gen);

        // Kontrola, zda se nemají monstra umístit na krajních pozicích
        bool onEdge = (pos < layoutSize) || (pos >= totalSize - layoutSize) ||
                      (pos % layoutSize == 0) || ((pos + 1) % layoutSize == 0 || pos == 180);

        if (!onEdge && std::find(monsterPositions.begin(), monsterPositions.end(), pos) == monsterPositions.end()) {
            monsterPositions.push_back(pos);
        }
    }

    for(int i = 0; i < totalSize; i++) {
        if(isTopRow && (i < layoutSize)) {
            m_layout.push_back(new Obstacle());
        } else if(isBottomRow && (i >= totalSize - layoutSize)) {
            m_layout.push_back(new Obstacle());
        } else if(isLeftColumn && (i % layoutSize == 0)) {
            m_layout.push_back(new Obstacle());
        } else if(isRightColumn && ((i + 1) % layoutSize == 0)) {
            m_layout.push_back(new Obstacle());
        } else if (std::find(monsterPositions.begin(), monsterPositions.end(), i) != monsterPositions.end()) {
            m_layout.push_back(new Monster());
        } else {
            m_layout.push_back(new GameObject());
        }
    }
    m_layout.at(23) = new NPC();
}

QVariant Location::getLayout() {
    qDebug("Location: layout getter");
    return QVariant::fromValue(m_layout);
}

void Location::insertEntity(int index, GameObject* object){
    qDebug("Location: insert index %d with type", index);
    qDebug() << object->getType();
    if (index >= 0 && index < m_layout.size()) {
        m_layout.at(index) = object;
    }
}

void Location::updatePlayerLocation(int targetloc, Player* player){
    GameObject* grass = new GameObject();
    m_layout.at(player->getPosition()) = grass;
    m_layout.at(targetloc) = player;
    //funkce vezme starou pozici hrace na layoutu a zmeni ji zpatky na gameobject, aby jsme tam meli travu, a nastavi na targetloc novou pozici hrace
}

GameObject* Location::getLayoutObject(int index){
    if (index >= 0 && index < m_layout.size()) {
        return m_layout.at(index);
    }
    return nullptr;
}
