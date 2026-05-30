#ifndef LISTACITAS_H
#define LISTACITAS_H

#include "Cita.h"

class ListaCitas {
private:
    Cita* cabeza;
    Cita* cola;

public:
    ListaCitas();
    ~ListaCitas();

    void insertarCita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo);
    Cita* buscarCita(int idCita);
    bool eliminarCita(int idCita);

    void mostrarAdelante();
    void mostrarAtras();

    bool estaVacia();
};

#endif