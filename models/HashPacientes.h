#ifndef HASHPACIENTES_H
#define HASHPACIENTES_H

#include "Paciente.h"

class NodoHash {
public:
    string dpi;
    Paciente* paciente;
    NodoHash* siguiente;

    NodoHash(string dpi, Paciente* paciente);
};

class HashPacientes {
private:
    static const int TAM = 10;
    NodoHash* tabla[TAM];

    int funcionHash(string dpi);

public:
    HashPacientes();
    ~HashPacientes();

    void insertar(string dpi, Paciente* paciente);
    Paciente* buscar(string dpi);
    void mostrarTabla();
};

#endif