// Passport
// Каждый паспорт содержит шестизначный уникальный номер и двухбуквенную серию.
// Номера присваиваются автоматически.
// При достижении последнего шестизначного номера, серию следует изменить на следующую.
// Также можно в произвольный момент времени задать новую серию, при этом нумерация начинается с начала.
// При изменении серии можно задать новый стартовый номер.

// Каждый паспорт содержит имя, фамилию, год, месяц и день рождения.

// Предусмотрите возможные исключения.
#include <iostream>

#include "Date.h"

class InvalidSerialNu {};
class InvalidSerialSize {};
class InvalidId {};

class Passport {
    private:
        std::string name;
        std::string surname;
        Date date;
        int lastId;
        std::string serNu;
    public:
        static int id;
        static std::string serialNu;
    public:
        Passport(const Date& date,const std::string& name = "Ivan",const std::string& surname = "Ivanov" ) {
            this->name = name;
            this->surname = surname;
            this->date = date;
            
            setStartId();
            
            this->serNu = serialNu;
            this->lastId = id;
        }
        
        ~Passport() {}
        
        const std::string& getName() const {
            return this->name;
        }
        
        const std::string& getSurname() const {
            return this->surname;
        }
        
        const Date& getDate() const {
            return this->date;
        }
        
        int getId() const {
            return this->lastId;
        }
        
        std::string getSeries() const {
            return this->serNu;
        }
        
        static void setNewSeries(const std::string& series, int newId);
        static void setNewId(int newId);
        static void setStartId();
        static void setSerialNu();
};

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << passport.getName() << " " << passport.getSurname() << " : " << passport.getDate() << " passport : " << passport.getSeries() << " " << passport.getId() ;
    
    return out;
}

int Passport::id = 1;
std::string Passport::serialNu = "NULL";

void Passport::setStartId() {
    if ( id >= 100000 ) {
        id += 1;
    }
    if ( id == 1 || id > 999999 ) {
        id = 100000;
        setSerialNu();
    }
    
}

void Passport::setSerialNu() {
    if ( serialNu == "NULL" ) {
        serialNu = "AA";
    } else {
        serialNu[1] += 1;
    }
    
    if ( serialNu[1] == '[' ) {
        serialNu[1] = 'A';
        serialNu[0] += 1;
    }
    if ( serialNu[0] == '[' ) {
        throw InvalidSerialNu();
    }
}

void Passport::setNewSeries(const std::string& series, int newId) {
    if ( series.size() > 2 ) {
        throw InvalidSerialSize();
    }
    
    if ( series[0] < 'A' || series[0] > 'Z' ) {
        throw InvalidSerialNu();
    }
    
    if ( series[1] < 'A' || series[1] > 'Z' ) {
        throw InvalidSerialNu();
    }
    
    serialNu = series;
    setNewId(newId-1);
}

void Passport::setNewId(int newId) {
    if ( newId > 999999 || newId < 100000 ) {
        throw InvalidId();
    } else {
        id = newId;
    }
}

int main() {
    Date *date = new Date(18, 12, 1997);
    Passport *pass = new Passport(*date, "Igor", "Volchkov");
    
    Date *date2 = new Date(13, 11, 1995);
    Passport *pass2 = new Passport(*date2, "Anya", "Volchkova");
    
    
    std::cout << *pass << std::endl;
    
    std::cout << *pass2 << std::endl;
    
    Passport::setNewSeries("AZ" , 999999);
    
    Date *date3 = new Date(19, 9, 1990);
    Passport *pass3 = new Passport(*date3, "Valik", "Lopuha");
    
    std::cout << *pass3 << std::endl;
    
    Date *date4 = new Date(19, 9, 1990);
    Passport *pass4 = new Passport(*date4, "Yura", "Mikulin");
    
    std::cout << *pass4 << std::endl;
    return 0;
}