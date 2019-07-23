#include "MagicianAttack.h"

MagicianAttack::MagicianAttack(Unit* unit) : Attack(unit){};
MagicianAttack::~MagicianAttack() {};

void MagicianAttack::attack(Unit* enemy) {
    this->Attack::attack(enemy);
};