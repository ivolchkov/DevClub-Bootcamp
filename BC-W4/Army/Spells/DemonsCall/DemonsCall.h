#ifndef DEMONSCALL_H
#define DEMONSCALL_H

#include <iostream>
#include "../Spell/Spell.h"
#include "../../Units/Demon/Demon.h"

class DemonsCall : public Spell {
    protected:
        static int demonAmount;
    public:
        DemonsCall(int actionPoints = 0, int manaCost = 30, const std::string& spellname = "DemonsCall");
        virtual ~DemonsCall();
        
        virtual Demon* action(Location* nLocation);
        virtual void action(Unit* enemy);
        virtual void heal(Unit* unit);
};

#endif //DEMONSCALL_H