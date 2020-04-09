#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <list>
#include "../Item/Item.h"
#include "../Customer/Customer.h"

class Item;
class Customer;

class Order {
    private:
        Customer* customer;
        std::list<Item*> itemList;
        static std::list<Order*> orders;
        static int orderId;
    public:
        Order(Customer* customer, Item* item);
        ~Order();
        
        void addItem(Item* item);
        void removeItem(Item* item);
        Customer* getCustomer() const;
        std::list<Item*> getItems() const;
        
        static std::list<Order*> getOrders();
        static int getId();
};

std::ostream& operator<<(std::ostream& out, const Order& order);

#endif //ORDER_H
