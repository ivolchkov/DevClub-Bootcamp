#include "Order.h"

Order::Order(Customer* customer, Item* item) {
    this->customer = customer;
    this->itemList.push_back(item);
    item->addToOrder(this);
    orderId += 1;
    orders.push_back(this);
}
Order::~Order() {
    orders.remove(this);
}

void Order::addItem(Item* item) {
    item->addToOrder(this);
    this->itemList.push_back(item);
}

void Order::removeItem(Item* item) {
    this->itemList.remove(item);
}

Customer* Order::getCustomer() const {
    return this->customer;
}

std::list<Item*> Order::getItems() const {
    return this->itemList;
}

std::list<Order*> Order::getOrders() {
    return orders;
}

int Order::getId() {
    return orderId;
}

int Order::orderId = 0;

std::list<Order*> Order::orders;

std::ostream& operator<<(std::ostream& out, const Order& order) {
    Customer* name = order.getCustomer();
    std::list<Item*> items = order.getItems();
    
    out << "[Order id: " << Order::getId() << "]" << std::endl;
    out << "[Customer: \"" << name->getName() << "\"]" << std::endl;
    
    for ( std::list<Item*>::iterator it = items.begin(); it != items.end(); ++it ) {
        out << "Item: " << *(*it) << std::endl;
    }
    
    return out;
}