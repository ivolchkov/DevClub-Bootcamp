#include "Healer.h"

Healer::Healer(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                                    : SpellCaster(name, x, y, hp, mp, dmg, magicResist, unitTitle, unitType),
                                                                                      Subject(this) {
    this->magicAbility = new HealerAbility(this);
    
    Fireball* fireball = new Fireball(30);
    DragonFlame* dragonflame = new DragonFlame(40);
    AquaSplash* aquasplash = new AquaSplash(30);
    WindVortex* windvortex = new WindVortex(20);
    LesserHeal* lesserheal = new LesserHeal();
    GreaterHeal* greaterheal = new GreaterHeal();
    KissOfLight* kissoflight = new KissOfLight();
    
    this->addSpell(fireball);
    this->addSpell(dragonflame);
    this->addSpell(aquasplash);
    this->addSpell(windvortex);
    this->addSpell(lesserheal);
    this->addSpell(greaterheal);
    this->addSpell(kissoflight);
};

Healer::~Healer() {
    delete (this->ability);
};

void Healer::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Healer::update(Unit* observer) {
    this->detach(observer);
};

void Healer::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Healer(Vampire)" || current == "Healer(Wolf)" || current == "Healer(Human)" ) {
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

void Healer::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Healer" || this->getUnitTitle() == "Healer(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Healer(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Healer(Human)";
    } else if ( this->state->getUnitTitle() == "Healer(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Healer(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
