#ifndef VAMPIRECOUNTERATTACK_H
#define VAMPIRECOUNTERATTACK_H

#include <iostream>
#include "../CounterAttack.h"

class VampireCounterAttack : public CounterAttack {
    public:
        VampireCounterAttack(Unit* unit);
        virtual ~VampireCounterAttack();
        
        virtual void counterAttack(Unit* enemy);
};

#endif //VAMPIRECOUNTERATTACK_H