#ifndef CITA_H
#define CITA_H

#include <iostream>
using namespace std;

class Cita {
private:
    int idCita;
    int idPaciente;
    string doctor;
    string fecha;
    string hora;
    string motivo;

public:
    //Cita(int idCita, int idPaciente, string doctor, string fecha, string hora, string motivo);
   Cita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo);

    int getIdCita();
    int getIdPaciente();
    string getDoctor();
    string getFecha();
    string getHora();
    string getMotivo();

    void mostrar();

    Cita* siguiente;
    Cita* anterior;
};

#endif