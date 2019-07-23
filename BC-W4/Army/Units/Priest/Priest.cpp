#include "Priest.h"

Priest::Priest(const std::string& name, int x, int y, int hp, int mp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType)
                                                                                    : SpellCaster(name, x, y, hp, mp, dmg, magicResist, unitTitle, unitType),
                                                                                      Subject(this) {
    this->magicAbility = new PriestAbility(this);
    
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

Priest::~Priest() {
    delete (this->ability);
};

void Priest::sign(Unit* enemy) {
    std::string current = enemy->getUnitTitle();
    
    if ( current == "Necromancer" || current == "Necromancer(Vampire)" || current == "Necromancer(Wolf)" || current == "Necromancer(Human)" ) {
        this->attach(enemy);
    } else {
        throw InvalidSignException();
    }
};

void Priest::update(Unit* observer) {
    this->detach(observer);
};

void Priest::transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle) {
    std::string current = this->getUnitTitle();
    
    if ( current == "Priest(Vampire)" || current == "Priest(Wolf)" || current == "Priest(Human)" ) {
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

void Priest::transform() {
    int newHP;
    int newDmg;
    int newResist;
    int newHPLimit = this->state->getHitPointsLimit();
    std::string newName = this->state->getName();
    std::string newUnitTitle;
    
    if ( this->getUnitTitle() == "Priest" || this->getUnitTitle() == "Priest(Vampire)" ) {
        throw InvalidTransformException();
    }
    
    if ( this->state->getUnitTitle() == "Priest(Wolf)" ) {
        newHP = this->state->getHitPoints() / 2;
        newDmg = this->state->getDamage() / 2;
        newResist = 25;
        newHPLimit /= 2;
        newUnitTitle = "Priest(Human)";
    } else if ( this->state->getUnitTitle() == "Priest(Human)" ) {
        newHP = this->state->getHitPoints() * 2;
        newDmg = this->state->getDamage() * 2;
        newResist = 0;
        newHPLimit *= 2;
        newUnitTitle = "Priest(Wolf)";
    }
    
    delete(this->state);
    
    this->state = new State(newName, newHP, newDmg, newResist, newUnitTitle, this->getUnitType());
    this->state->setHitPointsLimit(newHPLimit);
};
