#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                                    : SpellCaster(name, x, y, hp, mp, dmg, magicResist, unitTitle, unitType),
                                                                                      Observer(this) {
    this->magicAbility = new NecromancerAbility(this);
    this->ability = new DefaultAbility(this);
    Fireball* fireball = new Fireball(30);
    DragonFlame* dragonflame = new DragonFlame(40);
    AquaSplash* aquasplash = new AquaSplash(30);
    WindVortex* windvortex = new WindVortex(20);
    LesserHeal* lesserheal = new LesserHeal(20);
    GreaterHeal* greaterheal = new GreaterHeal(45);
    KissOfLight* kissoflight = new KissOfLight(60);
    
    this->addSpell(fireball);
    this->addSpell(dragonflame);
    this->addSpell(aquasplash);
    this->addSpell(windvortex);
    this->addSpell(lesserheal);
    this->addSpell(greaterheal);
    this->addSpell(kissoflight);
};

Necromancer::~Necromancer() {
    delete (this->ability);
};

void Necromancer::sign(Unit* enemy) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Necromancer::update(Unit* observer) {
    std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m recieves part of health \033[0m" << "\033[1;33m"
        << "\033[1;33m" << observer->getUnitTitle() <<": " << "\"" << observer->getName() << "\"" <<" \033[0m" << std::endl
        << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m";
    this->owner->addHitPoints(observer->getHitPointsLimit() / 10);
    this->detach(observer);
};

void Necromancer::attack(Unit* enemy) {
    this->attach(enemy);
    enemy->sign(this);
    this->unitAttack->attack(enemy);
};

void Necromancer::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
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

void Necromancer::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Necromancer" || this->getUnitTitle() == "Necromancer(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Necromancer(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Necromancer(Human)";
    } else if ( this->state->getUnitTitle() == "Necromancer(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Necromancer(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
