#ifndef WINDVORTEX_H
#define WINDVORTEX_H

#include <iostream>
#include "../Spell/Spell.h"

class WindVortex : public Spell {
    public:
        WindVortex(int actionPoints = 40, int manaCost = 30, const std::string& spellname = "WindVortex");
        virtual ~WindVortex();
        
        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //WINDVORTEX_H