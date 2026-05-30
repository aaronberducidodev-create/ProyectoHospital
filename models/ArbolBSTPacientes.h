#ifndef ARBOLBSTPACIENTES_H
#define ARBOLBSTPACIENTES_H

#include "Paciente.h"

class NodoBST {
public:
    Paciente* paciente;
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(Paciente* paciente);
};

class ArbolBSTPacientes {
private:
    NodoBST* raiz;

    NodoBST* insertarRecursivo(NodoBST* nodo, Paciente* paciente);
    Paciente* buscarRecursivo(NodoBST* nodo, int id);

    void inOrdenRecursivo(NodoBST* nodo);
    void preOrdenRecursivo(NodoBST* nodo);
    void postOrdenRecursivo(NodoBST* nodo);

    void liberarMemoria(NodoBST* nodo);

public:
    ArbolBSTPacientes();
    ~ArbolBSTPacientes();

    void insertar(Paciente* paciente);
    Paciente* buscar(int id);

    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
};

#endif