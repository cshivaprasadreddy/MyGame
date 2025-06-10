#pragma once
#include "Location.h"

class Trap : public Location {
public:
    Trap(const string& sym);
    virtual void activate(Player& player) = 0; // Each trap type must define its activation behavior
    virtual void visit(Player& player) override;
};
