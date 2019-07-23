#include "File.h"

template <class T>
File<T>::File(const char* filename) {
    this->file.open(filename);
    this->file >> this->element;
};

template <class T>
File<T>::~File() {
    this->file.close();
}

template <class T>
void File<T>::next() {
    if ( this->isOver() ) {
        this->file >> this->element;
    }
}

template <class T>
void File<T>::end() {
    for ( ; this->file.good(); this->file>>this->element );
}

template <class T>
void File<T>::operator++() {
    this->next();
}

template <class T>
void File<T>::operator++(int) {
    this->next();
}

template <class T>
T File<T>::operator*() const {
    return this->element;
}

template <class T>
bool File<T>::isOver() {
    return this->file.good();
}

template class File<int>;
template class File<float>;
template class File<double>;
template class File<char>;