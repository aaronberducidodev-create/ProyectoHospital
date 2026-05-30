#ifndef ARBOLAVLEDADES_H
#define ARBOLAVLEDADES_H

#include "Paciente.h"

class NodoAVL {
public:
    Paciente* paciente;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL(Paciente* paciente);
};

class ArbolAVLEdades {
private:
    NodoAVL* raiz;

    int altura(NodoAVL* nodo);
    int maximo(int a, int b);
    int obtenerBalance(NodoAVL* nodo);

    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);

    NodoAVL* insertarRecursivo(NodoAVL* nodo, Paciente* paciente);

    void inOrdenRecursivo(NodoAVL* nodo);
    void liberarMemoria(NodoAVL* nodo);

public:
    ArbolAVLEdades();
    ~ArbolAVLEdades();

    void insertar(Paciente* paciente);
    void mostrarInOrden();
};

#endif