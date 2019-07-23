<?php
    function arrayMax($array, $size ) {
        $arrMax = $array[0];
        
        for ( $i = 1; $i < $size; $i++ ) {
            if ( $array[$i] > $arrMax ) {
                $arrMax = $array[$i];
            }
        }
        return $arrMax;
    }
?>
