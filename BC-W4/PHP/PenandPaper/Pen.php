<?php
    class Pen {
        private $inkCapacity;
        private $inkAmount;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param!");
        }
        
        public function __construct($inkCapacity = 4096) {
            $this->inkCapacity = $this->validate($inkCapacity);
            $this->inkAmount = $this->inkCapacity;
        }
        
        public function __get($name) {
            if ( property_exists( $this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function write(Paper $paper, string $message) {
            $this->inkAmount -= strlen($message);
            
            if ( $this->inkAmount < 0 ) {
                throw new Exception("Out of Ink");
            }
            
            $paper->addContent($message);
            
        }
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
        
    }
?>