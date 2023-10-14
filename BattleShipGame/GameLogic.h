//
// Created by denis on 13.10.2023.
//

#ifndef BATTLESHIPGAME_GAMELOGIC_H
#define BATTLESHIPGAME_GAMELOGIC_H
#include "Loader.h"

class GameLogic {
private:
    unsigned int m_pocetKol;
    std::vector< std::vector<int>> m_pole;
    Loader* loader;
public:
    GameLogic(Loader* loader);  // Constructor accepting Loader pointer
    virtual ~GameLogic();
    unsigned int getPocetKol() const;   //pocet kol podle poctu lodi
    bool vyhodnotKonec() const;
    void strel(int x,int y);  //zautoceni hrace
};


#endif //BATTLESHIPGAME_GAMELOGIC_H
