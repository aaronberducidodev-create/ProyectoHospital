<?php
require_once __DIR__ . '/conexion.php';

/** @var mysqli $conexion */

$result = $conexion->query("SELECT id FROM pacientes ORDER BY id ASC");

while ($row = $result->fetch_assoc()) {
    echo $row['id'] . "\n";
}

$conexion->close();
?>