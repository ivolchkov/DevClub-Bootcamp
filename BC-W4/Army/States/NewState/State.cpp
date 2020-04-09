#include "State.h"

State::State(const std::string& name, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType ) {
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->damage = dmg;
    this->name = name;
    this->magicResist = magicResist;
    this->unitTitle = unitTitle;
    this->unitType = unitType;
};
State::~State() {};

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw OutOfHitPointsException();
    }
};

int State::getHitPointsState() const {
    int state = (this->hitPoints * 100) / this->hitPointsLimit;
    
    if ( state > 65 ) {
        return 32;
    } else if ( state > 30 ) {
        return 33;
    } else {
        return 31;
    }
};

int State::getMagicResist() const {
    return this->magicResist;
};
int State::getHitPoints() const {
    return this->hitPoints;
};
int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
};
int State::getDamage() const {
    return this->damage;
};
const std::string& State::getName() const {
    return this->name;
};

const std::string& State::getUnitTitle() const {
    return this->unitTitle;
};

const std::string& State::getUnitType() const {
    return this->unitType;
};

void State::setUnitType(std::string& newType) {
    this->unitType = newType;
};

void State::setHitPointsLimit(int hp) {
    if ( hp >= this->hitPoints ) {
        this->hitPointsLimit = hp;
    } else {
        throw InvalidHitPointsLimitException();
    }
    
};

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();
    
    this->hitPoints -= dmg;
    
    if ( this->hitPoints < 0 ) {
        this->hitPoints = 0;
    }
};

void State::takeDamage(int dmg) {
    this->_takeDamage(dmg);
};

void State::takeMagicDamage(int dmg) {
     this->_takeDamage(dmg);
};

void State::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    this->hitPoints += hp;
    
    if ( this->hitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    }
};

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "\033[1;32m\""<< state.getName() <<"\"\033[0m" << std::endl 
    << "\033[1;42mHit points\033[0m" << "\033[1;" << state.getHitPointsState() <<"m: "<< state.getHitPoints() << "/" << state.getHitPointsLimit() <<"\033[0m" << std::endl
    << "\033[1;41mDamage\033[0m" << "\033[1;31m: "<< state.getDamage() <<"\033[0m" << std::endl
    << "\033[1;46mMagic resistance\033[0m" << "\033[1;36m: "<< state.getMagicResist() <<"%\033[0m";
    
    return out;
};

