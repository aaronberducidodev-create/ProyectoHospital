#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>

using namespace std;

// ===============================
// NODO DEL ARBOL B
// ===============================

class NodoB {
public:
    int claves[10];
    int cantidad;

    NodoB();

    void insertar(int valor);
    void mostrar();
    void limpiar();
};

// ===============================
// ARBOL B
// ===============================

class ArbolB {
private:
    NodoB raiz;

public:
    ArbolB();

    void insertar(int valor);
    void mostrar();
    void limpiar();
};

#endif