#include <iostream>

#include "File.h"

int main() {
    char str[] = {"task.in"};
    File<double>* iter = new File<double>(str);
    
    //  std::cout << *(*iter) << std::endl;
    // if ( iter->isOver() ) {
    //     std::cout<<"True" << std::endl;
    // } else {
    //     std::cout<<"False" << std::endl;
    // }
    // (*iter)++;
    // if ( iter->isOver() ) {
    //     std::cout<<"True" << std::endl;
    // } else {
    //     std::cout<<"False" << std::endl;
    // }
    //     std::cout << *(*iter) << std::endl;
    for ( ; iter->isOver(); (*iter)++ ) {
        std::cout << *(*iter) << " ";
    }
    std::cout  << std::endl;

    delete iter;
    File<double>* iter1 = new File<double>("task.in");
    // std::cout <<"begin: "<< *iter << std::endl;
    
    iter1->next();
    iter1->next();
    
    std::cout <<"next 2: "<< *(*iter) << std::endl;
    
    
    // iter.next();
    // iter.next();
    // iter.next();
    // // iter.next();
    // std::cout <<"last: "<< *iter << std::endl;
    iter1->end();
    std::cout <<"end: "<< *(*iter) << std::endl;

    return 0;
}