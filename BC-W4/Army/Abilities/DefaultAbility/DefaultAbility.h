#ifndef DEFAULTABILITY_H
#define DEFAULTABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"

class DefaultAbility : public Ability {
    public:
        DefaultAbility(Unit* unit);
        virtual ~DefaultAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //DEFAULTABILITY_H