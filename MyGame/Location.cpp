#include "Location.h"

Location::Location(const string& sym) : symbol(sym) {}

Location::~Location() {}

void Location::visit(Player& player) {
    // Default action: do nothing.
}

void Location::draw() const {
    cout << symbol;
}
