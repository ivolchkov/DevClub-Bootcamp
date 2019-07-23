#include "DefaultAbility.h"

DefaultAbility::DefaultAbility(Unit* unit) : Ability(unit) {};
DefaultAbility::~DefaultAbility() {};

void DefaultAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void DefaultAbility::castAbility(Unit* enemy) {
    throw HasNoSuchAbilityException();
};