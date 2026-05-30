#include "Persona.h"

Persona::Persona() {
    id = 0;
    nombre = "";
    edad = 0;
}

Persona::Persona(long long id, string nombre, int edad) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::mostrar() {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

long long Persona::getId() {
    return id;
}

string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

Persona::~Persona() {
}