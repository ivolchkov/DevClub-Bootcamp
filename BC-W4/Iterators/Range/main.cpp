#include <iostream>

#include "Range.h"

int main() {
    Range iter = Range(3, 2, 13);
    
    for ( ; !iter.isOver(); iter++ ) {
        std::cout << *iter << " ";
    }
    std::cout << *iter << std::endl;
    
    iter.begin();
    
    std::cout <<"begin: "<< *iter << std::endl;
    
    iter.next();
    iter.next();
    
    std::cout <<"next 2: "<< *iter << std::endl;
    
    iter.prev();
    
    std::cout <<"prev: "<< *iter << std::endl;
    
    iter.next();
    iter.next();
    iter.next();
    iter.next();
    std::cout <<"last: "<< *iter << std::endl;
    iter.begin();
    std::cout <<"begin: "<< *iter << std::endl;
    iter.end();
    std::cout <<"end: "<< *iter << std::endl;
    return 0;
}