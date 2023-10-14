
#include "GameEngine.h"
int main() {
    Loader loader;
    loader.loadFromFile("zdroj.txt");
    loader.printMapForPlayer();  // Print the map for the player
    loader.getNumberOfShips();   // Update m_pocetLodi

    GameLogic logic(&loader);
    GameEngine game(&loader, &logic);
    game.play();

    return 0;
}
