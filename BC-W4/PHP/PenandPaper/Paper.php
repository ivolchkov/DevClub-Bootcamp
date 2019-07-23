<?php
    include_once 'Pen.php';
    
    class Paper {
        private $symbols;
        private $maxSymbols;
        private $content;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        public function __construct($maxSymbols = 4096) {
            $this->maxSymbols = $this->validate($maxSymbols);
            $this->symbols = 0;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function addContent(string $message) {
            if ( $this->symbols == $this->maxSymbols ) {
                throw new Exception("Out of space");
            }
            $this->symbols += strlen($message);
            
            if ( $this->symbols > $this->maxSymbols ) {
                $temp = strlen($message) - ($this->symbols - $this->maxSymbols);
                
                $this->symbols = $this->maxSymbols;
                $this->content .= substr($message, 0, $temp);
            } else {
                $this->content .= $message;
            }
        }
        
        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
    
    $pen = new Pen();
    $paper = new Paper();
    
    echo "In the beggining " . $paper->symbols . " " . $paper->maxSymbols . PHP_EOL;
    echo "In the beggining " . $pen->inkAmount . " " . $pen->inkCapacity . PHP_EOL;
    
    $pen->write($paper, "Hello World");
    $paper->show();
    
    echo  $paper->symbols . " " . $paper->maxSymbols . PHP_EOL;
    echo  $pen->inkAmount . " " . $pen->inkCapacity . PHP_EOL;
    
    $pen->refill();
    
    echo "After refilling pen ink " . $pen->inkAmount . " " . $pen->inkCapacity . PHP_EOL;
?>