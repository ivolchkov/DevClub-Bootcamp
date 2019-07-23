#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "../SpellCaster/SpellCaster.h"
#include "../../Abilities/PriestAbility/PriestAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Priest : virtual public SpellCaster, virtual public Subject {
    public:
        Priest(const std::string& name, int x, int y, int hp = Settings::PRIEST_HP, int mp = Settings::PRIEST_MP, int dmg = Settings::PRIEST_DMG, int magicResist = Settings::PRIEST_MR, const std::string& unitTitle = "Priest", const std::string& unitType = "Alive");
        virtual ~Priest();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //PRIEST_H