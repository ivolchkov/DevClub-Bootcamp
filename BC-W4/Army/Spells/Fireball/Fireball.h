#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
#include "../Spell/Spell.h"

class Fireball : public Spell {
    public:
        Fireball(int actionPoints = 60, int manaCost = 40, const std::string& spellname = "Fireball");
        virtual ~Fireball();
        
        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //FIREBALL_H