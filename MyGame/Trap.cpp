#include "Trap.h"

Trap::Trap(const string& sym) : Location(sym) {}

void Trap::visit(Player& player) {
    // When a trap is visited, activate its effect.
    activate(player);
}
