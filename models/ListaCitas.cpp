#include "ListaCitas.h"
#include <iostream>
#include <new>

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
// Validaciones:
// - Evita insertar citas con ID duplicado.
// - Verifica si hubo error al reservar memoria.
// =============================================
void ListaCitas::insertarCita(int idCita, long long idPaciente, string doctor, string fecha, string hora, string motivo) {

    if (buscarCita(idCita) != nullptr) {
        cout << "Error: ya existe una cita con ese ID." << endl;
        return;
    }

    Cita* nueva = nullptr;

    try {
        nueva = new Cita(idCita, idPaciente, doctor, fecha, hora, motivo);
    }
    catch (bad_alloc&) {
        cout << "Error: no se pudo reservar memoria para la cita." << endl;
        return;
    }

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
//
// Casos:
// - Lista vacía o cita no encontrada.
// - Única cita.
// - Primera cita.
// - Última cita.
// - Cita intermedia.
// =============================================
bool ListaCitas::eliminarCita(int idCita) {
    Cita* actual = buscarCita(idCita);

    if (actual == nullptr) {
        cout << "Cita no encontrada para eliminar." << endl;
        return false;
    }

    if (actual == cabeza && actual == cola) {
        cabeza = nullptr;
        cola = nullptr;
    }
    else if (actual == cabeza) {
        cabeza = cabeza->siguiente;

        if (cabeza != nullptr) {
            cabeza->anterior = nullptr;
        }
    }
    else if (actual == cola) {
        cola = cola->anterior;

        if (cola != nullptr) {
            cola->siguiente = nullptr;
        }
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