#include "ListaCitas.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DE LISTA DE CITAS
// =============================================
// Inicializa la lista doblemente enlazada vacía.
// =============================================
ListaCitas::ListaCitas() {
    cabeza = nullptr;
    cola = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera la memoria de todas las citas
// almacenadas en la lista.
// =============================================
ListaCitas::~ListaCitas() {
    Cita* actual = cabeza;

    while (actual != nullptr) {
        Cita* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    cabeza = nullptr;
    cola = nullptr;
}

// Verifica si no hay citas registradas.
bool ListaCitas::estaVacia() {
    return cabeza == nullptr;
}

// =============================================
// INSERTAR CITA
// =============================================
// Agrega una nueva cita al final de la lista.
//
// Al ser una lista doblemente enlazada,
// se actualizan los punteros siguiente
// y anterior.
// =============================================
void ListaCitas::insertarCita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo) {
    
    Cita* nueva = new Cita(idCita, idPaciente, doctor, fecha, hora, motivo);

    if (estaVacia()) {
        cabeza = nueva;
        cola = nueva;
    } else {
        cola->siguiente = nueva;
        nueva->anterior = cola;
        cola = nueva;
    }
}

// =============================================
// BUSCAR CITA
// =============================================
// Recorre la lista desde la cabeza hasta
// encontrar una cita por su ID.
// =============================================
Cita* ListaCitas::buscarCita(int idCita) {
    Cita* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getIdCita() == idCita) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

// =============================================
// ELIMINAR CITA
// =============================================
// Elimina una cita de la lista doblemente
// enlazada y ajusta los enlaces según
// su posición.
// =============================================
bool ListaCitas::eliminarCita(int idCita) {
    Cita* actual = buscarCita(idCita);

    if (actual == nullptr) {
        return false;
    }

    if (actual == cabeza && actual == cola) {
        cabeza = nullptr;
        cola = nullptr;
    } 
    else if (actual == cabeza) {
        cabeza = cabeza->siguiente;
        cabeza->anterior = nullptr;
    } 
    else if (actual == cola) {
        cola = cola->anterior;
        cola->siguiente = nullptr;
    } 
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual;
    return true;
}

// =============================================
// MOSTRAR HACIA ADELANTE
// =============================================
// Recorre la lista desde la cabeza
// hasta la cola.
// =============================================
void ListaCitas::mostrarAdelante() {
    if (estaVacia()) {
        cout << "No hay citas registradas." << endl;
        return;
    }

    Cita* actual = cabeza;

    while (actual != nullptr) {
        actual->mostrar();
        cout << "---------------------" << endl;
        actual = actual->siguiente;
    }
}

// =============================================
// MOSTRAR HACIA ATRÁS
// =============================================
// Recorre la lista desde la cola
// hasta la cabeza.
// =============================================
void ListaCitas::mostrarAtras() {
    if (estaVacia()) {
        cout << "No hay citas registradas." << endl;
        return;
    }

    Cita* actual = cola;

    while (actual != nullptr) {
        actual->mostrar();
        cout << "---------------------" << endl;
        actual = actual->anterior;
    }
}