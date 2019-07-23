#ifndef DRAGONFLAME_H
#define DRAGONFLAME_H

#include <iostream>
#include "../Spell/Spell.h"

class DragonFlame : public Spell {
    public:
        DragonFlame(int actionPoints = 80, int manaCost = 55, const std::string& spellname = "DragonFlame");
        virtual ~DragonFlame();
        
        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //DRAGONFLAME_H