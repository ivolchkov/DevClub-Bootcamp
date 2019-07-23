<?php
    class Identifiable {
        private $id;
        private static $lastId  = 0;
        
        public function __construct() {
            self::$lastId += 1;
            $this->id = self::$lastId;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
    }
    
    $count1 = new Identifiable();
    $count2 = new Identifiable();
    $count3 = new Identifiable($count2);
    $count4 = new Identifiable();
    $count4 = $count1;
    
    echo "1:" . $count1->id . PHP_EOL;
    echo "2:" . $count2->id . PHP_EOL;
    echo "3:" . $count3->id . PHP_EOL;
    echo "4:" . $count4->id . PHP_EOL;
    
?>