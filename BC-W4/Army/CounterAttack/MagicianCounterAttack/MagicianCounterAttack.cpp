#include "MagicianCounterAttack.h"

MagicianCounterAttack::MagicianCounterAttack(Unit* unit) : CounterAttack(unit){};
MagicianCounterAttack::~MagicianCounterAttack() {};

void MagicianCounterAttack::counterAttack(Unit* enemy) {
    this->CounterAttack::counterAttack(enemy);
};