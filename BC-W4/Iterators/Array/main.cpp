#include <iostream>

#include "Array.h"

int main() {
    int size = 5;
    double arr[size] = {4.55, 6.025, 8.44, 9.345, 5.99};
    Array<double> iter = Array<double>(*arr,size);
    
    for ( ; iter.isOver(); iter++ ) {
        std::cout << *iter << " ";
    }
    // std::cout << *iter << std::endl;
    std::cout << std::endl;
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
    // iter.next();
    std::cout <<"last: "<< *iter << std::endl;
    iter.begin();
    std::cout <<"begin: "<< *iter << std::endl;
    iter.end();
    std::cout <<"end: "<< *iter << std::endl;
    
    double value = iter[4];
    std::cout<<"Fourth elem: " << value << std::endl;
    return 0;
}