#ifndef MAGICIANCOUNTERATTACK_H
#define MAGICIANCOUNTERATTACK_H

#include <iostream>
#include "../CounterAttack.h"
#include "../../Units/Unit/Unit.h"

class MagicianCounterAttack : public CounterAttack {
    public:
        MagicianCounterAttack(Unit* unit);
        virtual ~MagicianCounterAttack();
        
        virtual void counterAttack(Unit* enemy);
};

#endif //MAGICIANCOUNTERATTACK_H