#ifndef MAGICIANATTACK_H
#define MAGICIANATTACK_H

#include <iostream>
#include "../Attack.h"
#include "../../Units/Unit/Unit.h"

class MagicianAttack : public Attack {
    public:
        MagicianAttack(Unit* unit);
        virtual ~MagicianAttack();
        
        virtual void attack(Unit* enemy);
};

#endif //MAGICIANATTACK_H