<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

// Datos enviados desde C++
$id = $_POST['id'];
$paciente_id = $_POST['paciente_id'];
$fecha = $_POST['fecha'];
$hora = $_POST['hora'];
$doctor = $_POST['doctor'];
$motivo = $_POST['motivo'];


// ======================================
// CONSULTA SEGURA
// Agregado por seguridad utilizando
// prepare() para evitar SQL Injection
// ======================================

$stmt = $conexion->prepare(
    "INSERT INTO citas
    (id, paciente_id, fecha, hora, doctor, motivo)
    VALUES (?, ?, ?, ?, ?, ?)"
);

$stmt->bind_param(
    "iissss",
    $id,
    $paciente_id,
    $fecha,
    $hora,
    $doctor,
    $motivo
);

if ($stmt->execute()) {

    echo "Cita insertada correctamente";

} else {

    echo "Error: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>