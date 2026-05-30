#include "Paciente.h"

// =============================================
// CONSTRUCTOR DE PACIENTE
// =============================================
// Paciente hereda de la clase Persona.
// Inicializa los datos básicos del paciente,
// además de su prioridad y puntero siguiente.
// =============================================

Paciente::Paciente(long long id, string nombre, int edad, string dpi)
    : Persona(id, nombre, edad) {


    this->dpi = dpi;

    // Prioridad normal por defecto para emergencias
    this->prioridad = 3;

    // Inicializa el puntero siguiente en nulo
    this->siguiente = nullptr;
}

// =============================================
// GETTERS
// =============================================
// Permiten obtener los datos del paciente
// respetando el encapsulamiento.
// =============================================
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
//
// Permite mostrar la información completa
// de un paciente.
// ===============================
void Paciente::mostrar() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "DPI: " << dpi << endl;
}

// =============================================
// HISTORIAL CLÍNICO
// =============================================
// Agrega un nuevo registro médico al
// historial del paciente.
// =============================================
void Paciente::agregarHistorial(string diagnostico, string tratamiento, string fecha) {
    historialClinico.pushHistorial(diagnostico, tratamiento, fecha);
}

// =============================================
// HISTORIAL CLÍNICO
// =============================================
// Muestra todos los registros almacenados
// en el historial médico del paciente.
// =============================================
void Paciente::mostrarHistorial() {
    historialClinico.mostrarHistorial();
}

// =============================================
// PRIORIDAD DE EMERGENCIAS
// =============================================
// Modifica la prioridad utilizada para
// la atención en la cola de emergencias.
// =============================================
void Paciente::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

// =============================================
// PRIORIDAD DE EMERGENCIAS
// =============================================
// Devuelve la prioridad actual asignada
// al paciente.
// =============================================
int Paciente::getPrioridad() {
    return prioridad;
}