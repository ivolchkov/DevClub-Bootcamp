#ifndef COUNTERATTACK_H
#define COUNTERATTACK_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Units/Unit/Unit.h"

class Unit;

class CounterAttack {
    protected:
        Unit* unit;
    public:
        CounterAttack(Unit* unit);
        virtual ~CounterAttack();
        
        virtual void counterAttack(Unit* enemy) = 0;
};
#endif //COUNTERATTACK_H