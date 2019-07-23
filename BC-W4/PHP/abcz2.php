<?php
    $num = intval(fgets(STDIN));
    $check = true;
    
    if ( $num % 2 == 0 ) {
        $check = false;
        echo "alpha" . PHP_EOL;
    }
    
    if ( $num % 3 == 0 ) {
        $check = false;
        echo "bravo" . PHP_EOL;
    }
    
    if ( $num % 5 == 0 ) {
        $check = false;
        echo "charlie" . PHP_EOL;
    }
    
    if ( $check ) {
        echo "zulu" . PHP_EOL;
    }
    
?>