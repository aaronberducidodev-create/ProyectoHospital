<?php
require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

/*
YA NO SE NECESITA ESTA CONEXION
porque ahora la conexion viene desde conexion.php

$conn = new mysqli("localhost", "root", "", "hospital_db");

if ($conn->connect_error) {
    die("Error de conexion: " . $conn->connect_error);
}
*/

$result = $conexion->query("SELECT * FROM pacientes");

while ($row = $result->fetch_assoc()) {
    echo $row['id'] . "|" . $row['nombre'] . "|" . $row['edad'] . "|" . $row['dpi'] . "\n";
}

$conexion->close();
?>