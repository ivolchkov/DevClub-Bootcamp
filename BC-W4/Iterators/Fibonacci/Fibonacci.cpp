#include "Fibonacci.h"

Fibonacci::Fibonacci(int last) : value(0),
                                 current(0),
                                 last(last) {}

void Fibonacci::next() {
    if ( this->last < 0 ) {
        this->current -= 1;
        this->value = this->getValue(this->current);
    } else {
        this->current += 1;
        this->value = this->getValue(this->current);
    }
}
void Fibonacci::prev() {
    if ( this->last < 0 ) {
        this->current += 1;
        this->value = this->getValue(this->current);
    } else {
        this->current -= 1;
        this->value = this->getValue(this->current);
    }
}
void Fibonacci::begin() {
    this->current = 0;
    this->value = this->getValue(this->current);
}
void Fibonacci::end() {
    this->current = this->last;
    this->value = this->getValue(this->current);
}
void Fibonacci::operator++() {
    this->next();
}
void Fibonacci::operator++(int) {
    this->next();
}
void Fibonacci::operator--() {
    this->prev();
}
void Fibonacci::operator--(int) {
    this->prev();
}
double Fibonacci::operator*() const {
    return this->value;
}
bool Fibonacci::isOver() {
    if ( this->last < 0 ) {
        return this->last < this->current;
    }
    return this->current < this->last;
}
bool Fibonacci::isStart() {
    return this->current > 0;
}
long long Fibonacci::getValue(int num) {
    long long fib1 = 1;
    long long fib2 = 1;
    bool flag = false;
    
    if ( num < 0 ) {
        num *= -1;
        
        if ( num % 2 == 0 ) {
            flag = true;
        }
    }
    if ( num == 0 ) {
        fib2 = 0;
    }
    if ( num > 2 ) {
        for ( int i = 2; i < num; i++ ) {
            int fibSumm = fib1 + fib2;
            
            fib1 = fib2;
            fib2 = fibSumm;
        }
    }
    
    if ( flag == true ) {
        fib2 *= -1;
    }
    
    return fib2;
}
