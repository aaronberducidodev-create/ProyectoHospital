#ifndef CONEXIONMYSQL_H
#define CONEXIONMYSQL_H

#include <string>
#include "../models/ListaPacientes.h"
#include "../models/ArbolB.h"

using namespace std;

class ConexionMySQL {
public:
    ConexionMySQL();

    bool conectar();

    // ===============================
    // PACIENTES
    // ===============================
    void insertarPaciente(long long id, string nombre, int edad, string dpi);
    void mostrarPacientes();
    void eliminarPaciente(long long id);
    void actualizarPaciente(long long id, string nombre, int edad, string dpi);
    void cargarPacientesDesdeMySQL(ListaPacientes &lista);
    void cargarIdsPacientesEnArbolB(ArbolB &arbolB);

    // ===============================
    // CITAS
    // ===============================
    void insertarCita(
        int id,
        long long paciente_id,
        string fecha,
        string hora,
        string doctor,
        string motivo
    );

    void mostrarCitas();

    void actualizarCita(
        int id,
        long long paciente_id,
        string fecha,
        string hora,
        string doctor,
        string motivo
    );

    void eliminarCita(int id);
};

#endif
