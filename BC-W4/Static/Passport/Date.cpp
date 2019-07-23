#include "Date.h"

void Date::validate(int day, int month, int year) {
    if ( this->day < 0 || this->month < 0 || this->year < 0 ) {
        throw InvalidDate("Invalid date!");
    }
    if ( this->month > 12 ) {
        throw InvalidDate("Invalid month!");
    }
    if ( this->year > 2002 ) {
        throw InvalidDate("Invalid year!");
    }
    if ( this->day <= 31 ) {
        if ( this->month == 2 ) {
            if ( this->year % 4 == 0 && this->day > 29 ) {
                throw InvalidDate("Invalid day!");
            } else if( this->year % 4 != 0 && this->day > 28 ) {
                throw InvalidDate("Invalid day!");
            }
        }
        if ( this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11 ) {
            if ( this->day == 31 ) {
                throw InvalidDate("Invalid day!");
            }
        }
    } else {
        throw InvalidDate("Invalid day!");
    }
}
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    
    validate(this->day, this->month, this->year);
}
Date::~Date() {}

int Date::getDay() const {
    return this->day;
}
int Date::getMonth() const {
    return this->month;
}
int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    if ( date.getMonth() > 9 ) {
        out << date.getDay()<<"."<<date.getMonth()<<"."<<date.getYear();
    } else {
        out << date.getDay()<<".0"<<date.getMonth()<<"."<<date.getYear();
    }
    
    return out;
}