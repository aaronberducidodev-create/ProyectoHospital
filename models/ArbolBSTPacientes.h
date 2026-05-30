#ifndef ARBOLBSTPACIENTES_H
#define ARBOLBSTPACIENTES_H

#include "Paciente.h"

// =============================================
// NODO BST
// =============================================
// Representa un nodo del Árbol Binario
// de Búsqueda.
//
// Cada nodo guarda:
// - Un paciente.
// - Un hijo izquierdo.
// - Un hijo derecho.
// =============================================
class NodoBST {
public:
    Paciente* paciente;
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(Paciente* paciente);
};

// =============================================
// ÁRBOL BST DE PACIENTES
// =============================================
// Organiza pacientes utilizando su ID.
//
// Si el ID es menor, se inserta a la izquierda.
// Si el ID es mayor, se inserta a la derecha.
// =============================================
class ArbolBSTPacientes {
private:
    // Nodo principal del árbol
    NodoBST* raiz;

    // Inserta pacientes de forma recursiva
    NodoBST* insertarRecursivo(NodoBST* nodo, Paciente* paciente);

    // Busca pacientes por ID de forma recursiva
    Paciente* buscarRecursivo(NodoBST* nodo, int id);

    // Recorridos del árbol
    void inOrdenRecursivo(NodoBST* nodo);
    void preOrdenRecursivo(NodoBST* nodo);
    void postOrdenRecursivo(NodoBST* nodo);

    // Libera la memoria usada por los nodos
    void liberarMemoria(NodoBST* nodo);

public:
    // Constructor y destructor
    ArbolBSTPacientes();
    ~ArbolBSTPacientes();

    // Inserta y busca pacientes
    void insertar(Paciente* paciente);
    Paciente* buscar(int id);

    // Muestra los recorridos del árbol
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
};

#endif