#pragma once
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

class Location {
protected:
    string symbol; // Used when drawing the map
public:
    Location(const string& sym = " ");
    virtual ~Location();
    virtual void visit(Player& player); // Action when the player visits
    virtual void draw() const;           // How the location is displayed
};
