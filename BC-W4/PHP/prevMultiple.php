<?php
    $divident = intval(fgets(STDIN));
    $divider = intval(fgets(STDIN));
    
    if ( $divider < 0 ) {
        $divider *= -1;
    }
    $multiple = $divident - $divident % $divider;
    
    if ( $multiple > $divident ) {
        $multiple -= $divider;
    }
    
    echo $multiple . PHP_EOL;
    
?>
