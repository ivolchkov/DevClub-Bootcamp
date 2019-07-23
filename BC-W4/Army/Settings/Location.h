#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include "Point/Point.h"
#include "../Exceptions/Exceptions.h"

#define FIELD_HEIGHT 16
#define FIELD_WIDHT 36

class Location {
    protected:
        Point location;
        static std::set<Point> freeLocation;
        static std::map<Point, char> occupiedLocation;
    public:
        Location(int x, int y);
        virtual ~Location();
        
        int getX() const;
        int getY() const;
        Point getLocation() const;
        
        double distance(const Point& other) const;
        
        static void addUnit(char title, const Point& location);
        static void changeUnitTitle(char newTitle, const Point& location);
        static void deleteUnit(const Point& location);
        
        void move(char direction);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        
        void changePosition(const Point& newPosition);
        Point findFreeLocation();
        
        void printField();
        void clearLocation();
        void wait();
};

#endif //LOCATION_H