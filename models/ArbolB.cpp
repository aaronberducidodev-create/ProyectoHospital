#include "ArbolB.h"

// =============================================
// CONSTRUCTOR DEL NODO B
// =============================================
// Inicializa el nodo sin claves almacenadas.
// =============================================
NodoB::NodoB() {
    cantidad = 0;
}

// =============================================
// INSERCIÓN EN EL NODO B
// =============================================
// Agrega una nueva clave al nodo siempre que
// exista espacio disponible.
//
// Nota:
// Esta implementación es una versión simplificada
// de un Árbol B para fines académicos.
// =============================================
void NodoB::insertar(int valor) {
    if (cantidad < 10) {
        claves[cantidad] = valor;
        cantidad++;
    }
}

// =============================================
// MOSTRAR CONTENIDO DEL NODO
// =============================================
// Muestra todas las claves almacenadas
// actualmente en el nodo.
// =============================================
void NodoB::mostrar() {
    cout << "\n===== ARBOL B =====" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << claves[i] << " ";
    }

    cout << endl;
}

// =============================================
// LIMPIAR NODO
// =============================================
// Elimina lógicamente todas las claves
// reiniciando el contador.
// =============================================
void NodoB::limpiar() {
    cantidad = 0;
}

// =============================================
// CONSTRUCTOR DEL ÁRBOL B
// =============================================
// Inicializa la estructura principal.
// =============================================
ArbolB::ArbolB() {
}

// =============================================
// INSERCIÓN EN EL ÁRBOL B
// =============================================
// Delega la inserción al nodo raíz.
// =============================================
void ArbolB::insertar(int valor) {
    raiz.insertar(valor);
}

// =============================================
// MOSTRAR ÁRBOL B
// =============================================
// Muestra el contenido almacenado
// en el nodo raíz.
// =============================================
void ArbolB::mostrar() {
    raiz.mostrar();
}

// =============================================
// LIMPIAR ÁRBOL B
// =============================================
// Reinicia la información almacenada.
// =============================================
void ArbolB::limpiar() {
    raiz.limpiar();
}