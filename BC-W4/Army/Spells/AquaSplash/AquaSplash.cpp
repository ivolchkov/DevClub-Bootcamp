#include "AquaSplash.h"

AquaSplash::AquaSplash(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
AquaSplash::~AquaSplash() {};

void AquaSplash::action(Unit* enemy) {
    enemy->takeMagicDamage(this->getActionPoints());
};

void AquaSplash::heal(Unit* unit) {
    throw InvalidHealException();
};