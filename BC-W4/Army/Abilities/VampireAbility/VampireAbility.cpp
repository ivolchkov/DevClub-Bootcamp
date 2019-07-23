#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* unit) : Ability(unit) {};
VampireAbility::~VampireAbility() {};

void VampireAbility::castAbility() {
    throw HasNoSuchAbilityException();
};

void VampireAbility::castAbility(Unit* enemy) {
    if ( this->unit->getLocation()->distance(unit->getPoint()) > 1 ) {
        std::cout << "\033[1;33mIt`s too far to use ability\033[0m" << std::endl;
    } else {
        std::string newTitle = enemy->getUnitTitle() + "(Vampire)";
        
        State* newState = new State(enemy->getName(), this->unit->getHitPoints(), this->unit->getDamage(), this->unit->getMagicResist(),    newTitle, this->unit->getUnitType());
        Ability* newAbility = new VampireAbility(enemy);
        Attack* newAttack = new VampireAttack(enemy);
        CounterAttack* newCounterAttack = new VampireCounterAttack(enemy);
        
        std::cout << "\033[1;34m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m tries to infect into Vampire \033[0m" << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m"
        << std::endl;
        
        enemy->transform(newAbility, newState, newAttack, newCounterAttack, 'V');
    }
    
};

