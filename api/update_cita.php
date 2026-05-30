<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

$id = $_POST['id'];
$paciente_id = $_POST['paciente_id'];
$fecha = $_POST['fecha'];
$hora = $_POST['hora'];
$doctor = $_POST['doctor'];
$motivo = $_POST['motivo'];

// Consulta segura agregada por seguridad
$stmt = $conexion->prepare(
    "UPDATE citas
     SET paciente_id = ?, fecha = ?, hora = ?, doctor = ?, motivo = ?
     WHERE id = ?"
);

$stmt->bind_param(
    "issssi",
    $paciente_id,
    $fecha,
    $hora,
    $doctor,
    $motivo,
    $id
);

if ($stmt->execute()) {
    echo "Cita actualizada correctamente";
} else {
    echo "Error al actualizar cita: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>