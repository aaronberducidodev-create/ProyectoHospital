#ifndef GRAFOHOSPITAL_H
#define GRAFOHOSPITAL_H

#include <iostream>
using namespace std;

class NodoAdyacente {
public:
    int destino;
    int peso;
    NodoAdyacente* siguiente;

    NodoAdyacente(int destino, int peso);
};

class GrafoHospital {
private:
    static const int NUM_AREAS = 5;
    NodoAdyacente* lista[NUM_AREAS];

    string nombres[NUM_AREAS];

    void dfsRecursivo(int area, bool visitado[]);

public:
    GrafoHospital();
    ~GrafoHospital();

    void agregarRuta(int origen, int destino, int peso);
    void mostrarGrafo();

    void BFS(int inicio);
    void DFS(int inicio);
    void dijkstra(int inicio);
};

#endif