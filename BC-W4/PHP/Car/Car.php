<?php
    include_once 'Point.php';
    
    class Car {
        private $fuelAmount;
        private $fuelCapacity;
        private $fuelConsumption;
        private $location;
        private $model;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($capacity = 60, $consumption = 0.6,$model = "Mercedes", $location = null) {
            $this->fuelCapacity = $this->validate($capacity);
            $this->fuelConsumption = $this->validate($consumption);
            $this->fuelAmount = 0;
            
            $this->location  = is_null($location) ? new Point(0, 0) : $location;
            $this->model = $model;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function drive(Point $destination) {
            $distance = $this->location->distance($destination);
            
            $this->fuelAmount -= $this->fuelConsumption * $distance;
            
            if ( $this->fuelAmount < 0 ) {
                throw new Exception("Out of Fuel");
            }
            
            $this->location = $destination;
        }
        
        
        public function refill(int $fuel) {
            $this->fuelAmount += $fuel;
            
            if ( $this->fuelAmount > $this->fuelCapacity ) {
                throw new Exception("Too much fuel");
            }
        }
        
        public function __toString() {
            return sprintf("%s has location - " . $this->location . " with fuel amount - %d, capacity - %d, and consumption - %f",$this->model,
                                                                                                                                  $this->fuelAmount,
                                                                                                                                  $this->fuelCapacity,
                                                                                                                                  $this->fuelConsumption);
        }
    }
    
    $location = new Point(5,5);
    $car = new Car(60, 0.5, "Lanos", $location);
    
    echo "car: " . $car . PHP_EOL;
    
    $car->refill(50);
    $car->drive(new Point(5, 20));
    
    echo "car: " . $car . PHP_EOL;
?>