#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../Attack/CommonAttack/CommonAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"
#include "../../Abilities/SoldierAbility/SoldierAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Soldier : virtual public Unit, virtual public Subject {
    public:
        Soldier(const std::string& name, int x, int y, int hp = Settings::SOLDIER_HP, int dmg = Settings::SOLDIER_DMG, int magicResist = Settings::SOLDIER_MR, const std::string& unitTitle = "Soldier", const std::string& unitType = "Alive");
        virtual ~Soldier();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};


#endif //SOLDIER_H