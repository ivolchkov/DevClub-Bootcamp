#ifndef MAGICSTATE_H
#define MAGICSTATE_H

#include <iostream>
#include "../../Exceptions/Exceptions.h"

class MagicState {
    protected:
        int mana;
        int manaLimit;
        
    public:
        MagicState(int mp);
        virtual ~MagicState();
        
        int getMana() const;
        int getManaLimit() const;
        
        void addMana(int mp);
        void spendMana(int cost);
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState);

#endif //MAGICSTATE_H