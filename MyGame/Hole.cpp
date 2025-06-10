#include "Hole.h"

Hole::Hole() : Trap("O") {} // "O" represents a hole

void Hole::activate(Player& player) {
    cout << " You fell into a hole!" << endl;
    player.fallDown();
}
