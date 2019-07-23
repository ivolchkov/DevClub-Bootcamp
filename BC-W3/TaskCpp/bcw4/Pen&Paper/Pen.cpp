#include "Pen.h"

Pen::Pen(int inkCapacity) {
    this->inkCapacity = inkCapacity;
    this->inkAmount = inkCapacity;
}
Pen::~Pen() {}

int Pen::getInkAmount() const {
    return this->inkAmount;
}
int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    this->inkAmount -= message.size();
    
    if ( this->inkAmount < 0 ) {
        throw OutOfInk();
    }
    
    paper.addContent(message);
}
void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}