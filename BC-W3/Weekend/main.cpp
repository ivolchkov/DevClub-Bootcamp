#include <iostream>
#include "list.h"

int main() {
    List* list;
    
    try {
        list = new list(-20);
    } catch (InvalidListSizeException e) {
        std::cout<<"Something went wrong"<< e.message <<std::endl;
        list = new list(10);
    }
    
    std::cout<<*list<<std::endl;
    list->quantity = 10;
    
    return 0;
}