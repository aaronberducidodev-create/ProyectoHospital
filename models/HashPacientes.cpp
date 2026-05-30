#include "HashPacientes.h"
#include <iostream>

using namespace std;

NodoHash::NodoHash(string dpi, Paciente* paciente) {
    this->dpi = dpi;
    this->paciente = paciente;
    this->siguiente = nullptr;
}

HashPacientes::HashPacientes() {
    for (int i = 0; i < TAM; i++) {
        tabla[i] = nullptr;
    }
}

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

int HashPacientes::funcionHash(string dpi) {
    int suma = 0;

    for (int i = 0; i < dpi.length(); i++) {
        suma += dpi[i];
    }

    return suma % TAM;
}

void HashPacientes::insertar(string dpi, Paciente* paciente) {
    int indice = funcionHash(dpi);

    NodoHash* nuevo = new NodoHash(dpi, paciente);

    // Encadenamiento: se inserta al inicio de la posición
    nuevo->siguiente = tabla[indice];
    tabla[indice] = nuevo;
}

Paciente* HashPacientes::buscar(string dpi) {
    int indice = funcionHash(dpi);

    NodoHash* actual = tabla[indice];

    while (actual != nullptr) {
        if (actual->dpi == dpi) {
            return actual->paciente;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

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