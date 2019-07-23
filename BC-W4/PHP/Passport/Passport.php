<?php
    include_once 'Date.php';
    
    class Passport {
        private $name;
        private $surname;
        private $date;
        private $lastId;
        private $serNum = array();
        
        public static $counterFirst = 1;
        public static $counterSecond = 1;
        public static $series = array();
        public static $id = 1;
        public static $serialNu = array(0 => ' ',
                                        1 => ' ');
        
        public function __construct($date, $name = "Ivan" , $surname = "Ivanov" ) {
            $this->date = $date;
            $this->name = $name;
            $this->surname = $surname;
            
            self::setStartId();
            
            $this->serNum = self::$serialNu;
            $this->lastId = self::$id;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __toString() {
            return sprintf("%s %s : " . $this->date . " passport : " . implode('', $this->serNum) . " %d", $this->name,
                                                                                                           $this->surname,
                                                                                                           $this->lastId);
        }
        
        public static function setStartId() {
            if ( self::$id >= 100000 && self::$id <= 999999 ) {
                self::$id += 1;
            }
            if ( self::$id == 1 || self::$id > 999999 ) {
                self::$id = 100000;
                self::setSerialNu();
            }
        }
        
        public static function setStartSeries() {
            self::$series = range('A', 'Z');
        }
        
        public static function setSerialNu() {
            if ( self::$serialNu[1] == ' ' ) {
                self::$serialNu[0] = 'A';
                self::$serialNu[1] = 'A';
                self::setStartSeries();
            } else {
                self::$serialNu[1] = self::$series[self::$counterFirst];
                self::$counterFirst += 1;
            }
            
            
            if ( self::$counterFirst == 26 ) {
                self::$counterFirst = 0;
                self::$counterSecond += 1;
                self::$serialNu[1] = self::$series[self::$counterFirst];
                self::$serialNu[0] = self::$series[self::$counterSecond];
            }
            if ( self::$counterSecond == 26 ) {
                throw new Exception("Invalid series!");
            }
            
        }
        
        public static function validateNewSeries($newSeries) {
            for ( $i = 0; $i < 26; $i++ ) {
                if ( self::$series[$i] == $newSeries[1] ) {
                    self::$counterFirst = $i;
                }
                if ( self::$series[$i] == $newSeries[0] ) {
                    self::$counterSecond = $i;
                }
            }
        }
        
        public static function setNewSeries($newSeries, int $newId) {
            if ( count($newSeries) > 2 ) {
                throw new Exception("Invalid series size");
            }
            
            self::$serialNu = $newSeries;
            self::validateNewSeries(self::$serialNu);
            self::setNewId($newId);
        }
        
        public static function setNewId($newId) {
            if ( !is_numeric($newId) ) {
                throw new Exception("Invalid type");
            }
            if ( $newId > 999999 || $newId < 100000 ) {
                throw new Exception("Invalid Id");
            } else {
                self::$id = $newId-1;
            }
        }
    }
    
    $date = new Date(18, 12, 1997);
    $pass = new Passport($date, "Igor", "Volchkov");
    
    $date2 = new Date(13, 11, 1995);
    $pass2 = new Passport($date2, "Anya", "Volchkova");
    
    echo $pass . PHP_EOL;
    echo $pass2 . PHP_EOL;
    $arr  = array(0 => 'A',
                   1 => 'Z' );
    Passport::setNewSeries($arr , 999999);
    // Passport::setNewId(999999);
    $date3 = new Date(19, 9, 1990);
    $pass3 = new Passport($date3, "Valik", "Lopuha");
    
    echo $pass3 . PHP_EOL;
    
    $date4 = new Date(19, 9, 1990);
    $pass4 = new Passport($date4, "Yura", "Mikulin");
    
    echo $pass4 . PHP_EOL;
    
    echo implode('', Passport::$serialNu) . PHP_EOL;
    

?>
