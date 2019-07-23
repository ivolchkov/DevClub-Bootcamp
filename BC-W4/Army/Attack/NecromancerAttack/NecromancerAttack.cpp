#include "NecromancerAttack.h"

NecromancerAttack::NecromancerAttack(Unit* unit) : Attack(unit) {};
NecromancerAttack::~NecromancerAttack() {};

void NecromancerAttack::attack(Unit* enemy) {
    this->Attack::attack(enemy);
};