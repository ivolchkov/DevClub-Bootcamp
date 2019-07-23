#ifndef RANGE_H
#define RANGE_H

#include <iostream>

class Range {
    private:
        int start;
        int step;
        int last;
        int current;
    public:
        Range(int start, int step, int last);
        
        void next();
        void prev();
        void begin();
        void end();
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int operator*() const;
        bool isOver();
        bool isStart();
};

#endif //RANGE_H