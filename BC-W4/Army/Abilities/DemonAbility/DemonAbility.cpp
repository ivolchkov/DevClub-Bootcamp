#include "DemonAbility.h"

DemonAbility::DemonAbility(Unit* unit) : Ability(unit) {};
DemonAbility::~DemonAbility() {};

void DemonAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void DemonAbility::castAbility(Unit* enemy) {
    throw HasNoSuchAbilityException();
};