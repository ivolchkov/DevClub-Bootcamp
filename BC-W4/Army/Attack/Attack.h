#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Units/Unit/Unit.h"

class Unit;

class Attack {
    protected:
        Unit* unit;
    public:
        Attack(Unit* unit);
        virtual ~Attack();
        
        virtual void attack(Unit* enemy) = 0;
};
#endif //ATTACK_H