<?php
    function gcd($a, $b) {
        if ( $b == 0 ) {
            return $a;
        }
        return gcd($b, $a % $b);
    }
    
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    
    fscanf($in, "%d %d", $a, $b);
    
    fclose($in);
    
    $lcm = ( $a / gcd($a, $b)) * $b;
    
    fwrite($out, $lcm);
    fclose($out);
    
?>