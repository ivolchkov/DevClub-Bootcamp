#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "../SpellCaster/SpellCaster.h"
#include "../../Abilities/WizardAbility/WizardAbility.h"
#include "../../Abilities/DefaultAbility/DefaultAbility.h"
#include "../../Interfaces/Subject/Subject.h"

class Wizard : virtual public SpellCaster, virtual public Subject {
    public:
        Wizard(const std::string& name, int x, int y, int hp = Settings::WIZARD_HP, int mp = Settings::WIZARD_MP, int dmg = Settings::WIZARD_DMG, int magicResist = Settings::WIZARD_MR, const std::string& unitTitle = "Wizard", const std::string& unitType = "Alive");
        virtual ~Wizard();
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

#endif //WIZARD_H