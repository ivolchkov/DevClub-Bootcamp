#ifndef LIST_H
#define LIST_H

#include <iostream>

enum Action{
    INCREASE,
    REDUCE,
};

class RunOutOfMemoryException {};
class InvalidListSizeException {
public:
    std::string message;
    InvalidListSizeException(const std::string& msg) {
        this->message = msg;
    }
};

class List {
    private:
        int *array;
        int quantity;
        int current;
        float multiplier;
        
       
        
    public:
        
         List(int quantity = 100);
        ~List();
        List(const List& copy);
        
        int* getArray()const;
        int getQuantity()const;
        int getCurrent()const;
        float getMultiplier()const;
        
        
        void setMultiplier(float newMult);
        
        void resize(Action action);
        void pushBack(int value);
        void fillList( int elems);
        int pop();
        
        
        const int operator[](int idx) const;
};




std::ostream& operator<<(std::ostream& out, List& list);









#endif //LIST_H