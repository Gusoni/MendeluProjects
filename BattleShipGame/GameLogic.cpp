//
// Created by denis on 13.10.2023.
//

#include "GameLogic.h"

GameLogic::GameLogic(Loader* loader) : loader(loader) {
    m_pole = loader->getMap();
    m_pocetKol = loader->getNumberOfShips() * 2;
}

void GameLogic::strel(int x,int y) {
    m_pocetKol--;
    if(x<=loader->getMapSize()-1 and y<=loader->getMapSize()-1){
        if (m_pole.at(x).at(y)==1)
        {
            std::cout<<"Vyborne, zasahli jste!"<<std::endl;
            loader->updateMap(x,y);
            loader->printMapForPlayer();
        } else
        {
            std::cout<<"Minul jsi\n"<<std::endl;
        }
    } else{
        std::cerr<<"\nZadali jste spatne udaje. Opakujte, prosim."<<std::endl;
        std::cerr<<"Zadavejte, prosim, cisla od 1 do "<<loader->getMapSize()-1<<"."<<std::endl;

    }

}

bool GameLogic::vyhodnotKonec() const {
    bool konec;
    if(m_pocetKol>0){
        konec= false;
    }else konec= true;
    return konec;
}

unsigned int GameLogic::getPocetKol() const {
    return m_pocetKol;
}


GameLogic::~GameLogic() {
 delete loader;
}
