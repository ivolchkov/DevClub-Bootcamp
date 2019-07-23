#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../Demon/Demon.h"
#include "../../States/MagicState/MagicState.h"
#include "../../Abilities/MagicAbility/MagicAbility.h"
#include "../../Attack/MagicianAttack/MagicianAttack.h"
#include "../../CounterAttack/MagicianCounterAttack/MagicianCounterAttack.h"
#include "../../Spells/Spell/Spell.h"
#include "../../Spells/Fireball/Fireball.h"
#include "../../Spells/DragonFlame/DragonFlame.h"
#include "../../Spells/AquaSplash/AquaSplash.h"
#include "../../Spells/WindVortex/WindVortex.h"
#include "../../Spells/LesserHeal/LesserHeal.h"
#include "../../Spells/GreaterHeal/GreaterHeal.h"
#include "../../Spells/KissOfLight/KissOfLight.h"
#include <map>

class MagicAbility;

class SpellCaster : public Unit {
    protected:
        MagicAbility* magicAbility;
        MagicState* magicState;
        std::map<std::string, Spell*>* spellBook;
    public:
        SpellCaster(const std::string& name, int x, int y, int hp = 100, int mp = 100, int dmg = 10, int magicResist = 10, const std::string& unitTitle = "SomeTitle", const std::string& unitType = "SomeType");
        virtual ~SpellCaster();
        
        int getMana() const;
        int getManaLimit() const;
        MagicState* getMagicState() const;
        
        void addMana(int mp);
        void spendMana(int mp);
        
        void addSpell(Spell* spell);
        void removeSpell(Spell* spell);
        void setAttackSpell(const std::string& spell);
        void setHealSpell(const std::string& spell);
        virtual void cast();
        virtual void cast(Unit* enemy);
        virtual void heal(Unit* unit);
        virtual void heal();
        
        virtual void CreateDemon(Demon* demon);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster* spellCaster);

#endif //SPELLCASTER_H