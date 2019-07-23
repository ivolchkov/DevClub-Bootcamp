#include "Location.h"

Location::Location(int x, int y) {
    this->location = Point(x, y);
    
    if ( freeLocation.empty() ) {
        for( int i = 0; i < FIELD_HEIGHT; i++ ) {
            for ( int j = 0; j < FIELD_WIDHT; j++ ) {
                freeLocation.insert(Point(i, j));
            }
        }
    }
};

Location::~Location() {};

int Location::getX() const {
    this->location.getX();
};

int Location::getY() const {
    this->location.getY();
};

Point Location::getLocation() const {
    return this->location;
};

void Location::printField() {
    std::cout << "\033[1;31m           BATTLEFIELD           \033[0m" << std::endl;
    
    for( int i = 0; i < FIELD_HEIGHT; i++ ) {
        for ( int j = 0; j < FIELD_WIDHT; j++ ) {
            std::cout << "\033[1;46m \033[0m";
        }
        std::cout << std::endl;
    }
    std::cout << "\033[s";
    
    std::map<Point, char>::iterator it = occupiedLocation.begin();
    
    for ( int color = 30; it != occupiedLocation.end(); it++ ) {
        std::cout <<"\033[" << it->first.getY() << "A" << "\033["<< it->first.getX() << "C" << "\033[1;"<< color <<";46m"<< it->second <<"\033[0m";
        std::cout << "\033[u";
        
        color += 1;
        if ( color == 38 ) {
            color = 30;
        }
    }
    
    std::cout << "\033[u";
};

double Location::distance(const Point& other) const {
    return this->location.distance(other);
};

void Location::move(char direction){
    switch ( direction ) {
        case 'U' : 
            this->moveUp();
            break;
        case 'D' :
            this->moveDown();
            break;
        case 'R' :
            this->moveRight();
            break;
        case 'L' :
            this->moveLeft();
            break;
        default :
            std::cout << "\033[1;31mAre you drunk??\033[0m" << std::endl;
    }
};

void Location::moveRight(){
    Point newPosition = Point(this->location.getX() + 1, this->location.getY());
    
    if ( freeLocation.find(newPosition) == freeLocation.end() ) {
        std::cout << "\033[1;31mThere is no way\033[0m" << std::endl;
    } else {
        this->changePosition(newPosition);
        this->location.setX(this->location.getX() + 1);
    }
};

void Location::moveLeft(){
    Point newPosition = Point(this->location.getX() - 1, this->location.getY());
    
    if ( freeLocation.find(newPosition) == freeLocation.end() ) {
        std::cout << "\033[1;31mThere is no way\033[0m" << std::endl;
    } else {
        this->changePosition(newPosition);
        this->location.setX(this->location.getX() - 1);
    }
};

void Location::moveUp(){
    Point newPosition = Point(this->location.getX(), this->location.getY() + 1);
    
    if ( freeLocation.find(newPosition) == freeLocation.end() ) {
        std::cout << "\033[1;31mThere is no way\033[0m" << std::endl;
    } else {
        this->changePosition(newPosition);
        this->location.setY(this->location.getY() + 1);
    }
};

void Location::moveDown(){
    Point newPosition = Point(this->location.getX(), this->location.getY() - 1);
    
    if ( freeLocation.find(newPosition) == freeLocation.end() ) {
        std::cout << "\033[1;31mThere is no way\033[0m" << std::endl;
    } else {
        this->changePosition(newPosition);
        this->location.setY(this->location.getY() - 1);
    }
};

void Location::changePosition(const Point& newPosition) {
    freeLocation.erase(this->location);
    freeLocation.insert(newPosition);
    occupiedLocation.insert(std::pair<Point, char>(newPosition, occupiedLocation.at(this->location)));
    occupiedLocation.erase(this->location);
    
};

Point Location::findFreeLocation() {
    std::set<Point>::iterator it = freeLocation.begin();
    Point nearestLocation = *it;
    double minDistance = this->location.distance(*it);
    double currentDistance;
    
    for ( ; it != freeLocation.end(); ++it ) {
        if ( minDistance > this->location.distance(*it) ) {
            minDistance = this->location.distance(*it);
            nearestLocation = *it;
        }
    }
    
    return nearestLocation;
};

void Location::clearLocation() {
    std::cout << "\033[2J" << "\033[3J" << "\033[1;1H";
};

void Location::wait() {
    std::cout << "\033[1;30mPress Enter to Continue.....\033[0m" << std::endl;
    std::cin.get();
};

void Location::addUnit(char title, const Point& location) {
    if ( freeLocation.find(location) != freeLocation.end() ) {
        freeLocation.erase(location);
        occupiedLocation.insert(std::pair<Point, char>(location, title));
    } else {
        throw OccupiedLocationException();
    }
};

void Location::changeUnitTitle(char newTitle, const Point& location) {
    occupiedLocation.at(location) = newTitle;
};

void Location::deleteUnit(const Point& location) {
    occupiedLocation.erase(location);
    freeLocation.insert(location);
};

std::set<Point> Location::freeLocation;
std::map<Point, char> Location::occupiedLocation;