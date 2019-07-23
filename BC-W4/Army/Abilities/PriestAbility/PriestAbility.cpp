#include "PriestAbility.h"

PriestAbility::PriestAbility(SpellCaster* owner) : MagicAbility(owner) {};

PriestAbility::~PriestAbility() {};

void PriestAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( this->owner->getLocation()->distance(enemy->getPoint()) > 3 ) {
        std::cout << "\033[1;33mYour enemy is too far to be attacked\033[0m" << std::endl;
    } else {
        this->owner->spendMana(this->attackSpell->getManaCost());
        
        std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m attacks \033[0m" << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m"
        << std::endl
        << "\033[1;35mwith spell " << this->attackSpell->getSpellName() <<" \033[0m" << std::endl;
        
        this->attackSpell->action(enemy);
    }
    
    if ( enemy->getUnitType() == "Undead" ) {
        std::cout << "\033[1;31mHate Undead!\033[0m" << std::endl;
        this->attackSpell->action(enemy);
    }
};