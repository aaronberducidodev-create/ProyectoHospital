#ifndef HASHPACIENTES_H
#define HASHPACIENTES_H

#include "Paciente.h"

// =============================================
// NODO HASH
// =============================================
// Representa un nodo dentro de la tabla hash.
//
// Cada nodo almacena:
// - DPI del paciente (clave).
// - Puntero al paciente.
// - Enlace al siguiente nodo.
//
// Se utiliza encadenamiento para manejar
// colisiones dentro de la tabla hash.
// =============================================
class NodoHash {
public:
    string dpi;
    Paciente* paciente;
    NodoHash* siguiente;

    NodoHash(string dpi, Paciente* paciente);
};

// =============================================
// TABLA HASH DE PACIENTES
// =============================================
// Permite realizar búsquedas rápidas de
// pacientes utilizando el DPI como clave.
//
// Estructura utilizada:
// - Tabla Hash
// - Encadenamiento para colisiones
//
// Ventaja:
// Las búsquedas son mucho más rápidas
// que recorrer una lista completa.
// =============================================
class HashPacientes {
private:

    // Tamaño fijo de la tabla hash
    static const int TAM = 10;

    // Arreglo de punteros que representa
    // la tabla hash.
    NodoHash* tabla[TAM];

    // =============================================
    // FUNCIÓN HASH
    // =============================================
    // Convierte un DPI en una posición
    // dentro de la tabla hash.
    // =============================================
    int funcionHash(string dpi);

public:

    // Constructor
    HashPacientes();

    // Destructor
    ~HashPacientes();

    // =============================================
    // OPERACIONES PRINCIPALES
    // =============================================

    // Inserta un paciente utilizando el DPI
    // como clave de búsqueda.
    void insertar(string dpi, Paciente* paciente);

    // Busca un paciente por DPI.
    Paciente* buscar(string dpi);

    // Muestra el contenido completo
    // de la tabla hash.
    void mostrarTabla();
};

#endif