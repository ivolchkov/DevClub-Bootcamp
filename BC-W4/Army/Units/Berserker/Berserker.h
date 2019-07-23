#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "../Unit/Unit.h"
#include "../../Attack/CommonAttack/CommonAttack.h"
#include "../../CounterAttack/CommonCounterAttack/CommonCounterAttack.h"
#include "../../Abilities/BerserkerAbility/BerserkerAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Berserker : virtual public Unit, virtual public Subject {
    public:
        Berserker(const std::string& name, int x, int y, int hp = Settings::BERSERKER_HP, int dmg = Settings::BERSERKER_DMG, int magicResist = Settings::BERSERKER_MR, const std::string& unitTitle = "Berserker", const std::string& unitType = "Alive");
        virtual ~Berserker();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //BERSERKER_H