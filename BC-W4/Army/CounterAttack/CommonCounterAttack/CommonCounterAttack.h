#ifndef COMMONCOUNTERATTACK_H
#define COMMONCOUNTERATTACK_H

#include <iostream>
#include "../CounterAttack.h"

class CommonCounterAttack : public CounterAttack {
    public:
        CommonCounterAttack(Unit* unit);
        virtual ~CommonCounterAttack();
        
        virtual void counterAttack(Unit* enemy);
};

#endif //COMMONCOUNTERATTACK_H