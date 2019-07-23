#ifndef GEOPROG_H
#define GEOPROG_H

#include <iostream>

class GeoProg {
    private:
        double start;
        double denominator;
        double last;
        double current;
    public:
        GeoProg(double start, double denominator, double last);
        
        void next();
        void prev();
        void begin();
        void end();
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        double operator*() const;
        bool isOver();
        bool isStart();
};

#endif //GEOPROG_H