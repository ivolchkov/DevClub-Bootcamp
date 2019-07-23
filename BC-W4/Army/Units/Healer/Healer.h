#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "../SpellCaster/SpellCaster.h"
#include "../../Abilities/HealerAbility/HealerAbility.h"
#include "../../Interfaces/Subject/Subject.h"


class Healer : virtual public SpellCaster, virtual public Subject {
    public:
        Healer(const std::string& name, int x, int y, int hp = Settings::HEALER_HP, int mp = Settings::HEALER_MP, int dmg = Settings::HEALER_DMG, int magicResist = Settings::HEALER_MR, const std::string& unitTitle = "Healer", const std::string& unitType = "Alive");
        virtual ~Healer();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //HEALER_H