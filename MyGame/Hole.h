#pragma once
#include "Trap.h"

class Hole : public Trap {
public:
    Hole();
    virtual void activate(Player& player) override;
};
