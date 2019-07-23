#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../Attack/RogueAttack/RogueAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"
#include "../../Abilities/RogueAbility/RogueAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Rogue : virtual public Unit, virtual public Subject {
    public:
        Rogue(const std::string& name, int x, int y, int hp = Settings::ROGUE_HP, int dmg = Settings::ROGUE_DMG, int magicResist = Settings::ROGUE_MR, const std::string& unitTitle = "Rogue", const std::string& unitType = "Alive");
        virtual ~Rogue();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //ROGUE_H