#ifndef SOLDIERABILITY_H
#define SOLDIERABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"

class SoldierAbility : public Ability{
    public:
        SoldierAbility(Unit* unit);
        virtual ~SoldierAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //SOLDIERABILITY_H