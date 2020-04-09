#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <list>

#include "../Order/Order.h"

class Order;

class Customer {
    private:
        std::string name;
        std::list<Order*> orderList;
        
        static std::list<Customer*> customers;
        static int id;
    public:
        Customer(const std::string& name);
        ~Customer();
        
        std::list<Order*> getOrders() const;
        const std::string& getName() const;
        void addOrder(Order* order);
        
        static std::list<Customer*> getAllCustomers();
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif //CUSTOMER_H
