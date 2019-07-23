#include "LesserHeal.h"

LesserHeal::LesserHeal(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
LesserHeal::~LesserHeal() {};

void LesserHeal::action(Unit* enemy) {
    throw InvalidActionException();
};

void LesserHeal::heal(Unit* unit) {
    unit->addHitPoints(this->getActionPoints());
};