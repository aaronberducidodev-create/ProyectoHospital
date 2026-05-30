#include "ArbolBSTPacientes.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DEL NODO BST
// =============================================
// Crea un nodo del árbol que almacena
// un puntero a un paciente.
// =============================================
NodoBST::NodoBST(Paciente* paciente) {
    this->paciente = paciente;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

// =============================================
// CONSTRUCTOR DEL ÁRBOL BST
// =============================================
// Inicializa el árbol vacío.
// =============================================
ArbolBSTPacientes::ArbolBSTPacientes() {
    raiz = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera la memoria de todos los nodos.
// =============================================
ArbolBSTPacientes::~ArbolBSTPacientes() {
    liberarMemoria(raiz);
}

// Libera memoria recorriendo el árbol en postorden.
void ArbolBSTPacientes::liberarMemoria(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);

    delete nodo;
}

// Inserta un paciente en el árbol usando su ID.
void ArbolBSTPacientes::insertar(Paciente* paciente) {
    raiz = insertarRecursivo(raiz, paciente);
}

// Inserción recursiva.
// Si el ID es menor va a la izquierda.
// Si el ID es mayor va a la derecha.
NodoBST* ArbolBSTPacientes::insertarRecursivo(NodoBST* nodo, Paciente* paciente) {
    if (nodo == nullptr) {
        return new NodoBST(paciente);
    }

    if (paciente->getId() < nodo->paciente->getId()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
    } else if (paciente->getId() > nodo->paciente->getId()) {
        nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
    } else {
        cout << "Ya existe un paciente con ese ID." << endl;
    }

    return nodo;
}

// Busca un paciente por ID dentro del BST.
Paciente* ArbolBSTPacientes::buscar(int id) {
    return buscarRecursivo(raiz, id);
}

// Búsqueda recursiva por ID.
Paciente* ArbolBSTPacientes::buscarRecursivo(NodoBST* nodo, int id) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (id == nodo->paciente->getId()) {
        return nodo->paciente;
    }

    if (id < nodo->paciente->getId()) {
        return buscarRecursivo(nodo->izquierda, id);
    } else {
        return buscarRecursivo(nodo->derecha, id);
    }
}

// Muestra los pacientes en orden ascendente por ID.
void ArbolBSTPacientes::mostrarInOrden() {
    inOrdenRecursivo(raiz);
}

// Recorrido InOrden: izquierda -> raíz -> derecha.
void ArbolBSTPacientes::inOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    inOrdenRecursivo(nodo->izquierda);
    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
    inOrdenRecursivo(nodo->derecha);
}

// Muestra primero la raíz y luego sus hijos.
void ArbolBSTPacientes::mostrarPreOrden() {
    preOrdenRecursivo(raiz);
}

// Recorrido PreOrden: raíz -> izquierda -> derecha.
void ArbolBSTPacientes::preOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
    preOrdenRecursivo(nodo->izquierda);
    preOrdenRecursivo(nodo->derecha);
}

// Muestra primero los hijos y al final la raíz.
void ArbolBSTPacientes::mostrarPostOrden() {
    postOrdenRecursivo(raiz);
}

// Recorrido PostOrden: izquierda -> derecha -> raíz.
void ArbolBSTPacientes::postOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    postOrdenRecursivo(nodo->izquierda);
    postOrdenRecursivo(nodo->derecha);
    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
}