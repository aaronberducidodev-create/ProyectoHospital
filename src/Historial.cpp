#include "../include/Historial.h"

// =============================================
// CONSTRUCTOR DEL NODO HISTORIAL
// =============================================
// Cada nodo almacena un registro clínico
// con diagnóstico, tratamiento y fecha.
// =============================================
NodoHistorial::NodoHistorial(string diagnostico, string tratamiento, string fecha) {
    this->diagnostico = diagnostico;
    this->tratamiento = tratamiento;
    this->fecha = fecha;
    this->siguiente = nullptr;
}

// =============================================
// CONSTRUCTOR DE HISTORIAL
// =============================================
// Inicializa la pila vacía.
// =============================================
Historial::Historial() {
    cima = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera todos los nodos almacenados
// en el historial clínico.
// =============================================
Historial::~Historial() {
    while (cima != nullptr) {
        NodoHistorial* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

// Verifica si la pila está vacía.
bool Historial::estaVacio() {
    return cima == nullptr;
}

// =============================================
// PUSH HISTORIAL
// =============================================
// Agrega un nuevo registro médico a la cima
// de la pila.
// =============================================
void Historial::pushHistorial(string diagnostico, string tratamiento, string fecha) {
    NodoHistorial* nuevo = new NodoHistorial(diagnostico, tratamiento, fecha);

    nuevo->siguiente = cima;
    cima = nuevo;
}

// =============================================
// POP HISTORIAL
// =============================================
// Elimina el último registro médico agregado.
// =============================================
bool Historial::popHistorial() {
    if (estaVacio()) {
        return false;
    }

    NodoHistorial* temp = cima;
    cima = cima->siguiente;
    delete temp;

    return true;
}

// =============================================
// MOSTRAR HISTORIAL
// =============================================
// Recorre la pila y muestra todos los
// registros clínicos del paciente.
// =============================================
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