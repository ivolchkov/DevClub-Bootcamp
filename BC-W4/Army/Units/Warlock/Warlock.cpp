#include "Warlock.h"

Warlock::Warlock(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                                    : SpellCaster(name, x, y, hp, mp, dmg, magicResist, unitTitle, unitType),
                                                                                      Subject(this) {
    
    this->magicAbility = new WarlockAbility(this);
    this->ability = new DefaultAbility(this);
    this->demons = new std::list<Demon*>();
    
    Fireball* fireball = new Fireball(30);
    DragonFlame* dragonflame = new DragonFlame(40);
    AquaSplash* aquasplash = new AquaSplash(30);
    WindVortex* windvortex = new WindVortex(20);
    LesserHeal* lesserheal = new LesserHeal(20);
    GreaterHeal* greaterheal = new GreaterHeal(45);
    KissOfLight* kissoflight = new KissOfLight(60);
    DemonsCall* demonscall = new DemonsCall();
    
    this->addSpell(fireball);
    this->addSpell(dragonflame);
    this->addSpell(aquasplash);
    this->addSpell(windvortex);
    this->addSpell(lesserheal);
    this->addSpell(greaterheal);
    this->addSpell(kissoflight);
    this->addSpell(demonscall);
};

Warlock::~Warlock() {
    std::list<Demon*>::iterator it = this->demons->begin();
    
    for ( ; it != this->demons->end(); it++) {
        delete *it;
    }
    
    delete this->demons;
    delete this->ability;
}

int Warlock::getDemonsAmount() const {
    return this->demons->size();
};

void Warlock::DemonsAttack(Unit* enemy) {
    if ( enemy->getName() == this->getName() ) {
        throw DontTouchYourMasterException();
    }
    std::list<Demon*>::iterator it;
    
    for ( it = this->demons->begin(); it != this->demons->end(); it++ ) {
        (*it)->attack(enemy);
    }
};

void Warlock::CreateDemon(Demon* demon) {
    this->demons->push_back(demon);
};

void Warlock::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Warlock::update(Unit* observer) {
    this->detach(observer);
};

void Warlock::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Warlock(Vampire)" || current == "Warlock(Wolf)" || current == "Warlock(Human)" ) {
        throw InvalidTransformException();
    } else {
        delete (this->ability);
        delete (this->state);
        delete (this->unitAttack);
        delete (this->unitCounterAttack);
        
        this->ability = newAbility;
        this->state = newState;
        this->unitAttack = newAttack;
        this->unitCounterAttack = setNewCounterAttack;
        
        this->location->changeUnitTitle(fieldTitle, this->getPoint());
    }
};

void Warlock::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Warlock" || this->getUnitTitle() == "Warlock(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Warlock(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Warlock(Human)";
    } else if ( this->state->getUnitTitle() == "Warlock(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Warlock(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};

std::ostream& operator<<(std::ostream& out, const Warlock* warlock) {
    out << "\033[1;36m"<< warlock->getUnitTitle() << "\033[0m" << "\033[1;32m : \033[0m"  << *(warlock->getState()) << std::endl 
    << *(warlock->getMagicState()) << std::endl 
    << "\033[1;35mwith "<< warlock->getDemonsAmount() << " demons \033[0m";
    
    return out;
}