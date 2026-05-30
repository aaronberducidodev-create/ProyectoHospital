#include "../include/Historial.h"

// Constructor del nodo
NodoHistorial::NodoHistorial(string diagnostico, string tratamiento, string fecha) {
    this->diagnostico = diagnostico;
    this->tratamiento = tratamiento;
    this->fecha = fecha;
    this->siguiente = nullptr;
}

// Constructor de la pila
Historial::Historial() {
    cima = nullptr;
}

// Destructor
Historial::~Historial() {
    while (cima != nullptr) {
        NodoHistorial* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

// Verifica si la pila está vacía
bool Historial::estaVacio() {
    return cima == nullptr;
}

// Push: agregar historial
void Historial::pushHistorial(string diagnostico, string tratamiento, string fecha) {
    NodoHistorial* nuevo = new NodoHistorial(diagnostico, tratamiento, fecha);

    nuevo->siguiente = cima;
    cima = nuevo;
}

// Pop: eliminar último historial agregado
bool Historial::popHistorial() {
    if (estaVacio()) {
        return false;
    }

    NodoHistorial* temp = cima;
    cima = cima->siguiente;
    delete temp;

    return true;
}

// Mostrar historial completo
void Historial::mostrarHistorial() {
    if (estaVacio()) {
        cout << "No hay historial clínico registrado." << endl;
        return;
    }

    NodoHistorial* actual = cima;
    while (actual != nullptr) {
        cout << "Fecha: " << actual->fecha << endl;
        cout << "Diagnóstico: " << actual->diagnostico << endl;
        cout << "Tratamiento: " << actual->tratamiento << endl;
        cout << "-------------------------" << endl;

        actual = actual->siguiente;
    }
}