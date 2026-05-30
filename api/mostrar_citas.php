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

$sql = "SELECT citas.id, pacientes.nombre, citas.fecha, citas.doctor, citas.motivo
        FROM citas
        INNER JOIN pacientes ON citas.paciente_id = pacientes.id";

$result = $conexion->query($sql);

while ($row = $result->fetch_assoc()) {

    // ✅ NUEVO:
    // Se cambio <br> por \n
    // para que PowerShell muestre limpio

    echo "ID Cita: " . $row['id'] . " - ";
    echo "Paciente: " . $row['nombre'] . " - ";
    echo "Fecha: " . $row['fecha'] . " - ";
    echo "Doctor: " . $row['doctor'] . " - ";
    echo "Motivo: " . $row['motivo'] . "\n";
}

$conexion->close();
?>