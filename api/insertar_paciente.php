<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

// Datos enviados desde C++
$id = $_POST['id'];
$nombre = $_POST['nombre'];
$edad = $_POST['edad'];
$dpi = $_POST['dpi'];


// ======================================
// CONSULTA SEGURA
// Agregado por seguridad utilizando
// prepare() para evitar SQL Injection
// ======================================

$stmt = $conexion->prepare(
    "INSERT INTO pacientes (id, nombre, edad, dpi)
     VALUES (?, ?, ?, ?)"
);

$stmt->bind_param(
    "isis",
    $id,
    $nombre,
    $edad,
    $dpi
);

if ($stmt->execute()) {

    echo "Paciente insertado correctamente";

} else {

    echo "Error: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>