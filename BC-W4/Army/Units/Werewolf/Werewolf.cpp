#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType) : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), Subject(this) {
    this->unitAttack = new CommonAttack(this);
    this->unitCounterAttack = new CommonCounterAttack(this);
    this->ability = new WerewolfAbility(this);
};

Werewolf::~Werewolf() {
    delete (this->ability);
};

void Werewolf::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Werewolf::update(Unit* observer) {
    this->detach(observer);
};

void Werewolf::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    throw InvalidTransformException();
};

void Werewolf::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->state->getUnitTitle() == "Werewolf(Wolf)") {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Werewolf(Human)";
    } else {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Werewolf(Wolf)";
    }
    
    delete (this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};

