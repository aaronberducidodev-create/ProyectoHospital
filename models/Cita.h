#ifndef CITA_H
#define CITA_H

#include <iostream>
using namespace std;

// =============================================
// CLASE CITA
// =============================================
// Representa una cita médica dentro del sistema.
//
// Cada cita almacena:
// - Identificador de la cita.
// - Paciente asociado.
// - Doctor asignado.
// - Fecha y hora.
// - Motivo de la consulta.
// =============================================
class Cita {
private:

    // Identificador único de la cita
    int idCita;

    // Identificador del paciente relacionado
    int idPaciente;

    // Información de la cita médica
    string doctor;
    string fecha;
    string hora;
    string motivo;

public:

    // =============================================
    // CONSTRUCTOR
    // =============================================
    // Inicializa todos los datos necesarios
    // para registrar una cita médica.
    // =============================================
    //Cita(int idCita, int idPaciente, string doctor, string fecha, string hora, string motivo);
    Cita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo);

    // =============================================
    // GETTERS
    // =============================================
    // Permiten consultar los datos de la cita
    // respetando el encapsulamiento.
    // =============================================
    int getIdCita();
    int getIdPaciente();
    string getDoctor();
    string getFecha();
    string getHora();
    string getMotivo();

    // =============================================
    // MUESTRA LA INFORMACIÓN COMPLETA
    // DE LA CITA MÉDICA
    // =============================================
    void mostrar();

    // =============================================
    // LISTA DOBLEMENTE ENLAZADA
    // =============================================
    // siguiente -> apunta al siguiente nodo
    // anterior -> apunta al nodo anterior
    //
    // Permite recorrer las citas en ambos
    // sentidos dentro de la lista.
    // =============================================
    Cita* siguiente;
    Cita* anterior;
};

#endif