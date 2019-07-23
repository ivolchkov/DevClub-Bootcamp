<?php
    $a = intval(fgets(STDIN));
    $b = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $max = $a;

    if ( $b > $max ) {
        $max = $b;
    }
    if ( $c > $max ) {
        $max = $c;
    }

    echo $max . PHP_EOL;

?>