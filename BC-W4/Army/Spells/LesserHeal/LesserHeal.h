#ifndef LESSERHEAL_H
#define LESSERHEAL_H

#include <iostream>
#include "../Spell/Spell.h"

class LesserHeal : public Spell {
    public:
        LesserHeal(int actionPoints = 40, int manaCost = 30, const std::string& spellName = "LesserHeal");
        virtual ~LesserHeal();

        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //LESSERHEAL_H