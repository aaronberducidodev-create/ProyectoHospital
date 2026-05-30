#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>

using namespace std;

// ===============================
// NODO DEL ARBOL B
// ===============================
// Representa un nodo que almacena
// múltiples claves.
//
// Esta implementación simplificada
// utiliza un arreglo para guardar
// hasta 10 valores.
// ===============================

class NodoB {
public:

    // Arreglo donde se almacenan las claves
    int claves[10];

    // Cantidad actual de claves almacenadas
    int cantidad;

    // Constructor
    NodoB();

    // Inserta una nueva clave
    void insertar(int valor);

    // Muestra las claves almacenadas
    void mostrar();

    // Reinicia el contenido del nodo
    void limpiar();
};

// ===============================
// ARBOL B
// ===============================
// Estructura utilizada para almacenar
// múltiples valores de forma organizada.
//
// En esta versión académica se utiliza
// un único nodo raíz.
// ===============================

class ArbolB {
private:

    // Nodo raíz del árbol
    NodoB raiz;

public:

    // Constructor
    ArbolB();

    // Inserta una clave en el árbol
    void insertar(int valor);

    // Muestra el contenido del árbol
    void mostrar();

    // Limpia los datos almacenados
    void limpiar();
};

#endif