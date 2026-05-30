#include "ArbolExpresiones.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// =============================================
// CONSTRUCTOR DEL ÁRBOL DE EXPRESIONES
// =============================================
// Inicializa el árbol vacío.
// =============================================
ArbolExpresiones::ArbolExpresiones() {
    raiz = nullptr;
}

// =============================================
// CONSTRUCCIÓN DEL ÁRBOL
// =============================================
// Representa la expresión:
//
// (CostoConsulta + Medicamentos) * IVA
//
// Ejemplo:
// (500 + 250) * 1.12
//
// Se utiliza un árbol binario donde:
// - Los operadores son nodos internos.
// - Los números son hojas.
// =============================================
void ArbolExpresiones::construirArbol() {

    raiz = new NodoExpresion("*");

    raiz->izquierda = new NodoExpresion("+");
    raiz->derecha = new NodoExpresion("1.12");

    raiz->izquierda->izquierda = new NodoExpresion("500");
    raiz->izquierda->derecha = new NodoExpresion("250");
}

// =============================================
// EVALUACIÓN RECURSIVA
// =============================================
// Recorre el árbol y calcula el resultado
// de la expresión matemática.
//
// Primero resuelve los hijos y luego
// aplica el operador correspondiente.
// =============================================
double ArbolExpresiones::evaluar(NodoExpresion* nodo) {

    // Si el nodo contiene un número,
    // se convierte a double y se retorna.
    if (nodo->valor != "+" &&
        nodo->valor != "-" &&
        nodo->valor != "*" &&
        nodo->valor != "/") {

        return atof(nodo->valor.c_str());
    }

    double izq = evaluar(nodo->izquierda);
    double der = evaluar(nodo->derecha);

    // Operaciones matemáticas soportadas
    if (nodo->valor == "+") return izq + der;
    if (nodo->valor == "-") return izq - der;
    if (nodo->valor == "*") return izq * der;
    if (nodo->valor == "/") return izq / der;

    return 0;
}

// =============================================
// EVALUAR EXPRESIÓN COMPLETA
// =============================================
// Inicia la evaluación desde la raíz
// del árbol de expresiones.
// =============================================
double ArbolExpresiones::evaluarExpresion() {
    return evaluar(raiz);
}