#include <iostream>
#include "Unit.h"

int main() {
    Unit barbarian("Barbarian", 20, 20);
    Unit knight("Knight", 23, 25);

    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;

    barbarian.attack(knight);

    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
    
    knight.addHitPoints(25);
    std::cout << knight << std::endl;
    return 0;
}