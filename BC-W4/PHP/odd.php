<?php
    $number = intval(fgets(STDIN));
    
    if ( $number % 2 == 0 ) {
        $number -= 1;
    }
    
    echo implode(" ", range(1, $number, 2)) . PHP_EOL;
    
?>
