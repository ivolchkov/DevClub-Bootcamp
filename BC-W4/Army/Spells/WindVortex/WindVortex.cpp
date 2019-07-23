#include "WindVortex.h"

WindVortex::WindVortex(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
WindVortex::~WindVortex() {};

void WindVortex::action(Unit* enemy) {
    enemy->takeMagicDamage(this->getActionPoints());
};

void WindVortex::heal(Unit* unit) {
    throw InvalidHealException();
};