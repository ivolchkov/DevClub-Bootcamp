#include "RogueAttack.h"

RogueAttack::RogueAttack(Unit* unit) : Attack(unit) {};
RogueAttack::~RogueAttack() {};

void RogueAttack::attack(Unit* enemy) {
    int attackRange = this->unit->getDamage() - 5;
    int attackPoints;
    
    srand(time(NULL));
    attackPoints = rand() % 10 + attackRange;
    
    this->unit->ensureIsAlive();
    
    enemy->takeDamage(attackPoints);
    
    std::cout << "\033[1;34m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<"\033[0m" 
    << "\033[1;32m attacks \033[0m" << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m"<< std::endl
    << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << this->unit->getName() << "\"" <<" \033[0m" 
    << "\033[1;31m-"<< attackPoints << " HP\033[0m" << std::endl;
};