#include "../include/SistemaHospital.h"

// Función principal del programa.
// Es el punto de entrada donde inicia la ejecución del sistema hospitalario.
int main() {

    // Se crea un objeto de la clase SistemaHospital.
    // Este objeto será el encargado de controlar todas las operaciones del sistema.
    SistemaHospital sistema;

    // Llama al método iniciar().
    // Aquí se ejecuta el menú principal y la lógica general del sistema.
    sistema.iniciar();

    // Indica que el programa terminó correctamente.
    return 0;
}