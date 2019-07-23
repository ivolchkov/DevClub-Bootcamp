#include "VampireState.h"

VampireState::VampireState(const std::string& name, int hp, int dmg, int magicResist, const std::string& unitTitle, const std::string& unitType) : State(name, hp, dmg, magicResist, unitTitle, unitType){};

VampireState::~VampireState() {};
