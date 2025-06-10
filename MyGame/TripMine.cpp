#include "TripMine.h"
#include <cstdlib>

TripMine::TripMine() : Trap("T") {}

void TripMine::activate(Player& player) {
    cout << "You triggered a Trip Mine! Game Over!" << endl;
    exit(0);
}
