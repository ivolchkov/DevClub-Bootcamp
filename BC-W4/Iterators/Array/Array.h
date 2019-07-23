#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <class T>
class Array {
    private:
        T* array;
        int current;
        int size;
        T value;
    public:
        Array(T &arr, int size);
        
        void next();
        void prev();
        void begin();
        void end();
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        T operator*() const;
        T operator[](int index) const;
        bool isOver();
        bool isStart();
};

#endif //ARRAY_H