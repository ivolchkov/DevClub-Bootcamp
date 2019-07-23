#ifndef NECROMANCERABILITY_H
#define NECROMANCERABILITY_H

#include <iostream>
#include "../MagicAbility/MagicAbility.h"

class NecromancerAbility : public MagicAbility {
    public:
        NecromancerAbility(SpellCaster* owner);
        virtual ~NecromancerAbility();
};

#endif //NECROMANCERABILITY_H