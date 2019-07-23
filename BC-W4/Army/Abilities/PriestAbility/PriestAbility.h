#ifndef PRIESTABILITY_H
#define PRIESTABILITY_H

#include <iostream>
#include "../MagicAbility/MagicAbility.h"

class PriestAbility : public MagicAbility {
    public:
        PriestAbility(SpellCaster* owner);
        virtual ~PriestAbility();
        
        virtual void cast(Unit* enemy);
};

#endif //PRIESTABILITY_H