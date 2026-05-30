#ifndef ARBOLEXPRESIONES_H
#define ARBOLEXPRESIONES_H

#include <string>

using namespace std;

// =============================================
// NODO DEL ÁRBOL DE EXPRESIONES
// =============================================
// Representa un elemento dentro del árbol.
//
// Puede almacenar:
// - Un operador: +, -, *, /
// - Un número: 500, 250, 1.12
//
// Cada nodo puede tener un hijo izquierdo
// y un hijo derecho.
// =============================================
struct NodoExpresion {
    string valor;
    NodoExpresion* izquierda;
    NodoExpresion* derecha;

    // Constructor del nodo
    NodoExpresion(string v) {
        valor = v;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// =============================================
// ÁRBOL DE EXPRESIONES
// =============================================
// Representa una fórmula matemática usando
// una estructura de árbol binario.
//
// En este proyecto se utiliza para simular
// el cálculo de facturación hospitalaria.
// =============================================
class ArbolExpresiones {
private:
    // Raíz del árbol de expresiones
    NodoExpresion* raiz;

    // Evalúa recursivamente cada nodo del árbol
    double evaluar(NodoExpresion* nodo);

public:
    // Constructor
    ArbolExpresiones();

    // Construye la expresión matemática del ejemplo
    void construirArbol();

    // Evalúa la expresión completa desde la raíz
    double evaluarExpresion();
};

#endif