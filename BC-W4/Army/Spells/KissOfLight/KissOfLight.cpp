#include "KissOfLight.h"

KissOfLight::KissOfLight(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
KissOfLight::~KissOfLight() {};

void KissOfLight::action(Unit* enemy) {
    throw InvalidActionException();
};

void KissOfLight::heal(Unit* unit) {
    unit->addHitPoints(this->getActionPoints());
};