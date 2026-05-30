#include "ListaCitas.h"
#include <iostream>

using namespace std;

ListaCitas::ListaCitas() {
    cabeza = nullptr;
    cola = nullptr;
}

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

bool ListaCitas::estaVacia() {
    return cabeza == nullptr;
}

// ❌ ANTES:
// void ListaCitas::insertarCita(int idCita, int idPaciente, string doctor, string fecha, string hora, string motivo) {

// ✅ NUEVO:
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