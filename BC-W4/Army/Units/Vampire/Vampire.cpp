#include "Vampire.h"

Vampire::Vampire(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType) : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), Subject(this) {
this->unitAttack = new VampireAttack(this);
this->unitCounterAttack = new VampireCounterAttack(this);
this->ability = new VampireAbility(this);
};

Vampire::~Vampire() {
    delete (this->ability);
};

void Vampire::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Vampire::update(Unit* observer) {
    this->detach(observer);
};

void Vampire::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    throw InvalidTransformException();
};

void Vampire::transform() {
    throw InvalidTransformException();
};
