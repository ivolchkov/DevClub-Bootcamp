#include "Car.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->fuelAmount = 0;
    
    this->location = location;
    this->model = model; 
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}
double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}
double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}
const Point& Car::getLocation() const {
    return this->location;
}
const std::string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    double distance = this->location.distance(destination);
    
    this->fuelAmount -= this->fuelConsumption * distance;
    
    if ( this->fuelAmount < 0 ) {
        throw OutOfFuel();
    }
    
    this->location = destination;
}
void Car::drive(double x, double y) {
    Point destination(x, y);
    double distance = this->location.distance(destination);
    
    this->fuelAmount -= this->fuelConsumption * distance;
    
    if ( this->fuelAmount < 0 ) {
        throw OutOfFuel();
    }
    this->location = destination;
}
void Car::refill(double fuel) {
    this->fuelAmount += fuel;
    
    if ( this->fuelAmount > this->fuelCapacity ) {
        throw ToMuchFuel();
    }
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << car.getModel() << " has location - " << car.getLocation() << " with fuel amount - " << car.getFuelAmount() << ", capacity - "<< car.getFuelCapacity() <<" and consumption - " << car.getFuelConsumption();
    
    return out;
}