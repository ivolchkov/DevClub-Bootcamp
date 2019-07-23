#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../Attack/CommonAttack/CommonAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"
#include "../../Abilities/DemonAbility/DemonAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Demon : virtual public Unit, virtual public Subject {
    public:
        Demon(const std::string& name, int x, int y, int hp = Settings::DEMON_HP, int dmg = Settings::DEMON_DMG, int magicResist = Settings::DEMON_MR, const std::string& unitTitle = "Demon", const std::string& unitType = "Undead");
        virtual ~Demon();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //DEMON_H