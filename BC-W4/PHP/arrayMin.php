<?php
    function arrayMin($array, $size ) {
        $arrMin = $array[0];
        
        for ( $i = 1; $i < $size; $i++ ) {
            if ( $array[$i] < $arrMin ) {
                $arrMin = $array[$i];
            }
        }
        return $arrMin;
    }
?>
