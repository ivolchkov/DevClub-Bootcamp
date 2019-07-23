#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../../Units/Unit/Unit.h"
#include "../../Units/Demon/Demon.h"

class Spell {
    protected:
        std::string spellName;
        int manaCost;
        int actionPoints;
    public:
        Spell( int actionPoints = 20, int manaCost = 40, const std::string& spellName = "SomeSpell");
        virtual ~Spell();
        
        int getManaCost() const;
        int getActionPoints() const;
        const std::string& getSpellName() const;
        
        virtual void action(Unit* enemy) = 0;
        virtual Demon* action(Location* nLocation);
        virtual void heal(Unit* unit) = 0;
        
};

#endif //SPELL_H