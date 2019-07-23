#include "SoldierAbility.h"

SoldierAbility::SoldierAbility(Unit* unit) : Ability(unit) {};
SoldierAbility::~SoldierAbility() {};

void SoldierAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void SoldierAbility::castAbility(Unit* enemy) {
    throw HasNoSuchAbilityException();
};