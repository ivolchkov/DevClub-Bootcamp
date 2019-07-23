#include "CommonCounterAttack.h"

CommonCounterAttack::CommonCounterAttack(Unit* unit) : CounterAttack(unit) {};
CommonCounterAttack::~CommonCounterAttack() {};

void CommonCounterAttack::counterAttack(Unit* enemy) {
    this->CounterAttack::counterAttack(enemy);
};