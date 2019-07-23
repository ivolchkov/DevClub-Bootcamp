#include "Prime.h"

Prime::Prime(int last) {
    this->current = 1;
    this->last = last;
    this->array = (int*)malloc(sizeof(int) * this->last);
    this->array[0] = 2;
} 
Prime::~Prime() {
    free(array);
}
void Prime::next() {
    if ( this->isOver() ) {
        this->array[this->current] = this->getValue(this->current);
        this->current += 1;
    }
}
void Prime::prev() {
    if ( this->isStart() ) {
        this->current -= 1;
    }
}
void Prime::begin() {
    this->current = 1;
    this->array[this->current] = this->getValue(this->current);
}
void Prime::end() {
    for ( ; this->isOver() ; this->current += 1, this->array[this->current] = this->getValue(this->current) );
}
void Prime::operator++() {
    this->next();
}
void Prime::operator++(int) {
    this->next();
}
void Prime::operator--() {
    this->prev();
}
void Prime::operator--(int) {
    this->prev();
}
double Prime::operator*() const {
    return this->array[this->current-1];
}
bool Prime::isOver() {
    return this->current < this->last;
}
bool Prime::isStart() {
    return this->current > 1;
}
bool Prime::isPrime(int num) {
    for ( int i = 2, mid = num / 2 + 1; i <= mid; i++ ) {
        if ( num % i == 0 ) {
            return false;
        }
    }
    return true;
}
int Prime::getValue(int number) {
    int max;
    
    for ( int i = 2, count = 0; count < number; i++ ) {
        bool flag = this->isPrime(i);
        
        if ( flag ) {
            count += 1;
            max = i;
        }
    }
    return max;
}