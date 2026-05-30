#include "ArbolAVLEdades.h"
#include <iostream>
#include <new>

using namespace std;

// =============================================
// CONSTRUCTOR DEL NODO AVL
// =============================================
NodoAVL::NodoAVL(Paciente* paciente) {
    this->paciente = paciente;
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->altura = 1;
}

// =============================================
// CONSTRUCTOR DEL ÁRBOL AVL
// =============================================
ArbolAVLEdades::ArbolAVLEdades() {
    raiz = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
ArbolAVLEdades::~ArbolAVLEdades() {
    liberarMemoria(raiz);
    raiz = nullptr;
}

// =============================================
// LIBERACIÓN DE MEMORIA
// =============================================
void ArbolAVLEdades::liberarMemoria(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);

    delete nodo;
}

// =============================================
// ALTURA
// =============================================
int ArbolAVLEdades::altura(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

// =============================================
// MÁXIMO
// =============================================
int ArbolAVLEdades::maximo(int a, int b) {
    return (a > b) ? a : b;
}

// =============================================
// BALANCE
// =============================================
int ArbolAVLEdades::obtenerBalance(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;

    return altura(nodo->izquierda) - altura(nodo->derecha);
}

// =============================================
// ROTACIÓN DERECHA
// =============================================
NodoAVL* ArbolAVLEdades::rotacionDerecha(NodoAVL* y) {

    if (y == nullptr || y->izquierda == nullptr) {
        return y;
    }

    NodoAVL* x = y->izquierda;
    NodoAVL* temp = x->derecha;

    x->derecha = y;
    y->izquierda = temp;

    y->altura = maximo(
        altura(y->izquierda),
        altura(y->derecha)
    ) + 1;

    x->altura = maximo(
        altura(x->izquierda),
        altura(x->derecha)
    ) + 1;

    return x;
}

// =============================================
// ROTACIÓN IZQUIERDA
// =============================================
NodoAVL* ArbolAVLEdades::rotacionIzquierda(NodoAVL* x) {

    if (x == nullptr || x->derecha == nullptr) {
        return x;
    }

    NodoAVL* y = x->derecha;
    NodoAVL* temp = y->izquierda;

    y->izquierda = x;
    x->derecha = temp;

    x->altura = maximo(
        altura(x->izquierda),
        altura(x->derecha)
    ) + 1;

    y->altura = maximo(
        altura(y->izquierda),
        altura(y->derecha)
    ) + 1;

    return y;
}

// =============================================
// INSERTAR
// =============================================
void ArbolAVLEdades::insertar(Paciente* paciente) {

    if (paciente == nullptr) {
        cout << "Error: paciente nulo, no se puede insertar en AVL." << endl;
        return;
    }

    raiz = insertarRecursivo(raiz, paciente);
}

// =============================================
// INSERTAR RECURSIVO
// =============================================
NodoAVL* ArbolAVLEdades::insertarRecursivo(NodoAVL* nodo, Paciente* paciente) {

    if (paciente == nullptr) {
        return nodo;
    }

    if (nodo == nullptr) {

        try {
            return new NodoAVL(paciente);
        }
        catch (bad_alloc&) {
            cout << "Error: no se pudo reservar memoria para AVL." << endl;
            return nullptr;
        }
    }

    if (paciente->getEdad() < nodo->paciente->getEdad()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
    }
    else if (paciente->getEdad() > nodo->paciente->getEdad()) {
        nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
    }
    else {

        if (paciente->getId() < nodo->paciente->getId()) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
        } else {
            nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
        }
    }

    nodo->altura =
        1 + maximo(
            altura(nodo->izquierda),
            altura(nodo->derecha)
        );

    int balance = obtenerBalance(nodo);

    // LL
    if (balance > 1 &&
        paciente->getEdad() < nodo->izquierda->paciente->getEdad()) {

        return rotacionDerecha(nodo);
    }

    // RR
    if (balance < -1 &&
        paciente->getEdad() > nodo->derecha->paciente->getEdad()) {

        return rotacionIzquierda(nodo);
    }

    // LR
    if (balance > 1 &&
        paciente->getEdad() > nodo->izquierda->paciente->getEdad()) {

        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // RL
    if (balance < -1 &&
        paciente->getEdad() < nodo->derecha->paciente->getEdad()) {

        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

// =============================================
// MOSTRAR INORDEN
// =============================================
void ArbolAVLEdades::mostrarInOrden() {

    if (raiz == nullptr) {
        cout << "El arbol AVL esta vacio." << endl;
        return;
    }

    inOrdenRecursivo(raiz);
}

// =============================================
// INORDEN RECURSIVO
// =============================================
void ArbolAVLEdades::inOrdenRecursivo(NodoAVL* nodo) {

    if (nodo == nullptr) {
        return;
    }

    inOrdenRecursivo(nodo->izquierda);

    if (nodo->paciente != nullptr) {
        nodo->paciente->mostrar();
        cout << "Altura nodo: " << nodo->altura << endl;
        cout << "---------------------" << endl;
    }

    inOrdenRecursivo(nodo->derecha);
}