<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $d = intval(fgets(STDIN));
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
    
    echo $max . PHP_EOL;
    
?>
