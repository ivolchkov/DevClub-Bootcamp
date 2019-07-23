#include <iostream>

class Countable {
    private: 
        static int totalCount;
        
    public:
        Countable() {
            totalCount += 1;
        }
        
        Countable(const Countable& copy) {
            totalCount += 1;
        }
        
        ~Countable() {
            totalCount -= 1;
        }
        
        Countable& operator=(const Countable& copy) {
            totalCount += 1;
        }
        
        static int getTotalCount();
};

int Countable::totalCount = 0;

int Countable::getTotalCount() {
    return totalCount;
}


int main() {
    Countable *count1 = new Countable();
    Countable *count2 = new Countable();
    Countable *count4 = new Countable(*count2);
    Countable *count3;
    *count3 = *count1;
    
    std::cout << Countable::getTotalCount() << std::endl;
    
    delete count1;
    
    std::cout << Countable::getTotalCount() << std::endl;
    
    return 0;
}
