#include <iostream>
#include "Category/Category.h"
#include "Item/Item.h"
#include "Order/Order.h"
#include "Customer/Customer.h"

#include "Item/Electronics/Electronics.h"
#include "Item/Food/Food.h"
#include "Item/Furniture/Furniture.h"
int main() {
    Category* electronics = new Category("Electronics");
    Electronics* phone = new Electronics("Phone", 150, electronics);
    Electronics* monitor = new Electronics("Monitor", 200, electronics);
    
    std::cout << *phone << std::endl;
    std::cout << *electronics;
    std::cout<<"-------------------------------------------" << std::endl;
    
    Customer* Mike = new Customer("Mike");
    Order* MikeOrder = new Order(Mike, phone);
    
    MikeOrder->addItem(monitor);
    
    std::cout << *MikeOrder;
    std::cout<<"-------------------------------------------" << std::endl;
    Category* food = new Category("Food");
    Food* pizza = new Food("Pizza", 60, food);
    Food* pineapple = new Food("Pineapple", 90, food);
    Customer* John = new Customer("John");
    Order* JohnOrder = new Order(John, pizza);
    
    std::cout << *JohnOrder;
    JohnOrder->addItem(monitor);
    std::cout << *JohnOrder;
    std::cout<<"-------------------------------------------" << std::endl;
    std::list<Order*> lst = monitor->getAllOrders();
    
    for ( std::list<Order*>::iterator it = lst.begin(); it != lst.end(); it++ ) {
        std::cout << *(*it);
    }
    std::cout<<"-------------------------------------------" << std::endl;
    std::cout << "Deleting monitor" << std::endl;
    
    std::cout << *electronics;
    electronics->removeGoods(monitor);
    // delete monitor;
    std::cout << *electronics;
    
    // TVset.addGoods(monitor);
    // std::cout << phone << std::endl;
    // std::cout << TVset << std::endl;
    //     std::cout<<"-------------------------------------------" << std::endl;
    
    // std::list<Category*> lst = Category::getAllCategories();
    
    // for ( std::list<Category*>::iterator it = lst.begin(); it != lst.end(); it++ ) {
    //     std::cout << *(*it) << std::endl;
    // }
    // delete monitor;
    return 0;
}