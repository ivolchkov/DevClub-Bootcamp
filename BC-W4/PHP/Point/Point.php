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
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw new Exception("Attribute error: attribute $name not found");
            }
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
    
    $a = new Point(2, 5);
    $b = new Point(3, 7);
    $c = new Point(3, 7);
    $d = $a;
    $e = clone $a;

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;

    // echo compare($a, $b) . PHP_EOL;
    // echo compare($b, $c) . PHP_EOL;
    $a->isEqual($b);
    $b->isEqual($c);
    echo $a->distance($b) . PHP_EOL;
    echo $b->distance($c) . PHP_EOL;
    
    $point = new Point(2, 8);

    echo $point . PHP_EOL;
    
    $point->x = 42;

    echo $point->x . PHP_EOL;
    echo $point->y . PHP_EOL;
?>
