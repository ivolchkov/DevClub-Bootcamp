7#include "List.h"

List::List(int capacity, double multiplier){
    this->capacity = capacity;
    this->multiplier = multiplier;
    this->current = 0;
    
    if ( this->capacity < 0 ) {
        throw ZeroLenException();
    }
    
    int* temp = (int*)malloc(sizeof(int) * this->capacity);
    
    if ( temp == NULL ) {
        throw OutOfMemoryException();
    }
    
    this->array = temp;
}
List::~List(){
    free(this->array);
}

int List::size() const {
    return this->current;
}
int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {
    for ( int i = index; i < this->current; i++ ) {
        this->array[i] = this->array[i+1];
    }
    
    this->current -= 1;
}
void List::insert(int value, int index) {
    this->current += 1;
    
    if ( this->current > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, sizeof(int) * newCapacity);
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    
    for ( int i = this->current - 1; i >= index; i-- ) {
        this->array[i+1] = this->array[i];
    }
    
    this->array[index] = value;
}
int List::find(int value) const {
    for ( int index = 0; index < this->current; index++ ) {
        if ( array[index] == value ) {
            return index;
        }
    }
}
void List::push_back(int value) {
    int newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, sizeof(int) * newCapacity);
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        
        this->capacity = newCapacity;
        this->array = newArray;
    }
    this->array[this->current] = value;
    this->current = newCurrent;
}
int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    
    return this->array[this->current];
}

void List::sort() {
    for ( int i = 1; i <= this->current; i++ ) {
        int temp = this->array[i];
        int j = i;
        
        for ( int prev = j - 1; j > 0 && this->array[prev] > temp; j--, prev-- ) {
            this->array[j] = this->array[prev];
        }
        this->array[j] = temp;
    }
}

int List::operator[](int index) const {
    return this->array[index];
}
bool List::operator==(const List& other) const {
    int i = 0;
    
    for ( ; i < this->current && i < other.current; i++ ) {
        if ( this->array[i] != other.array[i] ) {
            return false;
        }
    }
    if ( i == this->current && i == other.current ) {
        return true;
    }
    return false;
}
bool List::operator!=(const List& other) const {
    return !operator==(other);
}


std::ostream& operator<<(std::ostream& out, const List& list) {
    if ( list.size() == 0 ) {
        throw ZeroLenException();
    }
    int last = list.size() - 1;
    
    for ( int i = 0; i < last; i++ ) {
        out << list[i] << " ";
    }
    out << list[last];
    
    return out;
}