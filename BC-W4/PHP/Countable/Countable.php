<?php
    class Countabled {
        private static $totalCount = 0;
        
        public function __construct() {
            self::$totalCount += 1;
        }
        
        public function __destruct() {
            self::$totalCount -= 1;
        }
        
        public static function getTotalCount() {
            return self::$totalCount;
        }
    }
    
    $count1 = new Countabled();
    $count2 = new Countabled();
    $count4 = new Countabled();
    $count5 = new Countabled($count4);
    echo  Countabled::getTotalCount() . PHP_EOL;

?>
