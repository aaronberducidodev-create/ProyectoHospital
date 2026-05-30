#ifndef ARBOLAVLEDADES_H
#define ARBOLAVLEDADES_H

#include "Paciente.h"

// =============================================
// NODO AVL
// =============================================
// Representa un nodo dentro del Árbol AVL.
//
// Cada nodo almacena:
// - Un paciente.
// - Enlace al hijo izquierdo.
// - Enlace al hijo derecho.
// - Altura del nodo.
//
// La altura es utilizada para calcular
// el balance del árbol.
// =============================================
class NodoAVL {
public:
    Paciente* paciente;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    // Constructor del nodo AVL
    NodoAVL(Paciente* paciente);
};

// =============================================
// ÁRBOL AVL DE PACIENTES POR EDAD
// =============================================
// Organiza pacientes según su edad
// manteniendo el árbol balanceado.
//
// Ventajas:
// - Búsquedas rápidas.
// - Inserciones eficientes.
// - Mantiene altura controlada.
// =============================================
class ArbolAVLEdades {
private:

    // Nodo raíz del árbol AVL
    NodoAVL* raiz;

    // =============================================
    // FUNCIONES AUXILIARES AVL
    // =============================================

    // Obtiene la altura de un nodo
    int altura(NodoAVL* nodo);

    // Devuelve el mayor de dos valores
    int maximo(int a, int b);

    // Calcula el factor de balance
    int obtenerBalance(NodoAVL* nodo);

    // =============================================
    // ROTACIONES AVL
    // =============================================
    // Se utilizan para corregir
    // desbalances del árbol.
    // =============================================
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);

    // Inserción recursiva con balanceo
    NodoAVL* insertarRecursivo(NodoAVL* nodo, Paciente* paciente);

    // Recorrido InOrden recursivo
    void inOrdenRecursivo(NodoAVL* nodo);

    // Libera la memoria utilizada
    // por todos los nodos del árbol
    void liberarMemoria(NodoAVL* nodo);

public:

    // Constructor
    ArbolAVLEdades();

    // Destructor
    ~ArbolAVLEdades();

    // =============================================
    // OPERACIONES PRINCIPALES
    // =============================================

    // Inserta un paciente ordenado por edad
    void insertar(Paciente* paciente);

    // Muestra el árbol en recorrido InOrden
    void mostrarInOrden();
};

#endif