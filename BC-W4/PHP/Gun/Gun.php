<?php
    class Gun {
        private $model, $capacity, $amount, $totalShoots, $isReady;
        
        public function __construct(string $model = "Beretta", int $capacity = 8) {
            $this->model = $model;
            $this->capacity = $capacity;
            $this->amount = 0;
            $this->totalShoots = 0;
            $this->isReady = false;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function prepare() {
            $this->isReady = !$this->isReady;
        }
        
        public function reload() {
            $this->amount = $this->capacity;
        }
        
        public function shoot() {
            if ( !$this->isReady ) {
                throw new Exception("Not Ready");
            }
            if ( $this->amount == 0 ) {
                throw new Exception("Out of rounds");
            }
            
            $this->amount -= 1;
            $this->totalShoots += 1;
            $this->isReady = !$this->isReady;
        }
        
        public function __toString() {
            return sprintf("%s has capacity of %d, amount of rounds - %d and total shoots - %d", $this->model,
                                                                                                 $this->capacity,
                                                                                                 $this->amount,
                                                                                                 $this->totalShoots);
        }
    }
    
    $gun = new Gun("Beretta" , 10);
    $mka = $gun;
    $aka = clone $gun;
    
    echo "gun: " . $gun . PHP_EOL;
    echo "gun: " . $mka . PHP_EOL;
    
    $gun->reload();
    $gun->prepare();
    $gun->shoot();
    
    echo "gun: " . $gun . PHP_EOL;
    
?>