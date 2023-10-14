//
// Created by denis on 13.10.2023.
//

#ifndef BATTLESHIPGAME_LOADER_H
#define BATTLESHIPGAME_LOADER_H
#include <iostream>
#include <vector>

class Loader {
private:
    std::vector< std::vector<int>> m_pole;
    std::vector< std::vector<char>> m_emptyPole;
    int m_rozmer;
    int m_pocetLodi=0;
public:
    Loader();
    void loadFromFile(const std::string& filename);
    std::vector<std::vector<int>> getMap();
    void printMap(); //mapa nactena ze souboru
    void printMapForPlayer(); // mapa kterou vidi hrac
    int getNumberOfShips();
    int getMapSize() const;
    void updateMap(int x,int y);
};


#endif //BATTLESHIPGAME_LOADER_H
