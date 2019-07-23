#include "MagicAbility.h"

MagicAbility::MagicAbility(SpellCaster* owner) :owner(owner) {
    this->attackSpell = NULL;
    this->healSpell = NULL;
}; 

MagicAbility::~MagicAbility() {};

void MagicAbility::setAttackSpell(Spell* newSpell) {
    this->attackSpell = newSpell;
};

void MagicAbility::setHealSpell(Spell* newSpell) {
    this->healSpell = newSpell;
};

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( this->owner->getLocation()->distance(enemy->getPoint()) > 3 ) {
        std::cout << "\033[1;33mYour enemy is too far to be attacked\033[0m" << std::endl;
    } else {
        this->owner->spendMana(this->attackSpell->getManaCost());
        
        std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m attacks \033[0m" << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m"
        << std::endl
        << "\033[1;35mwith spell " << this->attackSpell->getSpellName() <<" \033[0m" << std::endl
        << "\033[1;33m" << enemy->getUnitTitle() <<": " << "\"" << enemy->getName() << "\"" <<"\033[0m" ;
        
        this->attackSpell->action(enemy);
    }
};

void MagicAbility::cast() {
    throw InvalidCastException();
};

void MagicAbility::heal(Unit* unit) {
    this->owner->ensureIsAlive();
    
    if ( this->owner->getLocation()->distance(unit->getPoint()) > 3 ) {
        std::cout << "\033[1;33mYou can`t heal. It`s too far away!\033[0m" << std::endl;
    } else {
        this->owner->spendMana(this->healSpell->getManaCost());
        
        std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m heals \033[0m" << "\033[1;33m" << unit->getUnitTitle() <<": " << "\"" << unit->getName() << "\"" <<"\033[0m"
        << std::endl
        << "\033[1;33m" << unit->getUnitTitle() <<": " << "\"" << this->owner->getName() << "\"" <<" \033[0m"
        << "\033[1;35mwith spell " << this->healSpell->getSpellName() <<" \033[0m" << std::endl
        << "\033[1;33m" << unit->getUnitTitle() <<": " << "\"" << unit->getName() << "\"" <<"\033[0m" ;
        
        this->healSpell->heal(unit);
    }

};

void MagicAbility::heal() {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->healSpell->getManaCost());
    
    std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
    << "\033[1;32m heals himself\033[0m" << "\033[1;33m" << std::endl
    << "\033[1;35mwith spell " << this->healSpell->getSpellName() <<" \033[0m" << std::endl
    << "\033[1;33m" << this->owner->getUnitTitle() <<": " << "\"" << this->owner->getName() << "\"" <<"\033[0m";
    
    this->healSpell->heal(this->owner);
};