#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <iostream>
#include "../Item.h"

class Electronics : public Item {
    public:
        Electronics(const std::string& name, int price, Category* category);
        virtual ~Electronics();
};

#endif //ELECTRONICS_H