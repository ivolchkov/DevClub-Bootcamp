#include "Range.h"

Range::Range(int start, int step, int last) : start(start),
                                              step(step),
                                              last(last),
                                              current(start) {};

void Range::next() {
    if ( !this->isOver() ) {
        this->current += this->step;
    }
}
void Range::prev() {
    if ( !this->isStart() ) {
        this->current -= this->step;
    }
}
void Range::begin() {
    for ( ; !this->isStart() ; this->current -= this->step  );
}
void Range::end() {
    for ( ; !this->isOver() ; this->current += this->step );
}
void Range::operator++() {
    this->next();
}
void Range::operator++(int) {
    this->next();
}
void Range::operator--() {
    this->prev();
}
void Range::operator--(int) {
    this->prev();
}
int Range::operator*() const {
    return this->current;
}
bool Range::isOver() {
    int next = this->current + this->step;
    
    return next > this->last;
}
bool Range::isStart() {
    int prev = this->current - this->step;
    
    return prev < this->start;
}