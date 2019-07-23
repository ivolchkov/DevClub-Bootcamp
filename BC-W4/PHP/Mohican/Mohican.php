<?php
    class Mohican {
        private $id;
        private $current;
        private static $last;
        
        public function __construct($id = 0) {
            $this->id = $id;
            self::$last = $this;
        }
        
        public function __toString() {
            return sprintf("id: %d", $this->id);
        }
        
        public static function getLast() {
            return self::$last;
        }
    }
    
    $one = new Mohican(1);
    $two = new Mohican(2);
    $three = new Mohican(3);
    
    echo "one: " . $one . PHP_EOL;
    echo "two: " . $two . PHP_EOL;
    echo "three: " . $three . PHP_EOL;
    
    // unset($three);
    
    echo "Last: " . Mohican::getLast() . PHP_EOL;
    
?>