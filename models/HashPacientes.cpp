#include "HashPacientes.h"
#include <iostream>

using namespace std;

// =============================================
// CONSTRUCTOR DEL NODO HASH
// =============================================
// Crea un nodo que almacena:
// - DPI (clave)
// - Paciente asociado
// - Enlace al siguiente nodo
// =============================================
NodoHash::NodoHash(string dpi, Paciente* paciente) {
    this->dpi = dpi;
    this->paciente = paciente;
    this->siguiente = nullptr;
}

// =============================================
// CONSTRUCTOR DE LA TABLA HASH
// =============================================
// Inicializa todas las posiciones de la tabla
// en nullptr indicando que están vacías.
// =============================================
HashPacientes::HashPacientes() {
    for (int i = 0; i < TAM; i++) {
        tabla[i] = nullptr;
    }
}

// =============================================
// DESTRUCTOR
// =============================================
// Libera la memoria utilizada por todos los
// nodos almacenados en la tabla hash.
// =============================================
HashPacientes::~HashPacientes() {
    for (int i = 0; i < TAM; i++) {
        NodoHash* actual = tabla[i];

        while (actual != nullptr) {
            NodoHash* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }

        tabla[i] = nullptr;
    }
}

// =============================================
// FUNCIÓN HASH
// =============================================
// Convierte el DPI en una posición válida
// dentro de la tabla hash.
//
// Se suman los caracteres del DPI y luego
// se aplica módulo con el tamaño de la tabla.
// =============================================
int HashPacientes::funcionHash(string dpi) {
    int suma = 0;

    for (int i = 0; i < dpi.length(); i++) {
        suma += dpi[i];
    }

    return suma % TAM;
}

// =============================================
// INSERTAR PACIENTE
// =============================================
// Inserta un paciente utilizando su DPI
// como clave.
//
// Utiliza encadenamiento para resolver
// colisiones dentro de la tabla hash.
// =============================================
void HashPacientes::insertar(string dpi, Paciente* paciente) {
    int indice = funcionHash(dpi);

    NodoHash* nuevo = new NodoHash(dpi, paciente);

    // Encadenamiento: se inserta al inicio de la posición
    nuevo->siguiente = tabla[indice];
    tabla[indice] = nuevo;
}

// =============================================
// BUSCAR PACIENTE
// =============================================
// Busca un paciente utilizando su DPI.
//
// Recorre la lista enlazada de la posición
// correspondiente hasta encontrar la clave.
// =============================================
Paciente* HashPacientes::buscar(string dpi) {
    int indice = funcionHash(dpi);

    NodoHash* actual = tabla[indice];

    while (actual != nullptr) {
        if (actual->dpi == dpi) {
            return actual->paciente;
        }

        actual = actual->siguiente;
    }

    // Retorna nullptr si no existe
    return nullptr;
}

// =============================================
// MOSTRAR TABLA HASH
// =============================================
// Muestra todas las posiciones de la tabla
// y los elementos almacenados en cada una.
// =============================================
void HashPacientes::mostrarTabla() {
    for (int i = 0; i < TAM; i++) {
        cout << "Indice [" << i << "]: ";

        NodoHash* actual = tabla[i];

        if (actual == nullptr) {
            cout << "vacio";
        }

        while (actual != nullptr) {
            cout << actual->dpi << " -> ";
            actual = actual->siguiente;
        }

        cout << endl;
    }
}