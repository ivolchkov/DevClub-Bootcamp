#include "VampireCounterAttack.h"

VampireCounterAttack::VampireCounterAttack(Unit* unit) : CounterAttack(unit) {};
VampireCounterAttack::~VampireCounterAttack() {};

void VampireCounterAttack::counterAttack(Unit* enemy) {
    int cAttackRange = (this->unit->getDamage() - 5) / 2;
    int cAttackPoints;
    
    srand(time(NULL));
    cAttackPoints = rand() % 10 + cAttackRange;
    this->unit->ensureIsAlive();
    
    enemy->takeDamage(cAttackPoints);
    this->unit->addHitPoints(cAttackPoints / 3);
    
    std::cout << "\033[1;33m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<"\033[0m" 
    << "\033[1;32m counter attacks \033[0m" 
    << "\033[1;34m" << enemy->getUnitTitle() <<": " << "\"" << this->unit->getName() << "\"" <<"\033[0m"<< std::endl
    << "\033[1;34m" << enemy->getUnitTitle() <<": " << "\"" << this->unit->getName() << "\"" <<" \033[0m" 
    << "\033[1;31m-"<< cAttackPoints << " HP\033[0m" << std::endl
    << "\033[1;33m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<" \033[0m" 
    << "\033[1;32m+" << cAttackPoints / 3 << " HP\033[0m" << std::endl;
};