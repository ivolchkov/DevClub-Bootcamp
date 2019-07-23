#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

template <class T>
class File {
    private:
        std::ifstream file;
        T element;
        
    public:
        File(const char* filename);
        ~File();
        
        void next();
        void end();
        void operator++();
        void operator++(int);
        T operator*() const;
        bool isOver();
};

#endif //FILE_H