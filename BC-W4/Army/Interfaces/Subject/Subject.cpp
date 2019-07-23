#include "Subject.h"

Subject::Subject(Unit* unit) {
    this->owner = unit;
};

Subject::~Subject() {
    this->notify();
};

void Subject::attach(Unit* observer) {
    std::string name = observer->getName();
    
    if ( obsList.find(name) == obsList.end() ) {
        obsList.insert(std::pair<std::string, Unit*>(name, observer));
    }
};

void Subject::detach(Unit* observer) {
    std::string name = observer->getName();
    
    obsList.erase(name);
};

void Subject::notify() {
    std::map<std::string, Unit*>::iterator it = this->obsList.begin();
    
    for ( ; it != this->obsList.end(); it++ ) {
        (it->second)->update(this->owner);
    }
};
