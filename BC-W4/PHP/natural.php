<?php
    $number = intval(fgets(STDIN));
    
    echo implode(" ", range(1, $number)) . PHP_EOL;
    
?>
