#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <list>
#include "../Category/Category.h"
#include "../Order/Order.h"

class Category;
class Order;

class Item {
    protected:
        Category* category;
        std::string itemName;
        int itemPrice;
        std::list<Order*> orderList;
        static std::list<Item*> items;
    public:
        Item(const std::string& name, int price, Category* category);
        virtual ~Item();
        
        const std::string& getName() const;
        int getPrice() const;
        const std::string& getCategoryName() const;
        void addToOrder(Order* order);
        std::list<Order*> getAllOrders() const;
        static std::list<Item*> getAllItems();
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //ITEM_H
