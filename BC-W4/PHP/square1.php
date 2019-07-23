<?php
    $total = intval(fgets(STDIN));
    
    for ( $i = 0; $i < $total; $i++ ) {
        for ( $j = 1; $j < $total; $j++ ) {
            echo $j . " ";
        }
        echo $total . PHP_EOL;
    }
    
?>
