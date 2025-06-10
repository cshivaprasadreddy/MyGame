#pragma once
#include "Player.h"
#include "Location.h"
#include <vector>
#include <string>
using namespace std;

class Game {
private:
    // floors[0] = base, [1] = floor1, [2] = floor2, [3] = floor3
    vector<vector<vector<Location*>>> floors; // 3D vector: floor, row, col
    vector<int> floorRows; // Number of rows per floor
    vector<int> floorCols; // Number of columns per floor
    int numFloors;
    Player player;
public:
    Game();
    ~Game();
    void loadMap(const string& filename);
    void playGame();
    void displayCurrentFloor();
};
