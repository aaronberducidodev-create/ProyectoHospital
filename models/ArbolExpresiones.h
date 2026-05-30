#ifndef ARBOLEXPRESIONES_H
#define ARBOLEXPRESIONES_H

#include <string>

using namespace std;

// Nodo del arbol
struct NodoExpresion {
    string valor;
    NodoExpresion* izquierda;
    NodoExpresion* derecha;

    NodoExpresion(string v) {
        valor = v;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

class ArbolExpresiones {
private:
    NodoExpresion* raiz;

    double evaluar(NodoExpresion* nodo);

public:
    ArbolExpresiones();

    void construirArbol();

    double evaluarExpresion();
};

#endif