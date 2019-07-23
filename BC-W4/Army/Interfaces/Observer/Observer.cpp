#include "Observer.h"

Observer::Observer(Unit* unit) {
    this->owner = unit;
};

Observer::~Observer() {
    this->notify();
};

void Observer::attach(Unit* subject) {
    std::string name = subject->getName();
    
    if ( sbjList.find(name) == sbjList.end() ) {
        sbjList.insert(std::pair<std::string, Unit*>(name, subject));
        
        std::cout << "\033[1;34m" << this->owner->getUnitTitle() << ": " << "\"" << this->owner->getName() << "\"" <<"\033[0m" 
        << "\033[1;32m attaches \033[0m" << "\033[1;33m" << subject->getUnitTitle() <<": " << "\"" << subject->getName() << "\"" <<
        "\033[0m"<< std::endl;
    }
};

void Observer::detach(Unit* subject) {
    std::string name = subject->getName();
    
    sbjList.erase(name);
};

void Observer::notify() {
    std::map<std::string, Unit*>::iterator it = this->sbjList.begin();
    
    for ( ; it != this->sbjList.end(); it++ ) {
        (it->second)->update(this->owner);
    }
};
