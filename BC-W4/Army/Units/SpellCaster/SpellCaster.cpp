#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                     : Unit(name, x, y, hp, dmg, magicResist, unitTitle, unitType), 
                                                                       magicState(new MagicState(mp))
                                                                        {
    this->unitAttack = new MagicianAttack(this);
    this->unitCounterAttack = new MagicianCounterAttack(this);
    this->spellBook = new std::map<std::string, Spell*>();
};

SpellCaster::~SpellCaster() {
    std::map<std::string, Spell*>::iterator it = spellBook->begin();
    
    for ( ; it != spellBook->end(); it++ ) {
        delete it->second;
    }
    
    delete this->magicState;
    delete this->magicAbility;
    delete this->spellBook;
};

int SpellCaster::getMana() const {
    return this->magicState->getMana();
};

int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}; 

MagicState* SpellCaster::getMagicState() const {
    return this->magicState;
}

void SpellCaster::addMana(int mp) {
    this->magicState->addMana(mp);
};

void SpellCaster::spendMana(int mp) {
    this->magicState->spendMana(mp);
};

void SpellCaster::addSpell(Spell* spell) {
    if ( this->spellBook->find(spell->getSpellName()) == this->spellBook->end() ) {
        this->spellBook->insert(std::pair<std::string, Spell*>(spell->getSpellName(), spell));
    } else {
        throw AlreadyAddException();
    }
};

void SpellCaster::removeSpell(Spell* spell) {
    if ( this->spellBook->find(spell->getSpellName()) == this->spellBook->end() ) {
        throw NoSuchSpellException();
    }
    this->spellBook->erase(spell->getSpellName());
};

void SpellCaster::setAttackSpell(const std::string& spell) {
    std::map<std::string, Spell*>::iterator it;
    
    it = this->spellBook->find(spell);
    
    if ( it == this->spellBook->end() ) {
        throw NoSuchSpellException();
    }
    this->magicAbility->setAttackSpell(it->second);
};

void SpellCaster::setHealSpell(const std::string& spell) {
    std::map<std::string, Spell*>::iterator it;
    
    it = this->spellBook->find(spell);
    
    if ( it == this->spellBook->end() ) {
        throw NoSuchSpellException();
    }
    this->magicAbility->setHealSpell(it->second);
};

void SpellCaster::cast() {
    this->magicAbility->cast();
};

void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
};

void SpellCaster::heal(Unit* unit) {
    this->magicAbility->heal(unit);
};

void SpellCaster::heal() {
    this->magicAbility->heal();
};

void SpellCaster::CreateDemon(Demon* demon) {
    throw InvalidActionException();
};

std::ostream& operator<<(std::ostream& out, const SpellCaster* spellCaster) {
    out << "\033[1;46m"<< spellCaster->getUnitTitle() << "\033[0m" << "\033[1;32m: \033[0m" << *(spellCaster->getState()) << std::endl 
    << *(spellCaster->getMagicState());

    return out;
}

