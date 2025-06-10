#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Player {
private:
    int currentFloor; // 0 = base, 1 = floor1, 2 = floor2, 3 = floor3
    int row, col;     // Position on the current floor
    vector<string> keys; // Inventory of keys (e.g., "real_key" or "fake_key")
public:
    Player();
    void setPosition(int floor, int r, int c);
    int getFloor() const;
    int getRow() const;
    int getCol() const;
    void addKey(const string& key);
    bool hasKey(const string& key) const;
    void listKeys() const;
    void fallDown(); // Called when falling in a hole trap
    void move(int dr, int dc); // Moves on the same floor (optional helper)
};
