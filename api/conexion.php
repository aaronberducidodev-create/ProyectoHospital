<?php
$conexion = new mysqli("localhost", "root", "", "hospital_db");

if ($conexion->connect_error) {
    die("Error de conexion: " . $conexion->connect_error);
}
?>