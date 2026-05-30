#include "Paciente.h"

// Constructor
// Ahora Paciente llama al constructor de Persona
// SISTEMA FIFO primero en entrar → primero en salir funciona del normal FIFO normal
Paciente::Paciente(long long id, string nombre, int edad, string dpi)
    : Persona(id, nombre, edad) {


    this->dpi = dpi;
    this->prioridad = 3; // Prioridad normal por defecto
    this->siguiente = nullptr;
}

// Getters
long long Paciente::getId() {
    return id;
}

string Paciente::getNombre() {
    return nombre;
}

int Paciente::getEdad() {
    return edad;
}

string Paciente::getDpi() {
    return dpi;
}

// ===============================
// POLIMORFISMO
// ===============================
// Este mostrar() sobrescribe el mostrar()
// de la clase Persona.
void Paciente::mostrar() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "DPI: " << dpi << endl;
}

// Historial clinico
void Paciente::agregarHistorial(string diagnostico, string tratamiento, string fecha) {
    historialClinico.pushHistorial(diagnostico, tratamiento, fecha);
}

void Paciente::mostrarHistorial() {
    historialClinico.mostrarHistorial();
}

void Paciente::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Paciente::getPrioridad() {
    return prioridad;
}