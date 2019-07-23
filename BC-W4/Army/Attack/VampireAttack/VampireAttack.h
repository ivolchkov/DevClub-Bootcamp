#ifndef VAMPIREATTACK_H
#define VAMPIREATTACK_H

#include <iostream>
#include "../Attack.h"

class VampireAttack : public Attack {
    public:
        VampireAttack(Unit* unit);
        virtual ~VampireAttack();
        
        virtual void attack(Unit* enemy);
};

#endif //VAMPIREATTACK_H