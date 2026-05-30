#ifndef MEMORIAHOSPITAL_H
#define MEMORIAHOSPITAL_H

#include <iostream>
using namespace std;

class BloqueMemoria {
public:
    int tamano;
    bool ocupado;

    BloqueMemoria();
};

class MemoriaHospital {
private:
    static const int TOTAL_BLOQUES = 10;
    BloqueMemoria bloques[TOTAL_BLOQUES];

public:
    MemoriaHospital();

    void mostrarMemoria();

    bool primerAjuste(int tamanoNecesario);
    bool mejorAjuste(int tamanoNecesario);
    bool peorAjuste(int tamanoNecesario);

    void liberarBloque(int posicion);
};

#endif