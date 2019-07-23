#ifndef COMMONATTACK_H
#define COMMONATTACK_H

#include <iostream>
#include "../Attack.h"

class CommonAttack : public Attack {
    public:
        CommonAttack(Unit* unit);
        virtual ~CommonAttack();
        
        virtual void attack(Unit* enemy);
};

#endif //COMMONATTACK_H