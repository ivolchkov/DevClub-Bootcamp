#include <iostream>

#include "point.h"

int main() {
    Point<int>* p1 = new Point<int>(1, 6);
    Point<float>* p2 = new Point<float>(1.23, 7.42);
    
    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;
    
    return 0;
}
