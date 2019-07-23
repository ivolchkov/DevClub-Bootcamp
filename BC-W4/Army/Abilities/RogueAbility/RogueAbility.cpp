#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* unit) : Ability(unit) {};
RogueAbility::~RogueAbility() {};

void RogueAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void RogueAbility::castAbility(Unit* enemy) {
    throw HasNoSuchAbilityException();
};