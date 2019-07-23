#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* unit) : Ability(unit) {};

WerewolfAbility::~WerewolfAbility() {};

void WerewolfAbility::castAbility() {
    std::cout << "\033[1;34m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<"\033[0m" 
    << "\033[1;32m is transforming\033[0m" << "\033[1;33m" << std::endl;
    this->unit->transform();
};

void WerewolfAbility::castAbility(Unit* enemy) {
    std::string newTitle;
    
    if ( this->unit->getLocation()->distance(unit->getPoint()) > 1 ) {
        std::cout << "\033[1;33mIt`s too far to use ability\033[0m" << std::endl;
    } else {
        if ( this->unit->getUnitTitle() == "Werewolf(Human)" ) {
            newTitle = enemy->getUnitTitle() + "(Human)";
        } else {
            newTitle = enemy->getUnitTitle() + "(Wolf)";
        }
        
        State* newState = new State(enemy->getName(), enemy->getHitPoints(), this->unit->getDamage(), this->unit->getMagicResist(), newTitle, this->unit->getUnitType());
        newState->setHitPointsLimit(this->unit->getHitPointsLimit());
        Ability* newAbility = new WerewolfAbility(enemy);
        Attack* newAttack = new CommonAttack(enemy);
        CounterAttack* newCounterAttack = new CommonCounterAttack(enemy);
        
        std::cout << "\033[1;34m" << this->unit->getUnitTitle() << ": " << "\"" << this->unit->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m tries to infect into Werewolf \033[0m" << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m"
        << std::endl;
        
        enemy->transform(newAbility, newState, newAttack, newCounterAttack, 'W');
    }
    
    
};