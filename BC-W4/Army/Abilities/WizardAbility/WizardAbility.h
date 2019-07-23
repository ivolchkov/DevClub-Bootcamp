#ifndef WIZARDABILITY_H
#define WIZARDABILITY_H

#include <iostream>
#include "../MagicAbility/MagicAbility.h"

class WizardAbility : public MagicAbility {
    public:
        WizardAbility(SpellCaster* owner);
        virtual ~WizardAbility();
};

#endif //WIZARDABILITY_H