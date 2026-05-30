#include "../include/MemoriaHospital.h"

// =============================================
// CONSTRUCTOR DEL BLOQUE DE MEMORIA
// =============================================
// Inicializa un bloque libre con tamaño 0.
// =============================================
BloqueMemoria::BloqueMemoria() {
    tamano = 0;
    ocupado = false;
}

// =============================================
// CONSTRUCTOR DEL GESTOR DE MEMORIA
// =============================================
// Simula bloques de memoria, camas o
// quirófanos disponibles dentro del hospital.
//
// Cada bloque tiene un tamaño determinado.
// =============================================
MemoriaHospital::MemoriaHospital() {
    bloques[0].tamano = 100;
    bloques[1].tamano = 250;
    bloques[2].tamano = 80;
    bloques[3].tamano = 300;
    bloques[4].tamano = 150;
    bloques[5].tamano = 500;
    bloques[6].tamano = 120;
    bloques[7].tamano = 200;
    bloques[8].tamano = 350;
    bloques[9].tamano = 90;
}

// =============================================
// MOSTRAR ESTADO DE MEMORIA
// =============================================
// Muestra todos los bloques indicando:
//
// - Tamaño disponible.
// - Si está libre u ocupado.
// =============================================
void MemoriaHospital::mostrarMemoria() {
    cout << "=== ESTADO DE MEMORIA / CAMAS / QUIROFANOS ===" << endl;

    for (int i = 0; i < TOTAL_BLOQUES; i++) {
        cout << "Bloque " << i
             << " | Tamano: " << bloques[i].tamano
             << " | Estado: " << (bloques[i].ocupado ? "Ocupado" : "Libre")
             << endl;
    }
}

// =============================================
// PRIMER AJUSTE (FIRST FIT)
// =============================================
// Busca el primer bloque libre que tenga
// espacio suficiente.
//
// Es uno de los algoritmos clásicos de
// administración de memoria.
// =============================================
bool MemoriaHospital::primerAjuste(int tamanoNecesario) {
    for (int i = 0; i < TOTAL_BLOQUES; i++) {
        if (!bloques[i].ocupado && bloques[i].tamano >= tamanoNecesario) {
            bloques[i].ocupado = true;
            cout << "Asignado con PRIMER AJUSTE en bloque " << i << endl;
            return true;
        }
    }

    cout << "No hay bloque disponible para primer ajuste." << endl;
    return false;
}

// =============================================
// MEJOR AJUSTE (BEST FIT)
// =============================================
// Busca el bloque libre más pequeño
// capaz de almacenar el tamaño solicitado.
//
// Reduce desperdicio de espacio.
// =============================================
bool MemoriaHospital::mejorAjuste(int tamanoNecesario) {
    int mejorIndice = -1;

    for (int i = 0; i < TOTAL_BLOQUES; i++) {
        if (!bloques[i].ocupado && bloques[i].tamano >= tamanoNecesario) {
            if (mejorIndice == -1 || bloques[i].tamano < bloques[mejorIndice].tamano) {
                mejorIndice = i;
            }
        }
    }

    if (mejorIndice != -1) {
        bloques[mejorIndice].ocupado = true;
        cout << "Asignado con MEJOR AJUSTE en bloque " << mejorIndice << endl;
        return true;
    }

    cout << "No hay bloque disponible para mejor ajuste." << endl;
    return false;
}

// =============================================
// PEOR AJUSTE (WORST FIT)
// =============================================
// Busca el bloque libre más grande
// disponible.
//
// Intenta evitar fragmentación temprana.
// =============================================
bool MemoriaHospital::peorAjuste(int tamanoNecesario) {
    int peorIndice = -1;

    for (int i = 0; i < TOTAL_BLOQUES; i++) {
        if (!bloques[i].ocupado && bloques[i].tamano >= tamanoNecesario) {
            if (peorIndice == -1 || bloques[i].tamano > bloques[peorIndice].tamano) {
                peorIndice = i;
            }
        }
    }

    if (peorIndice != -1) {
        bloques[peorIndice].ocupado = true;
        cout << "Asignado con PEOR AJUSTE en bloque " << peorIndice << endl;
        return true;
    }

    cout << "No hay bloque disponible para peor ajuste." << endl;
    return false;
}

// =============================================
// LIBERAR BLOQUE
// =============================================
// Marca un bloque ocupado como disponible
// nuevamente.
// =============================================
void MemoriaHospital::liberarBloque(int posicion) {
    if (posicion < 0 || posicion >= TOTAL_BLOQUES) {
        cout << "Posicion invalida." << endl;
        return;
    }

    if (!bloques[posicion].ocupado) {
        cout << "Ese bloque ya esta libre." << endl;
        return;
    }

    bloques[posicion].ocupado = false;
    cout << "Bloque " << posicion << " liberado correctamente." << endl;
}