<?php
    class Vector {
        private $x, $y;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
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
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw new Exception("Attribute error: attribute $name not found");
            }
        }
        
        public function len() {
            return hypot($this->x, $this->y);
        }
        
        public function isEqual(Vector $other) {
            if ( $this->x == $other->x && $this->y == $other->y ) {
                echo $this . " is equal to " . $other . PHP_EOL;
            } else {
                echo $this . " is not equal to " . $other . PHP_EOL;
            }
        }
        
        public function add(Vector $other) {
            $this->x += $other->x;
            $this->y += $other->y;
        }
        
        public function substract(Vector $other) {
            $this->x -= $other->x;
            $this->y -= $other->y;
        }
        
        public function __toString() {
            return sprintf("(%g, %g)", $this->x, $this->y);
        }
    }
    
    $a = new Vector(2, 5);
    $b = new Vector(3, 7);
    $c = new Vector(3, 7);
    $d = $a;
    $e = clone $a;

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;

    // echo compare($a, $b) . PHP_EOL;
    // echo compare($b, $c) . PHP_EOL;
    $a->isEqual($b);
    $b->isEqual($c);
    echo $a->len() . PHP_EOL;
    echo $b->len() . PHP_EOL;
    
    $vector = new Vector(2, 8);

    echo $vector . PHP_EOL;
    
    $vector->x = 42;

    echo $vector->x . PHP_EOL;
    echo $vector->y . PHP_EOL;
    echo "a: " . $a . PHP_EOL;
    
    $a->substract($b);
    
    echo "a: " . $a . PHP_EOL;
?>
