#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <iostream>

class Factorial {
    private:
        unsigned long long value;
        int current;
        int last;
    public:
        Factorial(int last);
        
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

#endif //FACTORIAL_H