#include <iostream>

class Identifiable {
    private:
        int id;
    public:
        static int lastId;
    public:
        Identifiable() {
            lastId += 1;
            this->id = lastId;
        }
        
        Identifiable(const Identifiable& copy) {
            lastId += 1;
            this->id = lastId;
        }
        
        Identifiable& operator=(const Identifiable& copy) {
            return *this;
        }
        
        ~Identifiable() {}
        
        int getLastId() {
            return this->id;
        }
};

int Identifiable::lastId = 0;

int main() {
    Identifiable *count1 = new Identifiable();
    Identifiable *count2 = new Identifiable();
    Identifiable *count4 = new Identifiable(*count2);
    Identifiable *count3 = new Identifiable();
    *count3 = *count1;
    
    std::cout <<"1:" << count1->getLastId() << std::endl;
    std::cout <<"2:"<< count2->getLastId() << std::endl;
    std::cout <<"3:"<< count3->getLastId() << std::endl;
    std::cout <<"4:"<< count4->getLastId() << std::endl;
    
    delete count1;
    
    // std::cout <<"1:" << count1->getLastId() << std::endl;
    std::cout <<"2:"<< count2->getLastId() << std::endl;
    std::cout <<"3:"<< count3->getLastId() << std::endl;
    std::cout <<"4:"<< count4->getLastId() << std::endl;
    return 0;
}