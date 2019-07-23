#include "Rogue.h"

Rogue::Rogue(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType) : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), Subject(this) {
    this->unitAttack = new RogueAttack(this);
    this->unitCounterAttack = new CommonCounterAttack(this);
    this->ability = new RogueAbility(this);
};

Rogue::~Rogue() {
    delete (this->ability);
};

void Rogue::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Rogue::update(Unit* observer) {
    this->detach(observer);
};

void Rogue::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Rogue(Vampire)" || current == "Rogue(Wolf)" || current == "Rogue(Human)" ) {
        throw InvalidTransformException();
    } else {
        delete this->ability;
        delete this->state;
        delete this->unitAttack;
        delete this->unitCounterAttack;
        
        this->ability = newAbility;
        this->state = newState;
        this->unitAttack = newAttack;
        this->unitCounterAttack = setNewCounterAttack;
        
        this->location->changeUnitTitle(fieldTitle, this->getPoint());
    }
};

void Rogue::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Rogue" || this->getUnitTitle() == "Rogue(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Rogue(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Rogue(Human)";
    } else if ( this->state->getUnitTitle() == "Rogue(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Rogue(Wolf)";
    }
    
    delete (this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
