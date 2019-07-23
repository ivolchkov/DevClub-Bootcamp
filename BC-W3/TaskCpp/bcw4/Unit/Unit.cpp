#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->name = name;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->damage = dmg;
}
Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}
int Unit::getHitPoints() const {
    return this->hitPoints;
}
int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}
const std::string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();
    
    this->hitPoints += hp;
    
    if ( this->hitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    }
}
void Unit::takeDamage(int dmg) {
    ensureIsAlive();
    
    this->hitPoints -= dmg;
    
    if ( this->hitPoints < 0 ) {
        this->hitPoints = 0;
    }
}

void Unit::attack(Unit& enemy) {
    enemy.takeDamage(this->damage);
    enemy.ensureIsAlive();
    enemy.counterAttack(*this);
}
void Unit::counterAttack(Unit& enemy) {
    enemy.takeDamage(this->damage / 2);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " has " << unit.getHitPoints()<< "/" << unit.getHitPointsLimit() << " hp, and " << unit.getDamage() << " damage.";
    
    return out; 
}