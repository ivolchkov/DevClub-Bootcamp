#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <map>
#include "../Subject/Subject.h"
#include "../../Units/Unit/Unit.h"

class Subject;

class Observer {
    protected:
        Unit* owner;
        std::map<std::string, Unit*> sbjList;
    public:
        Observer(Unit* unit);
        virtual ~Observer();
        
        void attach(Unit* subject);
        void detach(Unit* subject);
        virtual void notify();
};


#endif //OBSERVER_H