#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../../States/State/State.h"
#include "../../Attack/Attack.h"
#include "../../CounterAttack/CounterAttack.h"
#include "../../Abilities/Ability/Ability.h"
#include "../../Settings/Location.h"
#include "../../Exceptions/Exceptions.h"
#include "../../Settings.cpp"

class State;
class Attack;
class CounterAttack;
class Ability;
class Location;

class Unit {
    protected:
        Ability* ability;
        State* state;
        Attack* unitAttack;
        CounterAttack* unitCounterAttack;
        Location* location;
    public:
        Unit(const std::string& name, int x, int y, int hp = 100, int dmg = 10, int magicResist = 10, const std::string& unitTitle = "SomeTitle", const std::string& unitType = "SomeType");
        virtual ~Unit();
        
        void ensureIsAlive();
        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;
        const std::string& getUnitTitle() const;
        int getMagicResist() const;
        State* getState() const;
        const std::string& getUnitType() const;
        Point getPoint() const;
        Location* getLocation() const;
        
        double distance(Unit* enemy) const;
        void move(char direction);
        
        void setUnitType(std::string& newType);
        void setHitPointsLimit(int hp);
        
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
        void addHitPoints(int hp);
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit* unit);

#endif //UNIT_H