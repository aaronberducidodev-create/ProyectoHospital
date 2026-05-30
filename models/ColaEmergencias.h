#ifndef COLAEMERGENCIAS_H
#define COLAEMERGENCIAS_H

#include "Paciente.h"

class NodoCola {
public:
    Paciente* paciente;
    NodoCola* siguiente;

    NodoCola(Paciente* paciente);
};

class ColaEmergencias {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    ColaEmergencias();
    ~ColaEmergencias();

    void encolar(Paciente* paciente);
    Paciente* desencolar();
    void mostrarCola();

    bool estaVacia();
};

#endif