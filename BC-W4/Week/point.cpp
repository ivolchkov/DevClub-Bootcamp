#include <iostream>

#include "point.h"

template <class T>
Point<T>::Point(T x, T y) {
    this->x = x;
    this->y = y;
};

template <class T>
Point<T>::~Point() {};

template <class T>
T Point<T>::getX() const {
    return this->x;
};

template <class T>
T Point<T>::getY() const {
    return this->y;
};

template class Point<int>;
template class Point<float>;
template class Point<double>;

template <class T>
std::ostream& operator<<(std::ostream& out, const Point<T>& point) {
    out << '(' << point.getX() << ", " << point.getY() << ')';
    return out;
};

template std::ostream& operator<<(std::ostream& out, const Point<int>& point);
template std::ostream& operator<<(std::ostream& out, const Point<float>& point);
template std::ostream& operator<<(std::ostream& out, const Point<double>& point);
