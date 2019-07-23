#include "Unit.h"

Unit::Unit(const std::string& name, int x, int y, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType ) : state(new State(name, hp, dmg, magicResist, unitTitle, unitType)) {
    this->location = new Location(x, y);
    this->location->addUnit(unitTitle[0], this->location->getLocation());
};
Unit::~Unit() {
    this->location->deleteUnit(this->getPoint());
    
    delete (this->state);
    delete (this->unitAttack);
    delete (this->unitCounterAttack);
    delete (this->location);
};

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
};

int Unit::getDamage() const {
    return this->state->getDamage();
};

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
};

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
};

const std::string& Unit::getName() const {
    return this->state->getName();
};

const std::string& Unit::getUnitTitle() const {
    return this->state->getUnitTitle();
};

int Unit::getMagicResist() const {
    return this->state->getMagicResist();
};

State* Unit::getState() const {
    return this->state;
};

const std::string& Unit::getUnitType() const {
    this->state->getUnitType();
};

Point Unit::getPoint() const {
    return this->location->getLocation();
};

Location* Unit::getLocation() const {
    return this->location;
};

double Unit::distance(Unit* enemy) const {
    this->location->distance(enemy->getPoint());
};

void Unit::move(char direction) {
    this->location->move(direction);
};

void Unit::setUnitType(std::string& newType) {
    this->state->setUnitType(newType);
};

void Unit::setHitPointsLimit(int hp) {
    this->state->setHitPointsLimit(hp);
};

void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
};

void Unit::takeMagicDamage(int dmg) {
    int damage = ((100 - this->state->getMagicResist()) * dmg ) / 100;
    
    this->state->takeMagicDamage(damage);
    std::cout << "\033[1;31m -"<< damage << " HP\033[0m" << std::endl;
};

void Unit::addHitPoints(int hp) {
    std::cout << "\033[1;32m +" << hp << " HP\033[0m" << std::endl;
    this->state->addHitPoints(hp);
};

void Unit::attack(Unit* enemy) {
    if ( this->distance(enemy) == 1 ) {
        this->unitAttack->attack(enemy);
    } else {
        std::cout << "\033[1;33mYour enemy is too far to be attacked\033[0m" << std::endl;
    }
}

void Unit::counterAttack(Unit* enemy) {
    this->unitCounterAttack->counterAttack(enemy);
};

void Unit::sign(Unit* enemy) {};

void Unit::update(Unit* observer) {};

void Unit::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
};

void Unit::transform() {
};

void Unit::castAbility() {
    this->ability->castAbility();
};

void Unit::castAbility(Unit* enemy) {
    this->ability->castAbility(enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit* unit) {
    out << "\033[1;46m"<< unit->getUnitTitle() << "\033[0m" << "\033[1;32m: \033[0m"  << *(unit->getState()) ;

    return out;
}