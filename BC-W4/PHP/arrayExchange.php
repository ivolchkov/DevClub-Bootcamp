<?php
    function arrayExchange(&$array, $len) {
        for ( $even = 0, $odd = 1; $odd < $len; $even += 2, $odd += 2 ) {
            $temp = $array[$even];
            
            $array[$even] = $array[$odd];
            $array[$odd] = $temp;
        }
    }
?>
