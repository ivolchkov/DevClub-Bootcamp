#include "WarlockAbility.h"

WarlockAbility::WarlockAbility(SpellCaster* owner) : MagicAbility(owner) {};

WarlockAbility::~WarlockAbility() {};

void WarlockAbility::cast() {
    this->owner->ensureIsAlive();
    this->owner->spendMana(this->attackSpell->getManaCost());
    this->owner->CreateDemon(this->attackSpell->action(this->owner->getLocation()));
    
    std::cout << "\033[1;35m Creating new Slave with " << this->attackSpell->getSpellName() <<" \033[0m" << std::endl;
};