#include "Fireball.h"

Fireball::Fireball(int actionPoints, int manaCost, const std::string& spellName) : Spell(actionPoints, manaCost, spellName) {};
Fireball::~Fireball() {};

void Fireball::action(Unit* enemy) {
    enemy->takeMagicDamage(this->getActionPoints());
};

void Fireball::heal(Unit* unit) {
    throw InvalidHealException();
};