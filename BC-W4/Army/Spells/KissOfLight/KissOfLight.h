#ifndef KISSOFLIGHT_H
#define KISSOFLIGHT_H

#include <iostream>
#include "../Spell/Spell.h"

class KissOfLight : public Spell {
    public:
        KissOfLight(int actionPoints = 120, int manaCost = 100, const std::string& spellName = "KissOfLight");
        virtual ~KissOfLight();

        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //KISSOFLIGHT_H