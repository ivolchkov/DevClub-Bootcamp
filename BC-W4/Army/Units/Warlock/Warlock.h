#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include "../SpellCaster/SpellCaster.h"
#include "../Demon/Demon.h"
#include "../../Abilities/WarlockAbility/WarlockAbility.h"
#include "../../Abilities/DefaultAbility/DefaultAbility.h"
#include "../../Spells/DemonsCall/DemonsCall.h"
#include "../../Interfaces/Subject/Subject.h"
#include <list>

class Warlock : virtual public SpellCaster, virtual public Subject {
    protected:
        std::list<Demon*>* demons;
    public:
        Warlock(const std::string& name, int x, int y, int hp = Settings::WARLOCK_HP, int mp = Settings::WARLOCK_MP, int dmg = Settings::WARLOCK_DMG, int magicResist = Settings::WARLOCK_MR, const std::string& unitTitle = "Warlock", const std::string& unitType = "Alive");
        virtual ~Warlock();
        
        int getDemonsAmount() const;
        
        void DemonsAttack(Unit* enemy);
        void CreateDemon(Demon* demon);
        
        virtual void sign(Unit* enemy);
        virtual void update(Unit* observer);
        
        virtual void transform(Ability* newAbility, State* newState, Attack* newAttack, CounterAttack* setNewCounterAttack, char fieldTitle);
        virtual void transform();
};

std::ostream& operator<<(std::ostream& out, const Warlock* warlock);

#endif //WARLOCK_H