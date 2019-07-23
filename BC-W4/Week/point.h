#ifndef POINT_H
#define POINT_H

#include <iostream>

template <class T>
class Point {
    private:
        T x;
        T y;
    
    public:
        Point(T x, T y);
        ~Point();
        
        T getX() const;
        T getY() const;
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Point<T>& point);

#endif // POINT_H
