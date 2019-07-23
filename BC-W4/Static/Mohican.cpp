// В любой момент времени можно получить последнего из могикан, без использования отдельного экземпляра.
// Подсказка: хранить указатель, возвращать ссылку.
#include <iostream>
#include <list>

class Mohican {
    private:
        int id;

        static std::list<Mohican*> MohicanList;
    public:
        Mohican(int id) {
            this->id = id;

            MohicanList.push_back(this);
        }
        
        Mohican(const Mohican& copy) {
            MohicanList.push_back(this);
        }
        
        Mohican& operator=(const Mohican& copy) {
            MohicanList.push_back(this);
        }
        
        ~Mohican() {
            MohicanList.remove(this);
        }
        int getId() const {
            return this->id;
        }
        static Mohican& getLast();
        

};

std::ostream& operator<<(std::ostream& out, const Mohican& mohican) {
    out <<"Mohican: "<< mohican.getId();
    
    return out;
}

std::list<Mohican*> Mohican::MohicanList;

Mohican& Mohican::getLast() {
    return *(MohicanList.back());
}

int main() {
    Mohican *creep1 = new Mohican(1);
    Mohican *creep2 = new Mohican(2);
    Mohican *creep3 = new Mohican(3);
    // Mohican *creep4 = new Mohican(*creep3);
    
    // *creep4 = *creep1;
    
    std::cout << Mohican::getLast() << std::endl;
    
    delete creep2;

    std::cout << Mohican::getLast() << std::endl;
        delete creep3;
      std::cout << Mohican::getLast() << std::endl;  
    return 0;
}