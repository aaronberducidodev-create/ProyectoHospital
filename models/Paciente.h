#ifndef PACIENTE_H
#define PACIENTE_H

#include "Historial.h"
#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;

// ===============================
// CLASE PACIENTE
// ===============================
// Hereda de Persona.
// Persona tiene: id, nombre, edad.
// Paciente agrega: dpi, historialClinico y siguiente.

class Paciente : public Persona {
private:
    string dpi;

    // Historial clinico por paciente
    Historial historialClinico;
    int prioridad;

public:
    // Constructor
    Paciente(long long id, string nombre, int edad, string dpi);

    // Obtener datos
    long long getId();
    string getNombre();
    int getEdad();
    string getDpi();
    void setPrioridad(int prioridad);
    int getPrioridad();

    // ===============================
    // POLIMORFISMO
    // ===============================
    // Este metodo sobrescribe mostrar()
    // de la clase Persona.
    void mostrar() override;

    // Historial clinico
    void agregarHistorial(string diagnostico, string tratamiento, string fecha);
    void mostrarHistorial();

    // Puntero para la lista enlazada
    Paciente* siguiente;
};

#endif