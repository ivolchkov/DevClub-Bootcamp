#include "Demon.h"

Demon::Demon(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle,  const std::string& unitType) : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), Subject(this) {
    this->unitAttack = new CommonAttack(this);
    this->unitCounterAttack = new CommonCounterAttack(this);
    this->ability = new DemonAbility(this);
};

Demon::~Demon() {
    delete (this->ability);
};

void Demon::sign(Unit* enemy) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Demon::update(Unit* observer) {
    this->detach(observer);
};


void Demon::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Demon(Vampire)" || current == "Demon(Wolf)" || current == "Demon(Human)" ) {
        throw InvalidTransformException();
    } else {
        delete (this->ability);
        delete (this->state);
        delete (this->unitAttack);
        delete (this->unitCounterAttack);
        
        this->ability = newAbility;
        this->state = newState;
        this->unitAttack = newAttack;
        this->unitCounterAttack = setNewCounterAttack;
        
        this->location->changeUnitTitle(fieldTitle, this->getPoint());
    }
};

void Demon::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->state->getUnitTitle() == "Demon(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Demon(Human)";
    } else if ( this->state->getUnitTitle() == "Demon(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Demon(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};