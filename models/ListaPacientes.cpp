#include "ListaPacientes.h"
#include <iostream>

using namespace std;

// Constructor
ListaPacientes::ListaPacientes() {
    cabeza = nullptr;
}

// Destructor
ListaPacientes::~ListaPacientes() {
    Paciente* actual = cabeza;

    while (actual != nullptr) {
        Paciente* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    cabeza = nullptr;
}

// Verificar si esta vacia
bool ListaPacientes::estaVacia() {
    return cabeza == nullptr;
}

// Insertar paciente al inicio
void ListaPacientes::insertarPaciente(long long id, string nombre, int edad, string dpi) {
    Paciente* nuevo = new Paciente(id, nombre, edad, dpi);

    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// Buscar paciente por ID
Paciente* ListaPacientes::buscarPaciente(long long id) {
    Paciente* actual = cabeza;

    while (actual != nullptr) {
        if (actual->getId() == id) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

// Eliminar paciente por ID
bool ListaPacientes::eliminarPaciente(long long id) {
    if (cabeza == nullptr) {
        return false;
    }

    // Caso 1: el paciente a eliminar es el primero
    if (cabeza->getId() == id) {
        Paciente* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }

    // Caso 2: buscar en el resto de la lista
    Paciente* actual = cabeza;

    while (actual->siguiente != nullptr) {
        if (actual->siguiente->getId() == id) {
            Paciente* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

// Mostrar todos los pacientes
void ListaPacientes::mostrarPacientes() {
    if (cabeza == nullptr) {
        cout << "No hay pacientes registrados." << endl;
        return;
    }

    Paciente* actual = cabeza;

    while (actual != nullptr) {
        actual->mostrar();
        cout << "---------------------" << endl;
        actual = actual->siguiente;
    }
}

// =========================================
// NUEVO:
// Devuelve el inicio de la lista enlazada
// para poder recorrer pacientes desde
// otras partes del sistema.
// =========================================
Paciente* ListaPacientes::getCabeza() {
    return cabeza;
}