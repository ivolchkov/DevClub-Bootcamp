#include "CommonAttack.h"

CommonAttack::CommonAttack(Unit* unit) : Attack(unit) {};
CommonAttack::~CommonAttack() {};

void CommonAttack::attack(Unit* enemy) {
    this->Attack::attack(enemy);
};