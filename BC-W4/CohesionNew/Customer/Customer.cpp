#include "Customer.h"

Customer::Customer(const std::string& name) {
    this->name = name;
    id += 1;
    customers.push_back(this);
}
Customer::~Customer() {
    customers.remove(this);
}

std::list<Order*> Customer::getOrders() const {
    return this->orderList;
}

const std::string& Customer::getName() const {
    return this->name;
}

void Customer::addOrder(Order* order) {
    this->orderList.push_back(order);
}

std::list<Customer*> Customer::getAllCustomers() {
    return customers;
}

std::list<Customer*> Customer::customers;

int Customer::id = 0;

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
    out << "Customer: " << customer.getName() << std::endl;
    
    std::list<Order*> lst = customer.getOrders();
    
    for ( std::list<Order*>::iterator it = lst.begin(); it != lst.end(); it++ ) {
        out << "Order: " << *(*it) << std::endl;
    }
    
    return out;
}