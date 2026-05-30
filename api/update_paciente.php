<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

// Datos enviados desde C++
$id = $_POST["id"];
$nombre = $_POST["nombre"];
$edad = $_POST["edad"];
$dpi = $_POST["dpi"];


// ======================================
// CONSULTA SEGURA
// Agregado por seguridad utilizando
// prepare() para evitar SQL Injection
// ======================================

$stmt = $conexion->prepare(
    "UPDATE pacientes
     SET nombre = ?, edad = ?, dpi = ?
     WHERE id = ?"
);

$stmt->bind_param(
    "sisi",
    $nombre,
    $edad,
    $dpi,
    $id
);

if ($stmt->execute()) {

    echo "Paciente actualizado correctamente";

} else {

    echo "Error al actualizar paciente: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>