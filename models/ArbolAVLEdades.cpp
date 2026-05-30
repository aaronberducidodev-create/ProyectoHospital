#include "ArbolAVLEdades.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DEL NODO AVL
// =============================================
// Cada nodo almacena un paciente,
// enlaces a sus hijos y su altura.
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
// Inicializa el árbol vacío.
// =============================================
ArbolAVLEdades::ArbolAVLEdades() {
    raiz = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera toda la memoria utilizada
// por los nodos del árbol.
// =============================================
ArbolAVLEdades::~ArbolAVLEdades() {
    liberarMemoria(raiz);
}

// =============================================
// LIBERACIÓN RECURSIVA DE MEMORIA
// =============================================
// Recorre el árbol en postorden y elimina
// cada nodo almacenado.
// =============================================
void ArbolAVLEdades::liberarMemoria(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);
    delete nodo;
}

// =============================================
// OBTENER ALTURA DEL NODO
// =============================================
// Devuelve la altura de un nodo AVL.
// =============================================
int ArbolAVLEdades::altura(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

// Función auxiliar para obtener el máximo
// entre dos valores.
int ArbolAVLEdades::maximo(int a, int b) {
    return (a > b) ? a : b;
}

// =============================================
// FACTOR DE BALANCE
// =============================================
// Calcula la diferencia entre la altura
// del subárbol izquierdo y derecho.
//
// Se utiliza para determinar si el árbol
// necesita rotaciones.
// =============================================
int ArbolAVLEdades::obtenerBalance(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

// =============================================
// ROTACIÓN SIMPLE A LA DERECHA
// =============================================
// Se utiliza cuando el árbol queda
// desbalanceado hacia la izquierda.
// =============================================
NodoAVL* ArbolAVLEdades::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* temp = x->derecha;

    x->derecha = y;
    y->izquierda = temp;

    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

// =============================================
// ROTACIÓN SIMPLE A LA IZQUIERDA
// =============================================
// Se utiliza cuando el árbol queda
// desbalanceado hacia la derecha.
// =============================================
NodoAVL* ArbolAVLEdades::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecha;
    NodoAVL* temp = y->izquierda;

    y->izquierda = x;
    x->derecha = temp;

    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

// =============================================
// INSERCIÓN EN EL ÁRBOL AVL
// =============================================
// Inserta pacientes ordenados por edad,
// manteniendo el árbol balanceado.
// =============================================
void ArbolAVLEdades::insertar(Paciente* paciente) {
    raiz = insertarRecursivo(raiz, paciente);
}

// =============================================
// INSERCIÓN RECURSIVA AVL
// =============================================
// Inserta el paciente y aplica rotaciones
// cuando el árbol pierde el balance.
// =============================================
NodoAVL* ArbolAVLEdades::insertarRecursivo(NodoAVL* nodo, Paciente* paciente) {
    if (nodo == nullptr) {
        return new NodoAVL(paciente);
    }

    if (paciente->getEdad() < nodo->paciente->getEdad()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
    } else if (paciente->getEdad() > nodo->paciente->getEdad()) {
        nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
    } else {

        // Si tienen la misma edad,
        // se utiliza el ID para ordenar.
        if (paciente->getId() < nodo->paciente->getId()) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
        } else {
            nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
        }
    }

    nodo->altura = 1 + maximo(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    // Caso izquierda-izquierda (LL)
    if (balance > 1 && paciente->getEdad() < nodo->izquierda->paciente->getEdad()) {
        return rotacionDerecha(nodo);
    }

    // Caso derecha-derecha (RR)
    if (balance < -1 && paciente->getEdad() > nodo->derecha->paciente->getEdad()) {
        return rotacionIzquierda(nodo);
    }

    // Caso izquierda-derecha (LR)
    if (balance > 1 && paciente->getEdad() > nodo->izquierda->paciente->getEdad()) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // Caso derecha-izquierda (RL)
    if (balance < -1 && paciente->getEdad() < nodo->derecha->paciente->getEdad()) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

// =============================================
// RECORRIDO INORDEN
// =============================================
// Muestra los pacientes ordenados
// por edad de menor a mayor.
// =============================================
void ArbolAVLEdades::mostrarInOrden() {
    inOrdenRecursivo(raiz);
}

// =============================================
// RECORRIDO INORDEN RECURSIVO
// =============================================
// Visita:
// izquierda -> raíz -> derecha
// =============================================
void ArbolAVLEdades::inOrdenRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    inOrdenRecursivo(nodo->izquierda);

    nodo->paciente->mostrar();
    cout << "Altura nodo: " << nodo->altura << endl;
    cout << "---------------------" << endl;

    inOrdenRecursivo(nodo->derecha);
}