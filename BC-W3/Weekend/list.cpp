#include "list.h"
#include <cstdlib>

List::List(int quantity) {
    this->quantity = quantity;
    
    if ( this->quantity < 100 ) {
        if ( this->quantity < 0 ) {
            throw InvalidListSizeException("Are you crazy?");
        }
        this->quantity = 100;
    }
    
    this->current = 0;
    this->multiplier = 1.05;
    
    // int* temp = (int*)malloc(sizeof(int) * this->quantity);
    //int* temp = (int*)calloc(sizeof(int) ,List:: this->quantity); vse budet '0'
    int* temp = new int[this->quantity]();
    
    if ( temp == NULL ) {
        throw RunOutOfMemoryException();
        
    }
    
    this->array = temp;
    
    std::cout<<"List constructor works!"<<std::endl;
}

List::~List() {
    delete this->array;
    std::cout<<"List destructor works!"<<std::endl;
}

List::List(const List& copy) {
    this->quantity = copy.quantity;
    this->current = copy.current;
    this->multiplier = copy.multiplier;
    
    int* temp = new int[this->quantity]();
    
    this->array = temp;
}

// void List::listPrint() {
//     int limit = this->current - 1;
//     std::cout<<"[";
    
//     for ( int i = 0; i < limit; i++ ) {
//         std::cout<<this->array[i]<<", ";
//     }
    
//     if ( limit < 0 ) {
//         std::cout<<"]"<<std::endl;
//     } else {
//         std::cout<<this->array[limit] << "]" << std::endl;
//     }
// }


void List::resize(Action action) {
    int newQuantity;
    
    if ( action == REDUCE ) {
        newQuantity = this->quantity / this->multiplier;
        std::cout<<"Reduce size"<<std::endl;
    } else {
        newQuantity = this->quantity * this->multiplier;
        std::cout<<"Increase size" << std::endl;
    }
    
    int *temp = (int*)realloc(this->array, newQuantity * sizeof(int));
    
    if ( !temp ) {
        std::cout<<"Unsufficient memory"<<std::endl;
        return;
    }
    
    this->array = temp;
    this->quantity = newQuantity;
    std::cout<<"Memory reallocated ("<<this->quantity<<", "<< this->current << ")"<<std::endl;
}
void List::pushBack( int value) {
    if ( this->current == this->quantity ) {
        this->resize(INCREASE);
    }
    this->array[this->current] = value;
    this->current += 1;
}

void List::fillList(int elems) {
    for ( int i = 0, counter = 1; i < elems; i++, counter++ ) {
        this->pushBack(counter);
    }
}

int List::pop() {
    int result = this->array[this->current - 1];
    this->current -= 1;
    
    float diff = (float)this->quantity / (float)this->current;
    if ( diff > this->multiplier && this->quantity > 100 ) {
        this->resize(REDUCE);
    }
    
    return result;
}

int* List::getArray() const {
    return this->array;
}
int List::getQuantity() const {
    return this->quantity;
}
int List::getCurrent() const {
    return this->current;
}
float List::getMultiplier() const {
    return this->multiplier;
}


void List::setMultiplier(float newMult) {
    this->multiplier = newMult;
}


const int List::operator[](int idx) const{
    return this->array[idx];
}




std::ostream& operator<<(std::ostream& out, List& list) {
    int limit = list.getCurrent() - 1;
    std::cout<<"[";
    
    for ( int i = 0; i < limit; i++ ) {
        out<<list[i]<<", ";
    }
    
    if ( limit < 0 ) {
        std::cout<<"]"<<std::endl;
    } else {
        out<<list[limit] << "]";
    }
    
    return out;
}