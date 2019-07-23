#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>

class Fibonacci {
    private:
        long long value;
        int current;
        int last;
    public:
        Fibonacci(int last);
        
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
        long long getValue(int num);
};


#endif //FIBONACCI_H