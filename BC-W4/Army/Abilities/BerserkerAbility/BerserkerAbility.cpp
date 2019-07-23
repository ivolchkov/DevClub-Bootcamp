#include "BerserkerAbility.h"

BerserkerAbility::BerserkerAbility(Unit* unit) : Ability(unit) {};
BerserkerAbility::~BerserkerAbility() {};

void BerserkerAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void BerserkerAbility::castAbility(Unit* enemy) {
    throw HasNoSuchAbilityException();
};