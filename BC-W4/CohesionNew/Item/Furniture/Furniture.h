#ifndef FURNITURE_H
#define FURNITURE_H

#include <iostream>
#include "../Item.h"

class Furniture : public Item {
    public:
        Furniture(const std::string& name, int price, Category* category);
        virtual ~Furniture();
};

#endif //FURNITURE_H