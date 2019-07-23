#ifndef AQUASPLASH_H
#define AQUASPLASH_H

#include <iostream>
#include "../Spell/Spell.h"

class AquaSplash : public Spell {
    public:
        AquaSplash(int actionPoints = 60, int manaCost = 45, const std::string& spellname = "AquaSplash");
        virtual ~AquaSplash();
        
        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //AQUASPLASH_H