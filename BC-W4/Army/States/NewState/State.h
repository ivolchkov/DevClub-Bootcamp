#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../../Exceptions/Exceptions.h"

class State {
    protected:
        int hitPoints;
        int hitPointsLimit;
        int damage;
        int magicResist;
        std::string name;
        std::string unitTitle;
        std::string unitType;
        
        void _takeDamage(int dmg);
    public:
        State(const std::string& name, int hp = 100, int dmg = 10, int magicResist = 10, const std::string& unitTitle = "SomeTitle", const std::string& unitType = "SomeType");
        ~State();
        
        void ensureIsAlive();
        int getHitPointsState() const;
        int getMagicResist() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        const std::string& getName() const;
        const std::string& getUnitTitle() const;
        const std::string& getUnitType() const;
        void setUnitType(std::string& newType);
        void setHitPointsLimit(int hp);
        
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
        void addHitPoints(int hp);
        
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_H