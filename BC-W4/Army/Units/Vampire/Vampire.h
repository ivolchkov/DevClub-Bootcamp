#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../Attack/VampireAttack/VampireAttack.h"
#include "../../CounterAttack/VampireCounterAttack/VampireCounterAttack.h"
#include "../../States/VampireState/VampireState.h"
#include "../../Abilities/VampireAbility/VampireAbility.h"
#include "../../Interfaces/Subject/Subject.h"
#include "../../Exceptions/Exceptions.h"


class Vampire : virtual public Unit, virtual public Subject {
    public:
        Vampire(const std::string& name, int x, int y, int hp = Settings::VAMPIRE_HP, int dmg = Settings::VAMPIRE_DMG, int magicResist = Settings::VAMPIRE_MR, const std::string& unitTitle = "Vampire", const std::string& unitType = "Undead");
        virtual ~Vampire();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //VAMPIRE_H