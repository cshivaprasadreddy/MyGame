#pragma once
#include "Location.h"

class Room : public Location {
private:
    bool hasKey;
    bool keyIsReal;
    bool keyTaken;
public:
    // If key == true, then the room contains a key.
    // keyIsReal indicates if it is the real key.
    Room(bool key = false, bool isReal = false);
    virtual void visit(Player& player) override;
    virtual void draw() const override;
};
