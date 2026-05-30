#include "../include/Utilidades.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// ===============================
// LIMPIAR PANTALLA
// ===============================
void limpiarPantalla() {
    system("cls");
}

// ===============================
// PAUSA DEL SISTEMA
// ===============================
void pausa() {
    system("pause");
}

// ===============================
// MOSTRAR TITULO
// ===============================
void mostrarTitulo(string titulo) {

    cout << "\n======================================" << endl;
    cout << titulo << endl;
    cout << "======================================\n" << endl;
}