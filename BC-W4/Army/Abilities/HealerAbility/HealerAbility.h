#ifndef HEALERABILITY_H
#define HEALERABILITY_H

#include <iostream>
#include "../MagicAbility/MagicAbility.h"

class HealerAbility : public MagicAbility {
    public:
        HealerAbility(SpellCaster* owner);
        virtual ~HealerAbility();
};

#endif //HEALERABILITY_H