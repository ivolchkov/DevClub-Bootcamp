#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <list>
#include "../Item/Item.h"

class Item;

class Category {
    private:
        std::string name;
        std::list<Item*> goods;
        static std::list<Category*> categories;
    public:
        Category(const std::string& name);
        ~Category();
        
        void addGoods(Item* name);
        void removeGoods(Item* name);
        
        
        const std::string& getName() const;
        std::list<Item*> getAllGoods() const;
        static std::list<Category*> getAllCategories();
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif //CATEGORY_H
