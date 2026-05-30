#include "../include/Utilidades.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// ===============================
// LIMPIAR PANTALLA
// ===============================
// Borra todo el contenido visible
// de la consola.
//
// Se utiliza para mantener el menú
// más ordenado durante la ejecución.
// ===============================
void limpiarPantalla() {
    system("cls");
}

// ===============================
// PAUSA DEL SISTEMA
// ===============================
// Detiene la ejecución hasta que
// el usuario presione una tecla.
//
// Permite leer información antes
// de continuar.
// ===============================
void pausa() {
    system("pause");
}

// ===============================
// MOSTRAR TITULO
// ===============================
// Muestra encabezados decorativos
// para organizar visualmente los
// distintos módulos del sistema.
// ===============================
void mostrarTitulo(string titulo) {

    cout << "\n======================================" << endl;
    cout << titulo << endl;
    cout << "======================================\n" << endl;
}