<?php
    class Point {
        private $x, $y;
        
        private function validate($value) {
            if ( is_numeric($value)) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($x, $y) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function distance(Point $other) {
            return hypot($this->x-$other->x, $this->y-$other->y);
        }
        
        public function isEqual(Point $other) {
            if ( $this->x == $other->x && $this->y == $other->y ) {
                echo $this . " is equal to " . $other . PHP_EOL;
            } else {
                echo $this . " is  not equal to " . $other . PHP_EOL; 
            }
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }
?>
