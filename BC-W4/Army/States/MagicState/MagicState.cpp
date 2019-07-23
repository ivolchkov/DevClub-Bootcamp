#include "MagicState.h"

MagicState::MagicState(int mp) : mana(mp), manaLimit(mp) {};
MagicState::~MagicState() {};

int MagicState::getMana() const {
    return this->mana;
};

int MagicState::getManaLimit() const {
    return this->manaLimit;
};

void MagicState::addMana(int mp) {
    this->mana += mp;
    
    if ( this->mana > this->manaLimit ) {
        this->mana = this->manaLimit;
    }
};

void MagicState::spendMana(int cost) {
    if ( cost > this->mana ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState) {
    out << "\033[1;44mMana points\033[0m" << "\033[1;34m: "<< magicState.getMana() << "/" << magicState.getManaLimit() <<"\033[0m";
    
    return out;
}