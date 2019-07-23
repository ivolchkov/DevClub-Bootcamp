#ifndef PRIME_H
#define PRIME_H

#include <iostream>

class Prime {
    private:
        int current;
        int last;
        int *array;
    public:
        Prime(int last);
        ~Prime();
        
        void next();
        void prev();
        void begin();
        void end();
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        double operator*() const;
        bool isPrime(int num);
        bool isOver();
        bool isStart();
        int getValue(int number);
};

#endif //PRIME_H