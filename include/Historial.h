#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
using namespace std;

// Nodo de la pila
class NodoHistorial {
public:
    string diagnostico;
    string tratamiento;
    string fecha;
    NodoHistorial* siguiente;

    NodoHistorial(string diagnostico, string tratamiento, string fecha);
};

// Clase pila para historial clínico
class Historial {
private:
    NodoHistorial* cima;

public:
    // Constructor
    Historial();

    // Destructor
    ~Historial();

    // Operaciones de pila
    void pushHistorial(string diagnostico, string tratamiento, string fecha);
    bool popHistorial();
    void mostrarHistorial();

    // Utilidad
    bool estaVacio();
};

#endif