#include "Item.h"

Item::Item(const std::string& name, int price, Category* category)  {
    this->itemName = name;
    this->itemPrice = price;
    this->category = category;
    this->category->addGoods(this);
    
    items.push_back(this);
}

Item::~Item() {
    this->category->removeGoods(this);
    delete this->category;
    items.remove(this);
}

const std::string& Item::getName() const {
    return this->itemName;
}

int Item::getPrice() const {
    return this->itemPrice;
}

std::list<Order*> Item::getAllOrders() const {
    return this->orderList;
}

const std::string& Item::getCategoryName() const {
    return this->category->getName();
}

void Item::addToOrder(Order* order) {
    this->orderList.push_back(order);
}

std::list<Item*> Item::getAllItems() {
    return items;
}

std::list<Item*> Item::items;

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << "[Category: \"" << item.getCategoryName() <<"\"]\n"
    << item.getName() << " - " << item.getPrice() << "$";
    
    return out;
}