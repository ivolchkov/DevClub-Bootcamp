<?php
    $total = intval(fgets(STDIN));
    
    for ( $i = 0, $start = 1; $i < $total; $i++, $start++ ) {
        for ( $j = 1; $j < $total; $j++, $start++ ) {
            echo $start . " ";
        }
    echo $start . PHP_EOL;
    }
?>
