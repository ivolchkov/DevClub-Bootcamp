#ifndef ROGUEABILITY_H
#define ROGUEABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"

class RogueAbility : public Ability{
    public:
        RogueAbility(Unit* unit);
        virtual ~RogueAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //ROGUEABILITY_H