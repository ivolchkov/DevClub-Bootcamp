<?php
    class Unit {
        private $name;
        private $hitPoints;
        private $hitPointsLimit;
        private $damage;
        
        private function ensureIsAlive() {
            if ( $this->hitPoints == 0 ) {
                throw new Exception("Unit is dead!");
            }
        }
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param!");
        }
        
        public function __construct($name, $hp, $dmg) {
            $this->name = $name;
            $this->hitPoints = $this->validate($hp);
            $this->hitPointsLimit = $this->hitPoints;
            $this->damage = $this->validate($dmg);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function addHitPoints(int $hp) {
            $this->ensureIsAlive();
            
            $this->hitPoints += $hp;
            
            if ( $this->hitPoints > $this->hitPointsLimit ) {
                $this->hitPoints = $this->hitPointsLimit;
            }
        }
        
        public function takeDamage(int $dmg) {
            $this->ensureIsAlive();
            
            $this->hitPoints -= $dmg;
            
            if ( $this->hitPoints < 0 ) {
                $this->hitPoints = 0;
            }
        }
        
        public function attack(Unit $enemy) {
            $enemy->takeDamage($this->damage);
            $enemy->ensureIsAlive();
            $enemy->counterAttack($this);
        }
        
        public function counterAttack(Unit $enemy) {
            $enemy->takeDamage($this->damage / 2);
        }
        
        public function __toString() {
            return sprintf("\"%s\" : has %d/%d hp, and %d damage.", $this->name,
                                                                    $this->hitPoints,
                                                                    $this->hitPointsLimit,
                                                                    $this->damage);
        }
    }
    
    $unit = new Unit("Barbarian", 20, 20);
    $knight = new Unit("Knight", 23, 25);
    
    echo "Unit: " . $unit . PHP_EOL;
    echo "Unit: " . $knight . PHP_EOL;
    
    $unit->attack($knight);
    
    echo "Unit: " . $unit . PHP_EOL;
    echo "Unit: " . $knight . PHP_EOL;
    
    $knight->addHitPoints(25);
    
    echo "Unit: " . $knight . PHP_EOL;
?>
