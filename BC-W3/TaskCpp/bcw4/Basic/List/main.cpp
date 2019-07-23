#include <iostream>
#include "List.h"

int main() {
    List* list = new List(2);
    List* compare = new List(20);
    
    
    compare->push_back(55);
    compare->push_back(55);
    compare->push_back(55);
    
    list->push_back(20);
    list->push_back(40);
    list->push_back(60);
    std::cout<<"Maxsize list "<<list->max_size()<<std::endl;
    std::cout<<"Size list "<<list->size()<<std::endl;
    std::cout<<*list<<std::endl;
    list->insert(15,1);
    std::cout<<*list<<std::endl;
    list->pop_back();
    std::cout<<*list<<std::endl;
    list->insert(50,1);
    std::cout<<*list<<std::endl;
    list->sort();
    
    
    std::cout<<"Compare "<<*compare<<std::endl;
    std::cout<<*list<<std::endl;
    list->erase(1);
    compare->push_back(55);
    std::cout<<list->find(50)<<std::endl;
    std::cout<<*list<<std::endl;
    
    
    if ( compare != list ) {
        std::cout<<"Yes"<<std::endl;
    } else {
        std::cout<<"No"<<std::endl;
    }
    std::cout<<*list<<std::endl;
    std::cout<<*compare<<std::endl;
    
    std::cout<<"Size list "<<list->size()<<std::endl;
    std::cout<<"Size compare "<<compare->size()<<std::endl;
    
    std::cout<<"Maxsize list "<<list->max_size()<<std::endl;
    std::cout<<"Maxsize compare "<<compare->max_size()<<std::endl;
    // list->capacity = 10;
    
    return 0;
}