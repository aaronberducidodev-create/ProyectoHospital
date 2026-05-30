#include "ArbolAVLEdades.h"
#include <iostream>

using namespace std;

NodoAVL::NodoAVL(Paciente* paciente) {
    this->paciente = paciente;
    this->izquierda = nullptr;
    this->derecha = nullptr;
    this->altura = 1;
}

ArbolAVLEdades::ArbolAVLEdades() {
    raiz = nullptr;
}

ArbolAVLEdades::~ArbolAVLEdades() {
    liberarMemoria(raiz);
}

void ArbolAVLEdades::liberarMemoria(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);
    delete nodo;
}

int ArbolAVLEdades::altura(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int ArbolAVLEdades::maximo(int a, int b) {
    return (a > b) ? a : b;
}

int ArbolAVLEdades::obtenerBalance(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

NodoAVL* ArbolAVLEdades::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* temp = x->derecha;

    x->derecha = y;
    y->izquierda = temp;

    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

NodoAVL* ArbolAVLEdades::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecha;
    NodoAVL* temp = y->izquierda;

    y->izquierda = x;
    x->derecha = temp;

    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

void ArbolAVLEdades::insertar(Paciente* paciente) {
    raiz = insertarRecursivo(raiz, paciente);
}

NodoAVL* ArbolAVLEdades::insertarRecursivo(NodoAVL* nodo, Paciente* paciente) {
    if (nodo == nullptr) {
        return new NodoAVL(paciente);
    }

    if (paciente->getEdad() < nodo->paciente->getEdad()) {
        nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
    } else if (paciente->getEdad() > nodo->paciente->getEdad()) {
        nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
    } else {
        // Si tienen la misma edad, ordenamos por ID para no perder pacientes
        if (paciente->getId() < nodo->paciente->getId()) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, paciente);
        } else {
            nodo->derecha = insertarRecursivo(nodo->derecha, paciente);
        }
    }

    nodo->altura = 1 + maximo(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    // Caso izquierda izquierda
    if (balance > 1 && paciente->getEdad() < nodo->izquierda->paciente->getEdad()) {
        return rotacionDerecha(nodo);
    }

    // Caso derecha derecha
    if (balance < -1 && paciente->getEdad() > nodo->derecha->paciente->getEdad()) {
        return rotacionIzquierda(nodo);
    }

    // Caso izquierda derecha
    if (balance > 1 && paciente->getEdad() > nodo->izquierda->paciente->getEdad()) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // Caso derecha izquierda
    if (balance < -1 && paciente->getEdad() < nodo->derecha->paciente->getEdad()) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVLEdades::mostrarInOrden() {
    inOrdenRecursivo(raiz);
}

void ArbolAVLEdades::inOrdenRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    inOrdenRecursivo(nodo->izquierda);

    nodo->paciente->mostrar();
    cout << "Altura nodo: " << nodo->altura << endl;
    cout << "---------------------" << endl;

    inOrdenRecursivo(nodo->derecha);
}