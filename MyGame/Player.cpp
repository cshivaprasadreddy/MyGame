#include "Player.h"

Player::Player() : currentFloor(1), row(0), col(0) {} // Start at floor1

void Player::setPosition(int floor, int r, int c) {
    currentFloor = floor;
    row = r;
    col = c;
}

int Player::getFloor() const {
    return currentFloor;
}

int Player::getRow() const {
    return row;
}

int Player::getCol() const {
    return col;
}

void Player::addKey(const string& key) {
    keys.push_back(key);
    cout << "You picked up a key: " << key << endl;
}

bool Player::hasKey(const string& key) const {
    for (const auto& k : keys) {
        if (k == key)
            return true;
    }
    return false;
}

void Player::listKeys() const {
    if (keys.empty()) {
        cout << "You have no keys." << endl;
        return;
    }
    cout << "Your keys: ";
    for (const auto& k : keys)
        cout << k << " ";
    cout << endl;
}

void Player::fallDown() {
    if (currentFloor > 0) {
        cout << "You fell! Moving down one floor." << endl;
        currentFloor--; // Move down one floor
    }
    else {
        cout << "You are already on the base floor and cannot fall any further!" << endl;
    }
}

void Player::move(int dr, int dc) {
    row += dr;
    col += dc;
}
