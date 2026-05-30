#include "ListaPacientes.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DE LISTA DE PACIENTES
// =============================================
// Inicializa la lista enlazada vacía.
// =============================================
ListaPacientes::ListaPacientes() {
    cabeza = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera toda la memoria utilizada por
// los pacientes almacenados en la lista.
// =============================================
ListaPacientes::~ListaPacientes() {
    Paciente* actual = cabeza;

    while (actual != nullptr) {
        Paciente* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    cabeza = nullptr;
}

// =============================================
// VERIFICAR SI LA LISTA ESTÁ VACÍA
// =============================================
// Retorna true si no existen pacientes
// registrados en la lista.
// =============================================
bool ListaPacientes::estaVacia() {
    return cabeza == nullptr;
}

// =============================================
// INSERTAR PACIENTE
// =============================================
// Inserta un nuevo paciente al inicio
// de la lista enlazada.
//
// Estructura utilizada:
// Lista simplemente enlazada.
// =============================================
void ListaPacientes::insertarPaciente(long long id, string nombre, int edad, string dpi) {
    Paciente* nuevo = new Paciente(id, nombre, edad, dpi);

    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// =============================================
// BUSCAR PACIENTE POR ID
// =============================================
// Recorre la lista hasta encontrar
// un paciente con el ID solicitado.
// =============================================
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

// =============================================
// ELIMINAR PACIENTE
// =============================================
// Elimina un paciente utilizando su ID.
//
// Caso 1:
// El paciente es la cabeza.
//
// Caso 2:
// El paciente se encuentra en cualquier
// otra posición de la lista.
// =============================================
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

// =============================================
// MOSTRAR PACIENTES
// =============================================
// Recorre toda la lista enlazada
// mostrando la información de cada paciente.
// =============================================
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

// =============================================
// OBTENER CABEZA DE LA LISTA
// =============================================
// Devuelve el primer nodo de la lista.
//
// Se utiliza para recorrer pacientes
// desde otras clases del sistema.
// =============================================
Paciente* ListaPacientes::getCabeza() {
    return cabeza;
}