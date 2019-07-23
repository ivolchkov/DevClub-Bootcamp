<?php 
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    
    if ( $a > $b ) {
        echo $a . PHP_EOL;
    } else {
        echo $b . PHP_EOL;
    }
?>