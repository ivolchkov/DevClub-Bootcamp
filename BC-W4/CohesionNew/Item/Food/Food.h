#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "../Item.h"

class Food : public Item {
    public:
        Food(const std::string& name, int price, Category* category);
        virtual ~Food();
};

#endif //FOOD_H