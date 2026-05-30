#include "Persona.h"

// =============================================
// CONSTRUCTOR POR DEFECTO
// =============================================
// Inicializa una persona con valores
// vacíos o por defecto.
// =============================================
Persona::Persona() {
    id = 0;
    nombre = "";
    edad = 0;
}

// =============================================
// CONSTRUCTOR PARAMETRIZADO
// =============================================
// Permite crear una persona indicando
// ID, nombre y edad.
// =============================================
Persona::Persona(long long id, string nombre, int edad) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
}

// =============================================
// MOSTRAR INFORMACIÓN
// =============================================
// Muestra los datos básicos de una persona.
//
// Este método puede ser sobrescrito por
// clases derivadas como Paciente.
// =============================================
void Persona::mostrar() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

// =============================================
// GETTERS
// =============================================
// Permiten acceder a los atributos privados
// respetando el encapsulamiento.
// =============================================
long long Persona::getId() {
    return id;
}

string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

// =============================================
// SETTERS
// =============================================
// Permiten modificar atributos de la clase.
// =============================================
void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

// =============================================
// DESTRUCTOR
// =============================================
// Se ejecuta automáticamente cuando el
// objeto deja de existir.
// =============================================
Persona::~Persona() {
}