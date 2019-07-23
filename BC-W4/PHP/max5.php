<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $d = intval(fgets(STDIN));
    $e = intval(fgets(STDIN));
    $max = $a;
    
    if ( $b > $max ) {
        $max = $b;
    }
    
    if ( $c > $max ) {
        $max = $c;
    }
    
    if ( $d > $max ) {
        $max = $d;
    }
    
    if ( $e > $max ) {
        $max = $e;
    }
    
    echo $max . PHP_EOL;
?>
