#include "ArbolExpresiones.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ArbolExpresiones::ArbolExpresiones() {
    raiz = nullptr;
}

// Construir arbol:
// (CostoConsulta + Medicamentos) * IVA
void ArbolExpresiones::construirArbol() {

    raiz = new NodoExpresion("*");

    raiz->izquierda = new NodoExpresion("+");
    raiz->derecha = new NodoExpresion("1.12");

    raiz->izquierda->izquierda = new NodoExpresion("500");
    raiz->izquierda->derecha = new NodoExpresion("250");
}

// Evaluar recursivamente
double ArbolExpresiones::evaluar(NodoExpresion* nodo) {

    // Si es numero
    if (nodo->valor != "+" &&
        nodo->valor != "-" &&
        nodo->valor != "*" &&
        nodo->valor != "/") {

        return atof(nodo->valor.c_str());
    }

    double izq = evaluar(nodo->izquierda);
    double der = evaluar(nodo->derecha);

    if (nodo->valor == "+") return izq + der;
    if (nodo->valor == "-") return izq - der;
    if (nodo->valor == "*") return izq * der;
    if (nodo->valor == "/") return izq / der;

    return 0;
}

double ArbolExpresiones::evaluarExpresion() {
    return evaluar(raiz);
}