#include "Room.h"
#include "Player.h"

Room::Room(bool key, bool isReal) : Location("R"), hasKey(key), keyIsReal(isReal), keyTaken(false) {}

void Room::visit(Player& player) {
    if (hasKey && !keyTaken) {
        // Player collects the key
        if (keyIsReal)
            player.addKey("real_key");
        else
            player.addKey("fake_key");
        keyTaken = true;
    }
    else {
        cout << "This room is empty." << endl;
    }
}

void Room::draw() const {
    if (hasKey && !keyTaken)
        cout << "K"; // "K" indicates a key is available
    else
        cout << symbol;
}
