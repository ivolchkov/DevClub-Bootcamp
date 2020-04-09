#include "Category.h"

Category::Category(const std::string& name) {
    this->name = name;
    
    categories.push_back(this);
}

Category::~Category() {
    categories.remove(this);
}

void Category::addGoods(Item* name) {
    this->goods.push_back(name);
}

void Category::removeGoods(Item* name) {
    this->goods.remove(name);
}

const std::string& Category::getName() const {
    return this->name;
}

std::list<Item*> Category::getAllGoods() const {
    return this->goods;
}

std::list<Category*> Category::getAllCategories() {
    return categories;
}

std::list<Category*> Category::categories;

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << category.getName() << ": " << std::endl;
    std::list<Item*> lst = category.getAllGoods();
    
    for ( std::list<Item*>::iterator it = lst.begin(); it != lst.end(); ++it ) {
        out << *(*it) << std::endl;
    }
    
    return out;
}