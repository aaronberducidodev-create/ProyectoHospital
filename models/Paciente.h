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
// Persona contiene los atributos:
// id, nombre y edad.
//
// Paciente extiende la funcionalidad
// agregando DPI, historial clínico,
// prioridad y enlace para listas.
// ===============================

class Paciente : public Persona {
private:
    // Documento Personal de Identificación
    string dpi;

    // Historial médico asociado al paciente
    Historial historialClinico;

    // Prioridad utilizada en la cola de emergencias
    int prioridad;

public:
    // =============================================
    // CONSTRUCTOR
    // =============================================
    // Inicializa los datos básicos del paciente.
    // =============================================
    Paciente(long long id, string nombre, int edad, string dpi);

    // =============================================
    // GETTERS
    // =============================================
    // Permiten acceder a los datos del paciente
    // respetando el encapsulamiento.
    // =============================================
    long long getId();
    string getNombre();
    int getEdad();
    string getDpi();

    // =============================================
    // PRIORIDAD DE EMERGENCIAS
    // =============================================
    // Permite modificar y consultar la prioridad
    // asignada al paciente.
    // =============================================
    void setPrioridad(int prioridad);
    int getPrioridad();

    // ===============================
    // POLIMORFISMO
    // ===============================
    // Este metodo sobrescribe mostrar()
    // de la clase Persona.
    //
    // Permite mostrar la información
    // específica de un paciente.
    // ===============================
    void mostrar() override;

    // =============================================
    // HISTORIAL CLÍNICO
    // =============================================
    // Permite agregar y visualizar
    // registros médicos del paciente.
    // =============================================
    void agregarHistorial(string diagnostico, string tratamiento, string fecha);
    void mostrarHistorial();

    // =============================================
    // LISTA ENLAZADA
    // =============================================
    // Puntero utilizado para conectar pacientes
    // dentro de estructuras enlazadas.
    // =============================================
    Paciente* siguiente;
};

#endif