#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include "../../Units/Unit/Unit.h"

class Unit;

class Ability {
    protected:
        Unit* unit;
    public:
        Ability(Unit* unit);
        virtual ~Ability();
        
        virtual void castAbility() = 0;
        virtual void castAbility(Unit* enemy) = 0;
};

#endif //ABILITY_H