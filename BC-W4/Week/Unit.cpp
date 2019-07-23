#include <iostream>

class Unit {
    int hp;
    int dmg;
    
    public:
        Unit(int hp, int dmg) {
            this->hp = hp;
            this->dmg = dmg;
            std::cout << "Constructor(Unit)." << std::endl;
        };
        virtual ~Unit() {
            std::cout << "Destructor(Unit)." << std::endl;
        };
        
        virtual void sayMyName()  {
            std::cout << "say my name, say my name ... if you love me, make me crazy!!..." << std::endl;
        }
};

class Soldier : virtual public Unit {
    std::string* name;
    
    public:
        Soldier(int hp, int dmg, const std::string& name) : Unit(hp, dmg) {
            this->name = new std::string(name);
            std::cout << "Constructor(Soldier)." << std::endl;
        };
        ~Soldier() {
            delete(this->name);
            std::cout << "Destructor(Soldier)." << std::endl;
        };
        
        virtual void sayMyName() {
            std::cout << "My name is " << *(this->name) << std::endl;
            
        }
};

class Horse : virtual public Unit {
    std::string* name;
    
    public:
        Horse(int hp, int dmg, const std::string& name) : Unit(hp, dmg) {
            this->name = new std::string(name);
            std::cout << "Constructor(Horse)." << std::endl;
        };
        ~Horse() {
             delete(this->name);
             std::cout << "Destructor(Horse)." << std::endl;
        }
        
        virtual void sayMyName() {
            std::cout << "Igogoshechki!!!" << std::endl;
        };
};

class Centaur : virtual public Horse, virtual public Soldier {
    public:
        Centaur(int hp, int dmg, const std::string& name) :
            Horse(hp, dmg, name), Soldier(hp, dmg, name), Unit(hp, dmg) {
                std::cout << "Constructor(Centaur)." << std::endl;
            }
        virtual ~Centaur() {
            std::cout << "Destructor(Centaur)." << std::endl;
        };
        
        virtual void sayMyName() {
            Horse::sayMyName();
        }
};

void hospitalReception(Unit* u) {
    u->sayMyName();
    delete(u);
}

class A {
    public:
        A() {};
        ~A() {};
        
        virtual void foo() = 0;
};

class B final : public A {
    public:
        B() {};
        ~B() {};
        
        virtual void foo() {
            std::cout << "OOps!" << std::endl;
        }
};

class C : public B {
    public:
        C() {};
        ~C() {};
        
        virtual void foo() {
            std::cout << "Ups!" << std::endl;
        }
};


conn = redis.get_connection_pool("redis://localhost")

try {
    res = conn.execute('GET', 'my_saturday_programm')
} catch (someException e) {
    do_some_alternative...
} finally {
    conn.finalize()
}





int main() {
    // Unit u;
    // Soldier* soldier = new Soldier(100, 25, "Bobba");
    // Horse* horse = new Horse(250, 30, "Cherik");
    Centaur* centaur = new Centaur(270, 50, "Ololik");
    
    // hospitalReception(soldier);
    // hospitalReception(horse);
    // hospitalReception(centaur);
    // centaur->sayMyName();
    
    // A* a = new A();
    C* c = new C();
    
    return 0;
}
