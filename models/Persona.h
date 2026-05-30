#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

// ===============================
// CLASE PADRE (CLASE BASE)
// ===============================
// Representa una persona dentro del sistema.
//
// Esta clase sirve como base para aplicar
// HERENCIA en Programación Orientada a Objetos.
//
// La clase Paciente hereda de Persona,
// reutilizando sus atributos y métodos.
// ===============================
class Persona {
protected:

    // Datos comunes que heredarán
    // las clases derivadas.
    long long id;
    string nombre;
    int edad;

public:

    // =============================================
    // CONSTRUCTORES
    // =============================================
    // Permiten crear objetos Persona con o sin
    // valores iniciales.
    // =============================================
    Persona();
    Persona(long long id, string nombre, int edad);

    // =============================================
    // POLIMORFISMO
    // =============================================
    // Método virtual que puede ser sobrescrito
    // por las clases hijas como Paciente.
    // =============================================
    virtual void mostrar();

    // =============================================
    // GETTERS
    // =============================================
    // Permiten obtener información de la persona
    // respetando el encapsulamiento.
    // =============================================
    long long getId();
    string getNombre();
    int getEdad();

    // =============================================
    // SETTERS
    // =============================================
    // Permiten modificar atributos de la clase.
    // =============================================
    void setNombre(string nombre);
    void setEdad(int edad);

    // =============================================
    // DESTRUCTOR VIRTUAL
    // =============================================
    // Garantiza la correcta liberación de memoria
    // cuando se trabaja con herencia.
    // =============================================
    virtual ~Persona();
};

#endif