<?php
    $total = intval(fgets(STDIN));
    
    $num = $total * $total - ($total - 1);
    $start = $num;
    
    for ( $i = 0; $i < $total; $i++ ) {
        for ( $j = 1; $j < $total; $j++, $num++ ) {
            echo $num . " ";
        }
        echo $num . PHP_EOL;
        $start -= $total;
        $num = $start;
    }
?>