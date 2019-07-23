<?php
    class Date {
        private $day;
        private $month;
        private $year;
        
        private function validate($day, $month, $year) {
            if ( $day < 0 || $month < 0 || $year < 0 ) {
                throw new Exception("Invalid date!");
            }
            if ( $month > 12 ) {
                throw new Exception("Invalid month!");
            }
            if ( $year > 2002 ) {
                throw new Exception("Invalid year!");
            }
            if ( $day <= 31 ) {
                if ( $month == 2 ) {
                    if ( $year % 4 == 0 && $day > 29 ) {
                        throw new Exception("Invalid day!");
                    } else if( $year % 4 != 0 && $day > 28 ) {
                        throw new Exception("Invalid day!");
                    }
                }
                if ( $month == 4 || $month == 6 || $month == 9 || $month == 11 ) {
                    if ( $day == 31 ) {
                        throw new Exception("Invalid day!");
                    }
                }
            } else {
                throw new Exception("Invalid day!");
            }
        }
        
        public function __construct($day, $month, $year) {
            $this->validate($day, $month, $year);
            
            $this->day = $day;
            $this->month = $month;
            $this->year = $year;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __toString() {
            if ( $this->month > 9 ) {
                return sprintf("%d.%d.%d", $this->day,
                                           $this->month,
                                           $this->year);
            } else {
                return sprintf("%d.0%d.%d", $this->day,
                                            $this->month,
                                            $this->year);
            }
        }
    }
    
?>