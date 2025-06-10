#pragma once
#include "Location.h"

class ExitDoor : public Location {
public:
    ExitDoor();
    virtual void visit(Player& player) override;
};
