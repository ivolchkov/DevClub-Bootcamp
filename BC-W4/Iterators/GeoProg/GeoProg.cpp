#include "GeoProg.h"

GeoProg::GeoProg(double start, double denominator, double last) : start(start),
                                                                  denominator(denominator),
                                                                  last(last),
                                                                  current(start) {};

void GeoProg::next() {
    double next = this->current * this->denominator;
    
    if ( next < 0 ) {
        next *= -1;
    }
    
    if ( next <= this->last ) {
        this->current *= this->denominator;
    }
}
void GeoProg::prev() {
    double prev = this->current / this->denominator;
    
    if ( prev < 0 ) {
        prev *= -1;
    }
    
    if ( prev >= this->start ) {
        this->current /= this->denominator;
    }
}
void GeoProg::begin() {
    for ( ; !this->isStart() ; this->current /= this->denominator );
    
    if ( this->current < this->start ) {
        this->current *= this->denominator;
    }
}
void GeoProg::end() {
    for ( ; !this->isOver() ; this->current *= this->denominator );
    
    if ( this->current > this->last ) {
        this->current /= this->denominator;
    }
}
void GeoProg::operator++() {
    this->next();
}
void GeoProg::operator++(int) {
    this->next();
}
void GeoProg::operator--() {
    this->prev();
}
void GeoProg::operator--(int) {
    this->prev();
}
double GeoProg::operator*() const {
    return this->current;
}
bool GeoProg::isOver() {
    double next = this->current * this->denominator;
    
    if ( next < 0 ) {
        next *= -1;
    }
    return next > this->last;
}
bool GeoProg::isStart() {
    double prev = this->current / this->denominator;
    
    if ( prev < 0 ) {
        prev *= -1;
    }
    return prev < this->start;
}
