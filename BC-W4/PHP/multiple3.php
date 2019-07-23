<?php
    $number = intval(fgets(STDIN));
    
    $number -= $number % 3;
    
    echo implode(" ",range(0, $number, 3)) . PHP_EOL;
    
?>
