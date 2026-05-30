#include "HashPacientes.h"
#include <iostream>
#include <new>
#include <cctype>

using namespace std;

// =============================================
// FUNCION AUXILIAR: VALIDAR DPI
// =============================================
// Valida que el DPI tenga exactamente 13 dígitos.
// =============================================
bool validarDpiHash(const string& dpi) {
    if (dpi.length() != 13) {
        return false;
    }

    for (char c : dpi) {
        if (!isdigit((unsigned char)c)) {
            return false;
        }
    }

    return true;
}

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
// Nota: no elimina el objeto Paciente porque
// ese se libera en ListaPacientes.
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
// Validaciones:
// - DPI válido de 13 dígitos.
// - Paciente no nulo.
// - Evita DPI duplicado.
// - Maneja error de memoria.
// =============================================
void HashPacientes::insertar(string dpi, Paciente* paciente) {

    if (!validarDpiHash(dpi)) {
        cout << "Error: DPI invalido para insertar en tabla hash." << endl;
        return;
    }

    if (paciente == nullptr) {
        cout << "Error: paciente nulo, no se puede insertar en tabla hash." << endl;
        return;
    }

    if (buscar(dpi) != nullptr) {
        cout << "Error: ya existe un paciente con ese DPI en la tabla hash." << endl;
        return;
    }

    int indice = funcionHash(dpi);

    NodoHash* nuevo = nullptr;

    try {
        nuevo = new NodoHash(dpi, paciente);
    }
    catch (bad_alloc&) {
        cout << "Error: no se pudo reservar memoria para el nodo hash." << endl;
        return;
    }

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

    if (!validarDpiHash(dpi)) {
        return nullptr;
    }

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