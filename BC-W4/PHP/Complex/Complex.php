<?php
    class Complex {
        private $real, $imaginary;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param!");
        }
        
        public function __construct($re, $im) {
            $this->real = $this->validate($re);
            $this->imaginary = $this->validate($im);
        }
        
        public function __get($name) {
         if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $value;
            } else {
                throw new Exception("Attribute error: attribute $name not found");
            }
        }
        
        public function isEqual(Complex $other) {
            if ( $this->real == $other->real && $this->imaginary == $other->imaginary ) {
                echo $this . " is equal to " . $other . PHP_EOL;
            } else {
                echo $this . " is not equal to " . $other . PHP_EOL;
            }
        }
        
        public function add(Complex $other) {
            $this->real += $other->real;
            $this->imaginary += $other->imaginary;
        }
        
        public function substract(Complex $other) {
            $this->real -= $other->real;
            $this->imaginary -= $other->imaginary;
        }
        
        public function multiple(Complex $other) {
            $temp = clone $this;
            
            $this->real = $temp->real * $other->real - $temp->imaginary * $other->imaginary;
            $this->imaginary = $temp->imaginary * $other->real + $temp->real * $other->imaginary;
        }
        
        public function __toString() {
            return sprintf("%d%+di", $this->real, $this->imaginary);
        }
    }
    
    
    
    $a = new Complex(2, 5);
    $b = new Complex(3, 7);
    $c = new Complex(-3, -7);
    $d = $a;
    $e = clone $a;

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;
    
    $a->isEqual($b);
    $b->isEqual($c);
    
    $complex = new Complex(2, 8);

    echo $complex . PHP_EOL;
    
    $complex->real = 42;

    echo $complex->real . PHP_EOL;
    echo $complex->imaginary . PHP_EOL;
    echo "a: " . $a . PHP_EOL;
    
    $a->add($b);
    
    echo "a: " . $a . PHP_EOL;
    
    $a->multiple($c);
    echo "mult a: " . $a . PHP_EOL;
?>