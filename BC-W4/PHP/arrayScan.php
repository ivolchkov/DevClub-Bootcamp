<?php
    function arrayScan($in, &$array, $limit) {
        $array = explode(" ", trim(fgets($in)));
        return $array;
    }
?>
