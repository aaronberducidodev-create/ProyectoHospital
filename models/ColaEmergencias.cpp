#include "ColaEmergencias.h"
#include <iostream>
#include <new>

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
// Nota: no elimina el objeto Paciente,
// porque ese pertenece a ListaPacientes.
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
//
// Validaciones:
// - Paciente no nulo.
// - Prioridad válida entre 1 y 3.
// - Manejo de error de memoria.
// =============================================
void ColaEmergencias::encolar(Paciente* paciente) {

    if (paciente == nullptr) {
        cout << "Error: paciente nulo, no se puede encolar." << endl;
        return;
    }

    if (paciente->getPrioridad() < 1 || paciente->getPrioridad() > 3) {
        cout << "Error: prioridad invalida. Debe ser 1, 2 o 3." << endl;
        return;
    }

    NodoCola* nuevo = nullptr;

    try {
        nuevo = new NodoCola(paciente);
    }
    catch (bad_alloc&) {
        cout << "Error: no se pudo reservar memoria para la cola." << endl;
        return;
    }

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
        actual->siguiente->paciente != nullptr &&
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
        if (actual->paciente != nullptr) {
            actual->paciente->mostrar();

            cout << "Prioridad de emergencia: "
                 << actual->paciente->getPrioridad()
                 << endl;
        } else {
            cout << "Nodo con paciente nulo." << endl;
        }

        cout << "---------------------" << endl;

        actual = actual->siguiente;
    }
}