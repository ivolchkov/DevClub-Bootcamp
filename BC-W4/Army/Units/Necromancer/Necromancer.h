#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "../SpellCaster/SpellCaster.h"
#include "../../Abilities/NecromancerAbility/NecromancerAbility.h"
#include "../../Abilities/DefaultAbility/DefaultAbility.h"
#include "../../Attack/NecromancerAttack/NecromancerAttack.h"
#include "../../Interfaces/Observer/Observer.h"


class Necromancer : virtual public SpellCaster, virtual public Observer {
    public:
        Necromancer(const std::string& name, int x, int y, int hp = Settings::NECROMANCER_HP, int mp = Settings::NECROMANCER_MP, int dmg = Settings::NECROMANCER_DMG, int magicResist = Settings::NECROMANCER_MR, const std::string& unitTitle = "Necromancer", const std::string& unitType = "Undead");
        virtual ~Necromancer();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void attack(Unit* enemy);
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};


#endif //NECROMANCER_H