#ifndef MAGICABILITY_H
#define MAGICABILITY_H

#include <iostream>
#include "../../Units/SpellCaster/SpellCaster.h"
#include "../../Spells/Spell/Spell.h"

class SpellCaster;

class MagicAbility {
    protected:
        SpellCaster* owner;
        Spell* attackSpell;
        Spell* healSpell;
    public:
        MagicAbility(SpellCaster* owner);
        virtual ~MagicAbility();
        
        void setAttackSpell(Spell* newSpell);
        void setHealSpell(Spell* newSpell);
        
        virtual void cast(Unit* enemy);
        virtual void cast();
        virtual void heal(Unit* unit);
        virtual void heal();
};



#endif //MAGICABILITY_H