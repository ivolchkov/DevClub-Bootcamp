#ifndef BERSERKERABILITY_H
#define BERSERKERABILITY_H

#include <iostream>
#include "../Ability/Ability.h"
#include "../../Exceptions/Exceptions.h"

class BerserkerAbility : public Ability{
    public:
        BerserkerAbility(Unit* unit);
        virtual ~BerserkerAbility();
        
        virtual void castAbility();
        virtual void castAbility(Unit* enemy);
};

#endif //BERSERKERABILITY_H