#include "DragonFlame.h"

DragonFlame::DragonFlame(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
DragonFlame::~DragonFlame() {};

void DragonFlame::action(Unit* enemy) {
    enemy->takeMagicDamage(this->getActionPoints());
};

void DragonFlame::heal(Unit* unit) {
    throw InvalidHealException();
};