<?php
    function arrayPrint($out, $array, $size) {
        fwrite($out, implode(" ",$array));
    }
?>
