<?php
    $number = intval(fgets(STDIN));
    $multiple = intval(fgets(STDIN));
    
    $number -= $number % $multiple;
    
    echo implode(" ", range(0, $number, $multiple)) . PHP_EOL;
    
?>
