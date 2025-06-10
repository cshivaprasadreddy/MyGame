#pragma once
#include "Trap.h"

class TripMine : public Trap {
public:
    TripMine();
    virtual void activate(Player& player) override;
};
