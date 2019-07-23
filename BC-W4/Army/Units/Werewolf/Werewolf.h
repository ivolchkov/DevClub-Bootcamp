#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../States/VampireState/VampireState.h"
#include "../../Attack/CommonAttack/CommonAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"
#include "../../Abilities/WerewolfAbility/WerewolfAbility.h"
#include "../../Interfaces/Subject/Subject.h"
#include "../../Exceptions/Exceptions.h"

class Werewolf : virtual public Unit, virtual public Subject {
    public:
        Werewolf(const std::string& name, int x, int y, int hp = Settings::WEREWOLF_HP, int dmg = Settings::WEREWOLF_DMG, int magicResist = Settings::WEREWOLF_MR, const std::string& unitTitle = "Werewolf(Human)", const std::string& unitType = "Alive");
        virtual ~Werewolf();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //WEREWOLF_H