#include "Cita.h"
// ❌ ANTES:
// Cita::Cita(int idCita, int idPaciente, string doctor, string fecha, string hora, string motivo) {

// ✅ NUEVO:
Cita::Cita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo) {
    this->idCita = idCita;
    this->idPaciente = idPaciente;
    this->doctor = doctor;
    this->fecha = fecha;
    this->hora = hora;
    this->motivo = motivo;

    this->siguiente = nullptr;
    this->anterior = nullptr;
}

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

void Cita::mostrar() {
    cout << "ID Cita: " << idCita << endl;
    cout << "ID Paciente: " << idPaciente << endl;
    cout << "Doctor: " << doctor << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;
    cout << "Motivo: " << motivo << endl;
}