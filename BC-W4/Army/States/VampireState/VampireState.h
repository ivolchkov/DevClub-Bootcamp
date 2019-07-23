#ifndef VAMPIRESTATE_H
#define VAMPIRESTATE_H

#include <iostream>
#include "../State/State.h"
#include "../../Units/Unit/Unit.h"

class VampireState : public State {
    public:
        VampireState(const std::string& name, int hp = 120, int dmg = 40, int magicResist = 20, const std::string& unitTitle = "Vampire", const std::string& unitType = "Undead");
        virtual ~VampireState();
};

#endif //VAMPIRESTATE_H