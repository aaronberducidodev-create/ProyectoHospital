#include "../include/GrafoHospital.h"

NodoAdyacente::NodoAdyacente(int destino, int peso) {
    this->destino = destino;
    this->peso = peso;
    this->siguiente = nullptr;
}

GrafoHospital::GrafoHospital() {
    for (int i = 0; i < NUM_AREAS; i++) {
        lista[i] = nullptr;
    }

    nombres[0] = "Emergencias";
    nombres[1] = "Laboratorio";
    nombres[2] = "Rayos X";
    nombres[3] = "Farmacia";
    nombres[4] = "Quirofano";
}

GrafoHospital::~GrafoHospital() {
    for (int i = 0; i < NUM_AREAS; i++) {
        NodoAdyacente* actual = lista[i];

        while (actual != nullptr) {
            NodoAdyacente* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }

        lista[i] = nullptr;
    }
}

void GrafoHospital::agregarRuta(int origen, int destino, int peso) {
    if (origen < 0 || origen >= NUM_AREAS || destino < 0 || destino >= NUM_AREAS) {
        cout << "Area invalida." << endl;
        return;
    }

    NodoAdyacente* nuevo = new NodoAdyacente(destino, peso);
    nuevo->siguiente = lista[origen];
    lista[origen] = nuevo;

    // Ruta bidireccional
    NodoAdyacente* nuevo2 = new NodoAdyacente(origen, peso);
    nuevo2->siguiente = lista[destino];
    lista[destino] = nuevo2;
}

void GrafoHospital::mostrarGrafo() {
    cout << "=== MAPA INTERNO DEL HOSPITAL ===" << endl;

    for (int i = 0; i < NUM_AREAS; i++) {
        cout << nombres[i] << " -> ";

        NodoAdyacente* actual = lista[i];

        while (actual != nullptr) {
            cout << nombres[actual->destino] << "(" << actual->peso << ") ";
            actual = actual->siguiente;
        }

        cout << endl;
    }
}

void GrafoHospital::BFS(int inicio) {
    if (inicio < 0 || inicio >= NUM_AREAS) {
        cout << "Area inicial invalida." << endl;
        return;
    }

    bool visitado[NUM_AREAS] = {false};
    int cola[NUM_AREAS];
    int frente = 0;
    int final = 0;

    visitado[inicio] = true;
    cola[final++] = inicio;

    cout << "Recorrido BFS: ";

    while (frente < final) {
        int actualArea = cola[frente++];
        cout << nombres[actualArea] << " ";

        NodoAdyacente* actual = lista[actualArea];

        while (actual != nullptr) {
            if (!visitado[actual->destino]) {
                visitado[actual->destino] = true;
                cola[final++] = actual->destino;
            }

            actual = actual->siguiente;
        }
    }

    cout << endl;
}

void GrafoHospital::DFS(int inicio) {
    if (inicio < 0 || inicio >= NUM_AREAS) {
        cout << "Area inicial invalida." << endl;
        return;
    }

    bool visitado[NUM_AREAS] = {false};

    cout << "Recorrido DFS: ";
    dfsRecursivo(inicio, visitado);
    cout << endl;
}

void GrafoHospital::dfsRecursivo(int area, bool visitado[]) {
    visitado[area] = true;
    cout << nombres[area] << " ";

    NodoAdyacente* actual = lista[area];

    while (actual != nullptr) {
        if (!visitado[actual->destino]) {
            dfsRecursivo(actual->destino, visitado);
        }

        actual = actual->siguiente;
    }
}

void GrafoHospital::dijkstra(int inicio) {
    if (inicio < 0 || inicio >= NUM_AREAS) {
        cout << "Area inicial invalida." << endl;
        return;
    }

    int distancia[NUM_AREAS];
    bool visitado[NUM_AREAS];

    for (int i = 0; i < NUM_AREAS; i++) {
        distancia[i] = 999999;
        visitado[i] = false;
    }

    distancia[inicio] = 0;

    for (int contador = 0; contador < NUM_AREAS - 1; contador++) {
        int minimo = 999999;
        int indiceMinimo = -1;

        for (int i = 0; i < NUM_AREAS; i++) {
            if (!visitado[i] && distancia[i] <= minimo) {
                minimo = distancia[i];
                indiceMinimo = i;
            }
        }

        if (indiceMinimo == -1) {
            break;
        }

        visitado[indiceMinimo] = true;

        NodoAdyacente* actual = lista[indiceMinimo];

        while (actual != nullptr) {
            int destino = actual->destino;
            int peso = actual->peso;

            if (!visitado[destino] && distancia[indiceMinimo] + peso < distancia[destino]) {
                distancia[destino] = distancia[indiceMinimo] + peso;
            }

            actual = actual->siguiente;
        }
    }

    cout << "=== RUTAS MAS CORTAS DESDE " << nombres[inicio] << " ===" << endl;

    for (int i = 0; i < NUM_AREAS; i++) {
        cout << nombres[inicio] << " -> " << nombres[i]
             << " = " << distancia[i] << endl;
    }
}