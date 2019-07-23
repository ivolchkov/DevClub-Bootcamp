#include "DemonsCall.h"

DemonsCall::DemonsCall(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
DemonsCall::~DemonsCall() {};

Demon* DemonsCall::action(Location* nLocation) {
    std::string name = "Slave" + demonAmount;
    
    Demon* demon = new Demon(name, nLocation->findFreeLocation().getX(), nLocation->findFreeLocation().getY());
    
    return demon;
    
    demonAmount += 1;
};

void DemonsCall::action(Unit* enemy) {
    throw InvalidActionException();
};

void DemonsCall::heal(Unit* unit) {
    throw InvalidHealException();
};

int DemonsCall::demonAmount = 1;