#include "Wizard.h"

Wizard::Wizard(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                                    : SpellCaster(name, x, y, hp, mp, dmg, magicResist, unitTitle, unitType),
                                                                                      Subject(this) {
    this->magicAbility = new WizardAbility(this);
    this->ability = new DefaultAbility(this);
    
    Fireball* fireball = new Fireball();
    DragonFlame* dragonflame = new DragonFlame();
    AquaSplash* aquasplash = new AquaSplash();
    WindVortex* windvortex = new WindVortex();
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

Wizard::~Wizard() {
    delete this->ability;
};

void Wizard::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Wizard::update(Unit* observer) {
    this->detach(observer);
};

void Wizard::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Wizard(Vampire)" || current == "Wizard(Wolf)" || current == "Wizard(Human)" ) {
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

void Wizard::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Wizard" || this->getUnitTitle() == "Wizard(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Wizard(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Wizard(Human)";
    } else if ( this->state->getUnitTitle() == "Wizard(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Wizard(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
