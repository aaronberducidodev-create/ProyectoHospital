#include "ColaEmergencias.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DEL NODO DE COLA
// =============================================
// Cada nodo almacena un paciente y apunta
// al siguiente nodo de la cola.
// =============================================
NodoCola::NodoCola(Paciente* paciente) {
    this->paciente = paciente;
    this->siguiente = nullptr;
}

// =============================================
// CONSTRUCTOR DE COLA DE EMERGENCIAS
// =============================================
// Inicializa la cola vacía.
// =============================================
ColaEmergencias::ColaEmergencias() {
    frente = nullptr;
    final = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera todos los nodos pendientes
// de la cola.
// =============================================
ColaEmergencias::~ColaEmergencias() {
    while (!estaVacia()) {
        desencolar();
    }
}

// Verifica si la cola está vacía.
bool ColaEmergencias::estaVacia() {
    return frente == nullptr;
}

// =============================================
// ENCOLAR PACIENTE
// =============================================
// Agrega un paciente a la cola de emergencias
// según su prioridad de triaje.
// =============================================
void ColaEmergencias::encolar(Paciente* paciente) {
    NodoCola* nuevo = new NodoCola(paciente);

    // ===============================
    // COLA CON PRIORIDAD / TRIAJE
    // ===============================
    // Prioridad:
    // 1 = Critico
    // 2 = Urgente
    // 3 = Normal
    //
    // Mientras menor sea el numero,
    // mayor prioridad tiene el paciente.
    // ===============================

    if (estaVacia()) {
        frente = nuevo;
        final = nuevo;
        return;
    }

    // Si el nuevo paciente tiene mayor prioridad
    // que el primero de la cola, entra al frente.
    if (paciente->getPrioridad() < frente->paciente->getPrioridad()) {
        nuevo->siguiente = frente;
        frente = nuevo;
        return;
    }

    // Buscar la posicion correcta segun prioridad.
    NodoCola* actual = frente;

    while (
        actual->siguiente != nullptr &&
        actual->siguiente->paciente->getPrioridad() <= paciente->getPrioridad()
    ) {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;

    // Si se inserto al final, actualizar final.
    if (nuevo->siguiente == nullptr) {
        final = nuevo;
    }
}

// =============================================
// DESENCOLAR PACIENTE
// =============================================
// Atiende y elimina al paciente que está
// al frente de la cola.
// =============================================
Paciente* ColaEmergencias::desencolar() {
    if (estaVacia()) {
        return nullptr;
    }

    NodoCola* temp = frente;
    Paciente* pacienteAtendido = frente->paciente;

    frente = frente->siguiente;

    if (frente == nullptr) {
        final = nullptr;
    }

    delete temp;
    return pacienteAtendido;
}

// =============================================
// MOSTRAR COLA
// =============================================
// Recorre la cola y muestra todos los
// pacientes pendientes de atención.
// =============================================
void ColaEmergencias::mostrarCola() {
    if (estaVacia()) {
        cout << "No hay pacientes en emergencia." << endl;
        return;
    }

    NodoCola* actual = frente;

    while (actual != nullptr) {
        actual->paciente->mostrar();

        cout << "Prioridad de emergencia: "
             << actual->paciente->getPrioridad()
             << endl;

        cout << "---------------------" << endl;

        actual = actual->siguiente;
    }
}