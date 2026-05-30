#ifndef COLAEMERGENCIAS_H
#define COLAEMERGENCIAS_H

#include "Paciente.h"

// =============================================
// NODO DE LA COLA
// =============================================
// Representa un nodo dentro de la cola
// de emergencias.
//
// Cada nodo almacena:
// - Un paciente.
// - Un enlace al siguiente nodo.
// =============================================
class NodoCola {
public:
    Paciente* paciente;
    NodoCola* siguiente;

    // Constructor del nodo
    NodoCola(Paciente* paciente);
};

// =============================================
// COLA DE EMERGENCIAS
// =============================================
// Gestiona la atención de pacientes
// utilizando una cola con prioridad.
//
// Prioridades:
// 1 = Crítico
// 2 = Urgente
// 3 = Normal
//
// Los pacientes más críticos son
// atendidos primero.
// =============================================
class ColaEmergencias {
private:

    // Primer paciente de la cola
    NodoCola* frente;

    // Último paciente de la cola
    NodoCola* final;

public:

    // Constructor y destructor
    ColaEmergencias();
    ~ColaEmergencias();

    // =============================================
    // OPERACIONES PRINCIPALES
    // =============================================

    // Agrega un paciente a la cola
    // según su prioridad.
    void encolar(Paciente* paciente);

    // Atiende y elimina el paciente
    // que se encuentra al frente.
    Paciente* desencolar();

    // Muestra todos los pacientes
    // pendientes de atención.
    void mostrarCola();

    // Verifica si la cola está vacía.
    bool estaVacia();
};

#endif