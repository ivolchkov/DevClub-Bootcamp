#include "Array.h"

template <class T>
Array<T>::Array(T &arr, int size) {
    this->array = &arr;
    this->size = size;
    this->current = 0;
    this->value = this->array[0];
}

template <class T>
void Array<T>::next() {
    if ( this->isOver() ) {
        this->current += 1;
        this->value = this->array[this->current];
    }
}

template <class T>
void Array<T>::prev() {
    if ( this->isStart() ) {
        this->current -= 1;
        this->value = this->array[this->current];
    }
}

template <class T>
void Array<T>::begin() {
    for ( ; this->isStart(); this->current -= 1, this->value = this->array[this->current]);
}

template <class T>
void Array<T>::end() {
    for ( ; this->isOver(); this->value = this->array[this->current], this->current += 1);
}

template <class T>
void Array<T>::operator++() {
    this->next();
}

template <class T>
void Array<T>::operator++(int) {
    this->next();
}

template <class T>
void Array<T>::operator--() {
    this->prev();
}

template <class T>
void Array<T>::operator--(int) {
    this->prev();
}

template <class T>
T Array<T>::operator*() const {
    return this->value;
}

template <class T>
T Array<T>::operator[](int index) const {
    return this->array[index];
}

template <class T>
bool Array<T>::isOver() {
    return this->current < this->size;
}

template <class T>
bool Array<T>::isStart() {
    return this->current != 0;
}

template class Array<int>;
template class Array<float>;
template class Array<double>;