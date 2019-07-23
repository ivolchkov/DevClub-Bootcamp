#ifndef DEMONABILITY_H
#define DEMONABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"

class DemonAbility : public Ability{
    public:
        DemonAbility(Unit* unit);
        virtual ~DemonAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //DEMONABILITY_H