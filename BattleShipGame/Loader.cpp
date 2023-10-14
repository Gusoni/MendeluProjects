//
// Created by denis on 13.10.2023.
//

#include "Loader.h"
#include <fstream>

Loader::Loader() {
    m_pocetLodi = 0;
    m_rozmer = 0;
};

void Loader::loadFromFile(const std::string& filename) {
    std::ifstream vstup(filename);
    if (!vstup.is_open())
        throw std::runtime_error("Error in opening the file!");

    vstup >> m_rozmer;
    int znak;
    for (int i = 0; i < m_rozmer; i++) {
        std::vector<int> radek;
        for (int j = 0; j < m_rozmer; j++) {
            vstup >> znak;
            radek.push_back(znak);
        }
        m_pole.push_back(radek);
    }
    vstup.close();
    m_emptyPole.resize(m_rozmer, std::vector<char>(m_rozmer, '~'));
}

std::vector<std::vector<int>> Loader::getMap() {
    return m_pole;
}

void Loader::printMap() {
    std::cout << "Contents of Battle map:" << std::endl;
    for (int i = 0; i < m_rozmer; i++) {
        for (int j = 0; j < m_rozmer; j++) {
            std::cout << m_pole[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int Loader::getNumberOfShips() {
    m_pocetLodi = 0;  // Initialize m_pocetLodi to zero before counting ships
    for (int i = 0; i < m_rozmer; i++) {
        for (int j = 0; j < m_rozmer; j++) {
            if (m_pole[j][i] == 1)
                m_pocetLodi++;
        }
    }
    return m_pocetLodi;
}
int Loader::getMapSize() const {
    return m_rozmer;
}

void Loader::printMapForPlayer() {
    std::cout << "Contents of Battle map:" << std::endl;
    for (int i = 0; i < m_rozmer; i++) {
        for (int j = 0; j < m_rozmer; j++) {
            std::cout << m_emptyPole[j][i] << " ";  // Print '~' for each element
        }
        std::cout << std::endl;
    }
}

void Loader::updateMap(int radek,int sloupec) {
    m_emptyPole[radek][sloupec] = '1';
}
