<?php

require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

$id = $_POST['id'];

// Consulta segura agregada por seguridad
$stmt = $conexion->prepare(
    "DELETE FROM citas WHERE id = ?"
);

$stmt->bind_param(
    "i",
    $id
);

if ($stmt->execute()) {
    echo "Cita eliminada de la base de datos.";
} else {
    echo "Error al eliminar cita: " . $stmt->error;
}

$stmt->close();
$conexion->close();

?>