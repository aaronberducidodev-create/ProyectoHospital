<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

// ID enviado desde C++
$id = $_POST['id'];


// ======================================
// CONSULTA SEGURA
// Agregado por seguridad utilizando
// prepare() para evitar SQL Injection
// ======================================

$stmt = $conexion->prepare(
    "DELETE FROM pacientes WHERE id = ?"
);

$stmt->bind_param(
    "i",
    $id
);

if ($stmt->execute()) {

    echo "Paciente eliminado de la base de datos.";

} else {

    echo "Error al eliminar: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>