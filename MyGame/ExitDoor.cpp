#include "ExitDoor.h"
#include "Player.h"
#include <cstdlib>

ExitDoor::ExitDoor() : Location("E") {}

void ExitDoor::visit(Player& player) {
    if (player.hasKey("real_key")) {
        cout << " You unlocked the exit door! You win!" << endl;
        exit(0);
    }
    else {
        cout << "The door is locked. You don't have the correct key." << endl;
    }
}
