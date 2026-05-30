#include "ArbolBSTPacientes.h"
#include <iostream>

using namespace std;

NodoBST::NodoBST(Paciente* paciente) {
    this->paciente = paciente;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}

ArbolBSTPacientes::ArbolBSTPacientes() {
    raiz = nullptr;
}

ArbolBSTPacientes::~ArbolBSTPacientes() {
    liberarMemoria(raiz);
}

void ArbolBSTPacientes::liberarMemoria(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberarMemoria(nodo->izquierda);
    liberarMemoria(nodo->derecha);

    delete nodo;
}

void ArbolBSTPacientes::insertar(Paciente* paciente) {
    raiz = insertarRecursivo(raiz, paciente);
}

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

Paciente* ArbolBSTPacientes::buscar(int id) {
    return buscarRecursivo(raiz, id);
}

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

void ArbolBSTPacientes::mostrarInOrden() {
    inOrdenRecursivo(raiz);
}

void ArbolBSTPacientes::inOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    inOrdenRecursivo(nodo->izquierda);
    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
    inOrdenRecursivo(nodo->derecha);
}

void ArbolBSTPacientes::mostrarPreOrden() {
    preOrdenRecursivo(raiz);
}

void ArbolBSTPacientes::preOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
    preOrdenRecursivo(nodo->izquierda);
    preOrdenRecursivo(nodo->derecha);
}

void ArbolBSTPacientes::mostrarPostOrden() {
    postOrdenRecursivo(raiz);
}

void ArbolBSTPacientes::postOrdenRecursivo(NodoBST* nodo) {
    if (nodo == nullptr) {
        return;
    }

    postOrdenRecursivo(nodo->izquierda);
    postOrdenRecursivo(nodo->derecha);
    nodo->paciente->mostrar();
    cout << "---------------------" << endl;
}