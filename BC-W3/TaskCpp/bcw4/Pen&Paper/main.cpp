#include <iostream>
#include "Paper.h"
#include "Pen.h"

int main() {
    Pen pen(4096);
    Paper paper(4096);
    
    std::cout<< "In the beggining "<< paper.getSymbols() <<" " << paper.getMaxSymbols() << std::endl;
    std::cout<< "In the beggining " << pen.getInkAmount() <<" " << pen.getInkCapacity() << std::endl;
    pen.write(paper, "Hello, world!");
    paper.show();
    std::cout<< paper.getSymbols() <<" "<< paper.getMaxSymbols() << std::endl;
    std::cout<< pen.getInkAmount() <<" "<< pen.getInkCapacity() << std::endl;
    pen.refill();
    std::cout<<"After refilling pen ink"<< pen.getInkAmount() <<" "<< pen.getInkCapacity() << std::endl;
    // pen.write(paper, "Hi");
    // paper.addContent("Hi");
}