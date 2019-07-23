#ifndef WEREWOLFABILITY_H
#define WEREWOLFABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Attack/CommonAttack/CommonAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"

class WerewolfAbility : public Ability {
    public:
        WerewolfAbility(Unit* unit);
        virtual ~WerewolfAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
        
};

#endif //WEREWOLFABILITY_H