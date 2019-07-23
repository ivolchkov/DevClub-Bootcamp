#include "GreaterHeal.h"

GreaterHeal::GreaterHeal(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
GreaterHeal::~GreaterHeal() {};

void GreaterHeal::action(Unit* enemy) {
    throw InvalidActionException();
};

void GreaterHeal::heal(Unit* unit) {
    unit->addHitPoints(this->getActionPoints());
};