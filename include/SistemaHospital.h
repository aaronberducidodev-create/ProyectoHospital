#ifndef SISTEMAHOSPITAL_H
#define SISTEMAHOSPITAL_H

// ===============================
// MODELOS Y ESTRUCTURAS
// Ahora estan dentro de /models
// ===============================
#include "../models/ArbolExpresiones.h"
#include "../models/ListaPacientes.h"
#include "../models/ColaEmergencias.h"
#include "../models/ListaCitas.h"
#include "../models/ArbolBSTPacientes.h"
#include "../models/ArbolAVLEdades.h"
#include "../models/HashPacientes.h"
#include "../models/ArbolB.h"

// ===============================
// ARCHIVOS QUE SIGUEN EN /include
// ===============================
#include "MemoriaHospital.h"
#include "GrafoHospital.h"

// ===============================
// CONEXION MYSQL
// Ahora esta dentro de /database
// ===============================
#include "../database/ConexionMySQL.h"

class SistemaHospital {
private:

    ListaPacientes listaPacientes;
    ColaEmergencias colaEmergencias;
    ListaCitas listaCitas;
    ArbolBSTPacientes arbolBST;
    ArbolAVLEdades arbolAVL;
    HashPacientes hashPacientes;
    MemoriaHospital memoria;
    GrafoHospital grafo;
    ConexionMySQL conexion;

    // Arbol de Expresiones para facturacion
    ArbolExpresiones arbolExpresiones;

    // Arbol B para indice de pacientes
    ArbolB arbolB;

    void menuPacientes();
    void menuEmergencias();
    void menuCitas();
    void menuEstructuras();
    void menuHospital();

public:
    SistemaHospital();
    void iniciar();
};

#endif