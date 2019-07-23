#include "Spell.h"

Spell::Spell(int actionPoints, int manaCost,const std::string& spellName) : manaCost(manaCost), actionPoints(actionPoints), spellName(spellName) {};
Spell::~Spell() {};

int Spell::getManaCost() const {
    return this->manaCost;
};

int Spell::getActionPoints() const {
    return this->actionPoints;
};

const std::string& Spell::getSpellName() const {
    return this->spellName;
};

Demon* Spell::action(Location* nLocation) {
    throw InvalidActionException();
};