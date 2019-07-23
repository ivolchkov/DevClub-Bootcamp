#ifndef NECROMANCERATTACK_H
#define NECROMANCERATTACK_H

#include <iostream>
#include "../Attack.h"

class NecromancerAttack : public Attack {
    public:
        NecromancerAttack(Unit* unit);
        virtual ~NecromancerAttack();
        
        virtual void attack(Unit* enemy);
};

#endif //NECROMANCERATTACK_H