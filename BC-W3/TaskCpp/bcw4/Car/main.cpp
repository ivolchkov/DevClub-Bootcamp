#include<iostream>
#include "Car.h"
#include "Point.h"

int main() {
    Point location(5,5);
    Car car(60,0.6, location, "Lanos");

    std::cout << car << std::endl;
    
    car.refill(50);
    car.drive(Point(5, 20));

    std::cout << car << std::endl;
}