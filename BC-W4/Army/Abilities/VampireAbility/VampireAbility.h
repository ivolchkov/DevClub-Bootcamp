#ifndef VAMPIREABILITY_H
#define VAMPIREABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"
#include "../../Attack/VampireAttack/VampireAttack.h"
#include "../../CounterAttack/VampireCounterAttack/VampireCounterAttack.h"
#include "../../States/State/State.h"

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* unit);
        virtual ~VampireAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //VAMPIREABILITY_H