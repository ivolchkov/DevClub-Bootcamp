#ifndef WARLOCKABILITY_H
#define WARLOCKABILITY_H

#include <iostream>
#include "../MagicAbility/MagicAbility.h"

class WarlockAbility : public MagicAbility {
    public:
        WarlockAbility(SpellCaster* owner);
        virtual ~WarlockAbility();
        
        virtual void cast();
};

#endif //WARLOCKABILITY_H
