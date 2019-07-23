#ifndef GREATERHEAL_H
#define GREATERHEAL_H

#include <iostream>
#include "../Spell/Spell.h"

class GreaterHeal : public Spell {
    public:
        GreaterHeal(int actionPoints = 90, int manaCost = 60, const std::string& spellName = "GreaterHeal");
        virtual ~GreaterHeal();

        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //GREATERHEAL_H