#include "ArbolB.h"

NodoB::NodoB() {
    cantidad = 0;
}

void NodoB::insertar(int valor) {
    if (cantidad < 10) {
        claves[cantidad] = valor;
        cantidad++;
    }
}

void NodoB::mostrar() {
    cout << "\n===== ARBOL B =====" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << claves[i] << " ";
    }

    cout << endl;
}

void NodoB::limpiar() {
    cantidad = 0;
}

ArbolB::ArbolB() {
}

void ArbolB::insertar(int valor) {
    raiz.insertar(valor);
}

void ArbolB::mostrar() {
    raiz.mostrar();
}

void ArbolB::limpiar() {
    raiz.limpiar();
}