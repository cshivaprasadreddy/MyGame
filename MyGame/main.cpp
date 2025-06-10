#include "Game.h"

int main()
{
    Game game;
    // Load the map file (ensure map.txt is in the working directory)
    game.loadMap("map.txt");
    game.playGame();
    return 0;
}
