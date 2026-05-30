#ifndef LISTACITAS_H
#define LISTACITAS_H

#include "Cita.h"

// =============================================
// LISTA DOBLEMENTE ENLAZADA DE CITAS
// =============================================
// Gestiona todas las citas médicas
// registradas en el sistema.
//
// Utiliza una lista doblemente enlazada
// para permitir recorridos en ambos
// sentidos (adelante y atrás).
// =============================================
class ListaCitas {
private:

    // Primer nodo de la lista
    Cita* cabeza;

    // Último nodo de la lista
    Cita* cola;

public:

    // Constructor y destructor
    ListaCitas();
    ~ListaCitas();

    // =============================================
    // OPERACIONES PRINCIPALES
    // =============================================

    // Agrega una nueva cita al final
    // de la lista.
    void insertarCita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo);

    // Busca una cita por su ID.
    Cita* buscarCita(int idCita);

    // Elimina una cita existente.
    bool eliminarCita(int idCita);

    // =============================================
    // RECORRIDOS
    // =============================================

    // Recorre desde la cabeza hasta la cola.
    void mostrarAdelante();

    // Recorre desde la cola hasta la cabeza.
    void mostrarAtras();

    // Verifica si la lista está vacía.
    bool estaVacia();
};

#endif