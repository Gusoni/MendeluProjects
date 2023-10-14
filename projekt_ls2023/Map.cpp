//
// Created by terez on 11.03.2023.
//

#include "Map.h"
#include <iostream>
#include <windows.h>


Map::Map(Hero *h, int exitNum, Enemy enemy,  bool isFirst) : h(h), enemy(enemy) {

    m_width = rand() % 9 + 5;
    m_height = rand() % 6 + 3;
    //poslední mapa
    if(exitNum == 1 && !isFirst){
        m_width+=2;
        m_height+=2;
    }
    generateMap(exitNum, isFirst);
}

void Map::generateMap(int exitNum, bool isFirst) {
    m_map.resize(m_height, std::vector<std::string>(m_width, "."));

    // přidání zdí
    generateWalls( exitNum,isFirst);

    // pridani hrace
    m_map[m_height / 2][1]="@";
    // získání pozice hráče
    setHeroPosition();

    //generovani itemu a enemy
    if(m_height > 3){
        generateObjectOnMap(m_height, m_width, 'T');
        generateObjectOnMap(m_height, m_width, 'E');
    }


}

void Map::generateWalls(int exitNum, bool isFirst) {
    for (int i = 0; i < m_height; i++) {
        m_map[i][0] = "#";
        m_map[i][m_width - 1] = "#";
    }
    for (int i = 1; i < m_width; i++) {
        m_map[0][i] = "#";
        m_map[m_height - 1][i] = "#";
    }
    if(exitNum==1 && isFirst){
        m_map[m_height / 2][m_width - 1] = " ";
    }
    if(exitNum==1 && !isFirst){
        m_map[m_height / 2][0] = " ";
    }
    if(exitNum==2){
        m_map[m_height / 2][m_width - 1] = " ";
        m_map[m_height / 2][0] = " ";

    }
}

void Map::setHeroPosition() {
    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++) {
            if (m_map[i][j] == "@") {
                h->setHeroX(j);
                h->setHeroY(i);
            }
        }
    }
}

// vypsání mapy
void Map::printMap()  {
    std::system("cls");
    for (int i = 0; i < m_map.size(); i++) {
        for (int j = 0; j < m_map[i].size(); j++) {
            std::cout << m_map[i][j];
        }
        std::cout << std::endl;
    }
    printStats();
    std::cout << "\n\n\nPress M to open MENU. I to show inventory. P to use potion.";
}

void Map::printStats() {
    std::cout << "\n-------------------------------HERO-----------------------------------\n";
    printAttributes( h->getHealth(), h->getDefense(), h->getAttack(), h->getLvl(),
                     h->getExp(),h->getNextLvlExp());
    std::cout << "\n-------------------------------ENEMY-----------------------------------\n";
    if(enemy.getHealth() > 0 && m_height > 3){
        printAttributes( enemy.getHealth(), enemy.getMDefense(), enemy.getMAttack(),enemy.getLvl(),
                         enemy.getExp(),0);
    }
    else {
        std::cout << "Nothing is here";
    }
}

void Map::printAttributes(int health, int defense, int attack, int lvl, int exp, int nextLvlExp) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "\nHealth: " << health;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout << "\nDefense: " << defense;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "\nAttack: " << attack;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    std::cout << "\nLVL: " << lvl;
    std::cout << "\nEXP: " << exp;
    if(nextLvlExp > 0) {
        std::cout << "\nNext LVL exp: " << nextLvlExp;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// pohyb hráče
int Map::movePlayer(char direction) {
    int new_x = h->getHeroX();
    int new_y = h->getHeroY();
    switch (direction) {
        case 'w':
            new_y--;
            break;
        case 'a':
            new_x--;
            break;
        case 's':
            new_y++;
            break;
        case 'd':
            new_x++;
            break;
        default:
            return 0;
    }
    return movePlayerOnMap(new_x, new_y);
}

int Map::movePlayerOnMap(int new_x, int new_y) {
    // mimo mapu
    if (new_x < 0 || new_x >= m_map[0].size() || new_y < 0 || new_y >= m_map.size()) {
        return 0;
    }
    //zeď
    if (m_map[new_y][new_x] == "#") {
        return 0;
    }
    //východ
    if (m_map[new_y][new_x] == " ") {
        if(new_x != 0){
            return + 1;
        }
        else return -1;
    }
    //truhla
    if (m_map[new_y][new_x] == "T") {
        h->generateItem();
    }
    //enemy fight
    if (m_map[new_y][new_x] == "E") {
        h->fightEnemy(&enemy);
        if(isEnemyDead()){
            h->addExp(enemy.getExp());
        }
        if(enemy.getHealth() > 0 && h->getHealth() > 0){
            return 0;
        }
        if(h->getHealth() <= 0){
            //Jsme mrtví
            return 0;
        }
    }
    //pohyb na další místo
    movePlayerToFreeSpot(new_x, new_y);
    return 0;
}

void Map::movePlayerToFreeSpot(int new_x, int new_y) {
    m_map[h->getHeroY()][h->getHeroX()] = '.';
    m_map[new_y][new_x] = '@';
    h->setHeroX(new_x);
    h->setHeroY(new_y);
}

void Map::generateObjectOnMap(int height, int width, char string) {
    while(true) {
        int x = rand() %  width;
        int y =rand() %  height;
        if(m_map[y][x] == "."){
            m_map[y][x] = string;
            break;
        }
    }
}

bool Map::isEnemyDead() {
    return enemy.getHealth() <= 0;
}


