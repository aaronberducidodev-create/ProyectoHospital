#include "Cita.h"

// =============================================
// CONSTRUCTOR DE CITA
// =============================================
// Inicializa todos los datos necesarios para
// registrar una cita médica.
//
// También inicializa los punteros utilizados
// en la lista doblemente enlazada.
// =============================================
Cita::Cita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo) {
    this->idCita = idCita;
    this->idPaciente = idPaciente;
    this->doctor = doctor;
    this->fecha = fecha;
    this->hora = hora;
    this->motivo = motivo;

    // Inicializa los enlaces de la lista
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

// =============================================
// GETTERS
// =============================================
// Permiten acceder a la información de la cita
// respetando el encapsulamiento.
// =============================================
int Cita::getIdCita() {
    return idCita;
}

int Cita::getIdPaciente() {
    return idPaciente;
}

string Cita::getDoctor() {
    return doctor;
}

string Cita::getFecha() {
    return fecha;
}

string Cita::getHora() {
    return hora;
}

string Cita::getMotivo() {
    return motivo;
}

// =============================================
// MOSTRAR CITA
// =============================================
// Muestra toda la información almacenada
// de una cita médica.
// =============================================
void Cita::mostrar() {
    cout << "ID Cita: " << idCita << endl;
    cout << "ID Paciente: " << idPaciente << endl;
    cout << "Doctor: " << doctor << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;
    cout << "Motivo: " << motivo << endl;
}