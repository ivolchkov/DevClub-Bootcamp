#include <iostream>
#include "Vector.h"

int main() {
    Vector x(2, 7);
    Vector y(3, 8);
    Vector z;
    
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
    
    std::cout << "New x" << x << std::endl;
    std::cout << "New z" << z << std::endl;
    
    y = x + x;
    std::cout << "New y" << y << std::endl;
    std::cout << "Distance: " << x.len() << std::endl;
    
    return 0;
}
