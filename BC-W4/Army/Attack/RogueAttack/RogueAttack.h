#ifndef ROGUEATTACK_H
#define ROGUEATTACK_H

#include <iostream>
#include "../Attack.h"

class RogueAttack : public Attack {
    public:
        RogueAttack(Unit* unit);
        virtual ~RogueAttack();
        
        virtual void attack(Unit* enemy);
};

#endif //ROGUEATTACK_H