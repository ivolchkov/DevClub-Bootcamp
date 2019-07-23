#include <iostream>
#include "Complex.h"

int main() {
    Complex x(2, 7);
    Complex y(3, 8);
    Complex z;
    
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
    
    if ( x == y ) {
    std::cout << x << " is equal to " << y << std::endl;
    } else {
    std::cout << x << " is not equal to " << y << std::endl;
    }
    
    x += y;
    z -= y;
    
    std::cout << "New x " << x << std::endl;
    std::cout << "New z " << z << std::endl;
    
    y = x + x;
    std::cout << "New y " << y << std::endl;
    
    x = y * x;
    std::cout<<"New x mult " << x << std::endl;
    
    return 0;
}
