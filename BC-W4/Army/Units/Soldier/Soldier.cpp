#include "Soldier.h"

Soldier::Soldier(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle,  const std::string& unitType) : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), Subject(this) {
    this->unitAttack = new CommonAttack(this);
    this->unitCounterAttack = new CommonCounterAttack(this);
    this->ability = new SoldierAbility(this);
};

Soldier::~Soldier() {
    delete (this->ability);
};

void Soldier::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Soldier::update(Unit* observer) {
    this->detach(observer);
};

void Soldier::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Soldier(Vampire)" || current == "Soldier(Wolf)" || current == "Soldier(Human)" ) {
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

void Soldier::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Soldier" || this->getUnitTitle() == "Soldier(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Soldier(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Soldier(Human)";
    } else if ( this->state->getUnitTitle() == "Soldier(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Soldier(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
