#pragma once
#include "Location.h"

class Staircase : public Location {
public:
    Staircase();
    virtual void visit(Player& player) override;
};
