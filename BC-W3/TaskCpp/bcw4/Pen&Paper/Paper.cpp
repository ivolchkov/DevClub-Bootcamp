#include "Paper.h"

Paper::Paper(int maxSymbols) {
    this->maxSymbols = maxSymbols;
    this->symbols = 0;
}
Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}
int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    if ( this->symbols == this->maxSymbols ) {
        throw OutOfSpace();
    }
    this->symbols += message.size();
    
    if ( this->symbols > this->maxSymbols ) {
        int temp = message.size() - (this->symbols - this->maxSymbols);
        
        this->symbols = this->maxSymbols;
        this->content += message.substr(0, temp);
    } else {
        this->content += message; 
    }
}
void Paper::show() const {
    std::cout << this->content << std::endl;
}

