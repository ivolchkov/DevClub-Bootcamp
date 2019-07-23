<?php
    $dividend = intval(fgets(STDIN));
    $divider = intval(fgets(STDIN));
    
    if ( $divider < 0 ) {
        $divider *= -1;
    }
    $multiple = $dividend - $dividend % $divider;
    
    if ( $multiple < $dividend ) {
        $multiple += $divider;
    }
    
    echo $multiple . PHP_EOL;
?>
