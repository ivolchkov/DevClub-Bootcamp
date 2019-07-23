#include "Factorial.h"

Factorial::Factorial(int last) : current(1),
                                 value(1),
                                 last(last) {};

void Factorial::next() {
    if ( this->isOver() ) {
        this->current += 1;
        this->value *= this->current;
    }
}
void Factorial::prev() {
    if ( this->isStart() ) {
        this->value /= this->current;
        this->current -= 1;
    }
}
void Factorial::begin() {
    for ( ; this->isStart() ; this->value /= this->current, this->current -= 1 );
}
void Factorial::end() {
    for ( ; this->isOver() ; this->current += 1, this->value *= this->current );
}
void Factorial::operator++() {
    this->next();
}
void Factorial::operator++(int) {
    this->next();
}
void Factorial::operator--() {
    this->prev();
}
void Factorial::operator--(int) {
    this->prev();
}
double Factorial::operator*() const {
    return this->value;
}
bool Factorial::isOver() {
    return this->current < this->last;
}
bool Factorial::isStart() {
    return this->current > 1;
}
