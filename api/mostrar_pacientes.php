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

$sql = "SELECT * FROM pacientes";
$result = $conexion->query($sql);

while ($row = $result->fetch_assoc()) {

    // ✅ NUEVO:
    // Se cambio <br> por \n
    // para que la consola PowerShell se vea limpia

    echo "ID: " . $row['id'] . " - ";
    echo "Nombre: " . $row['nombre'] . " - ";
    echo "Edad: " . $row['edad'] . " - ";
    echo "DPI: " . $row['dpi'] . "\n";
}

$conexion->close();
?>