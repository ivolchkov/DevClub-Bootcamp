#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <map>
#include "../Observer/Observer.h"
#include "../../Units/Unit/Unit.h"

class Observer;

class Subject {
    protected:
        Unit* owner;
        std::map<std::string, Unit*> obsList;
    public:
        Subject(Unit* unit);
        virtual ~Subject();
        
        void attach(Unit* observer);
        void detach(Unit* observer);
        virtual void notify();
};

#endif //SUBJECT_H