public class Date implements Cloneable {
    private int day;
    private int month;
    private int year;
    
    private void validate(int day, int month, int year) throws InvalidDateException {
        if ( this.day < 0 || this.month < 0 || this.year < 0 ) {
            throw new InvalidDateException("Invalid date!");
        }
        if ( this.month > 12 ) {
            throw new InvalidDateException("Invalid month!");
        }
        if ( this.year > 2019 ) {
            throw new InvalidDateException("Invalid year!");
        }
        if ( this.day <= 31 ) {
            if ( this.month == 2 ) {
                if ( this.year % 4 == 0 && this.day > 29 ) {
                    throw new InvalidDateException("Invalid day!");
                } else if( this.year % 4 != 0 && this.day > 28 ) {
                    throw new InvalidDateException("Invalid day!");
                }
            }
            if ( this.month == 4 || this.month == 6 || this.month == 9 || this.month == 11 ) {
                if ( this.day == 31 ) {
                    throw new InvalidDateException("Invalid day!");
                }
            }
        } else {
            throw new InvalidDateException("Invalid day!");
        }
    }
    
    public Date(int day, int month, int year) throws InvalidDateException {
        this.day = day;
        this.month = month;
        this.year = year;
        
        validate(this.day, this.month, this.year);
    }
    
    public Date() throws InvalidDateException {
        this(1, 1, 1970);
    }
    
    public int getDay() {
        return day;
    }
    
    public int getMonth() {
        return month;
    }
    
    public int getYear() {
        return year;
    }
    
    public String toString() {
        if ( month > 9 ) {
            return day + "." + month + "." + year;
        } else {
            return day + ".0" + month + "." + year;
        }
    }
    
    public Date clone() throws CloneNotSupportedException {
        return (Date) super.clone();
    }
}

