#include "Gun.h"


Gun::Gun(const std::string& model, int capacity) {
    this->model = model;
    this->capacity = capacity;
    this->amount = 0;
    this->totalShots = 0;
    this->isReady = false;
}
Gun::~Gun() {}

int Gun::getAmount() const {
    return this->amount;
}
int Gun::getCapacity() const {
    return this->capacity;
}
bool Gun::ready() const {
    return this->isReady;
}
const std::string& Gun::getModel() const {
    return this->model;
}
int Gun::getTotalShots() const {
    return this->totalShots;
}

void Gun::prepare() {
    this->isReady = !this->isReady;
}
void Gun::reload() {
    this->amount = this->capacity;
}
void Gun::shoot() {
    if ( !this->isReady ) {
        throw NotReady();
    }
    if ( this->amount == 0 ) {
        throw OutOfRounds();
    }
    this->amount -= 1;
    this->totalShots += 1;
    this->isReady = !this->isReady;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << gun.getModel() << " has capacity of " << gun.getCapacity() << " , amount of rounds - " << gun.getAmount() << " and total shoots - " << gun.getTotalShots();
    
    return out;
}