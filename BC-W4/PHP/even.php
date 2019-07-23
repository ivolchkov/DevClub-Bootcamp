<?php
    $number = intval(fgets(STDIN));
    
    $number -= $number % 2;
    
    echo implode(" ", range(0, $number, 2)) . PHP_EOL;
    
?>
