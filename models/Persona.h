#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

// ===============================
// CLASE PADRE
// ===============================
// Persona sera la clase base.
// De aqui heredara Paciente.

class Persona {
protected:
    long long id;
    string nombre;
    int edad;

public:
    Persona();
    Persona(long long id, string nombre, int edad);

    virtual void mostrar();

    long long getId();
    string getNombre();
    int getEdad();

    void setNombre(string nombre);
    void setEdad(int edad);

    virtual ~Persona();
};

#endif