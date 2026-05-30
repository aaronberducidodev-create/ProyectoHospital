#include "ArbolBSTPacientes.h"
#include <iostream>
#include <new>

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
// Nota: no elimina el objeto Paciente porque
// ese pertenece a ListaPacientes.
// =============================================
ArbolBSTPacientes::~ArbolBSTPacientes() {
    liberarMemoria(raiz);
    raiz = nullptr;
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

// =============================================
// INSERTAR PACIENTE EN BST
// =============================================
// Inserta un paciente en el árbol usando su ID.
// Valida que el paciente no sea nullptr.
// =============================================
void ArbolBSTPacientes::insertar(Paciente* paciente) {
    if (paciente == nullptr) {
        cout << "Error: paciente nulo, no se puede insertar en BST." << endl;
        return;
    }

    raiz = insertarRecursivo(raiz, paciente);
}

// Inserción recursiva.
// Si el ID es menor va a la izquierda.
// Si el ID es mayor va a la derecha.
NodoBST* ArbolBSTPacientes::insertarRecursivo(NodoBST* nodo, Paciente* paciente) {
    if (paciente == nullptr) {
        return nodo;
    }

    if (nodo == nullptr) {
        try {
            return new NodoBST(paciente);
        }
        catch (bad_alloc&) {
            cout << "Error: no se pudo reservar memoria para nodo BST." << endl;
            return nullptr;
        }
    }

    if (nodo->paciente == nullptr) {
        return nodo;
    }

    if (paciente->getId() < nodo->paciente->getId()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
    }
    else if (paciente->getId() > nodo->paciente->getId()) {
        nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
    }
    else {
        cout << "Ya existe un paciente con ese ID en el BST." << endl;
    }

    return nodo;
}

// =============================================
// BUSCAR PACIENTE POR ID
// =============================================
Paciente* ArbolBSTPacientes::buscar(int id) {
    return buscarRecursivo(raiz, id);
}

// Búsqueda recursiva por ID.
Paciente* ArbolBSTPacientes::buscarRecursivo(NodoBST* nodo, int id) {
    if (nodo == nullptr || nodo->paciente == nullptr) {
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

// =============================================
// MOSTRAR INORDEN
// =============================================
// Muestra los pacientes en orden ascendente por ID.
// =============================================
void ArbolBSTPacientes::mostrarInOrden() {
    if (raiz == nullptr) {
        cout << "El arbol BST esta vacio." << endl;
        return;
    }

    inOrdenRecursivo(raiz);
}

// Recorrido InOrden: izquierda -> raíz -> derecha.
void ArbolBSTPacientes::inOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    inOrdenRecursivo(nodo->izquierda);

    if (nodo->paciente != nullptr) {
        nodo->paciente->mostrar();
        cout << "---------------------" << endl;
    }

    inOrdenRecursivo(nodo->derecha);
}

// =============================================
// MOSTRAR PREORDEN
// =============================================
// Muestra primero la raíz y luego sus hijos.
// =============================================
void ArbolBSTPacientes::mostrarPreOrden() {
    if (raiz == nullptr) {
        cout << "El arbol BST esta vacio." << endl;
        return;
    }

    preOrdenRecursivo(raiz);
}

// Recorrido PreOrden: raíz -> izquierda -> derecha.
void ArbolBSTPacientes::preOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    if (nodo->paciente != nullptr) {
        nodo->paciente->mostrar();
        cout << "---------------------" << endl;
    }

    preOrdenRecursivo(nodo->izquierda);
    preOrdenRecursivo(nodo->derecha);
}

// =============================================
// MOSTRAR POSTORDEN
// =============================================
// Muestra primero los hijos y al final la raíz.
// =============================================
void ArbolBSTPacientes::mostrarPostOrden() {
    if (raiz == nullptr) {
        cout << "El arbol BST esta vacio." << endl;
        return;
    }

    postOrdenRecursivo(raiz);
}

// Recorrido PostOrden: izquierda -> derecha -> raíz.
void ArbolBSTPacientes::postOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    postOrdenRecursivo(nodo->izquierda);
    postOrdenRecursivo(nodo->derecha);

    if (nodo->paciente != nullptr) {
        nodo->paciente->mostrar();
        cout << "---------------------" << endl;
    }
}