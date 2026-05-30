#include "ConexionMySQL.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

ConexionMySQL::ConexionMySQL() {
}

bool ConexionMySQL::conectar() {
    cout << "Conexion preparada mediante PHP + XAMPP." << endl;
    return true;
}

// ===============================
// PACIENTES
// ===============================

void ConexionMySQL::insertarPaciente(long long id, string nombre, int edad, string dpi) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "--data-urlencode \"nombre=" + nombre + "\" "
        "-d \"edad=" + to_string(edad) + "\" "
        "-d \"dpi=" + dpi + "\" "
        "http://localhost/hospital_api/insertar_paciente.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::mostrarPacientes() {
    cout << "Pacientes registrados en MySQL:" << endl;

    string comando =
        "curl.exe http://localhost/hospital_api/mostrar_pacientes.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::eliminarPaciente(long long id) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "http://localhost/hospital_api/eliminar_paciente.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::actualizarPaciente(long long id, string nombre, int edad, string dpi) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "--data-urlencode \"nombre=" + nombre + "\" "
        "-d \"edad=" + to_string(edad) + "\" "
        "-d \"dpi=" + dpi + "\" "
        "http://localhost/hospital_api/update_paciente.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::cargarPacientesDesdeMySQL(ListaPacientes &lista) {
    system("curl.exe http://localhost/hospital_api/obtener_pacientes.php > data.txt");

    ifstream archivo("data.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir data.txt" << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);

        string idStr, nombre, edadStr, dpi;

        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, dpi, '|');

        if (idStr == "" || nombre == "" || edadStr == "" || dpi == "") {
            continue;
        }

        try {
            long long id = stoll(idStr);
            int edad = stoi(edadStr);

            if (lista.buscarPaciente(id) == nullptr) {
                lista.insertarPaciente(id, nombre, edad, dpi);
            }
        }
        catch (...) {
            cout << "Error al cargar paciente desde MySQL. Datos invalidos." << endl;
        }
    }

    archivo.close();

    cout << "Pacientes cargados desde MySQL correctamente." << endl;
}

// ===============================
// CITAS
// ===============================

void ConexionMySQL::insertarCita(
    int id,
    long long paciente_id,
    string fecha,
    string hora,
    string doctor,
    string motivo
) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "-d \"paciente_id=" + to_string(paciente_id) + "\" "
        "-d \"fecha=" + fecha + "\" "
        "--data-urlencode \"hora=" + hora + "\" "
        "--data-urlencode \"doctor=" + doctor + "\" "
        "--data-urlencode \"motivo=" + motivo + "\" "
        "http://localhost/hospital_api/insertar_cita.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::mostrarCitas() {
    cout << "Citas registradas en MySQL:" << endl;

    string comando =
        "curl.exe http://localhost/hospital_api/mostrar_citas.php";

    system(comando.c_str());
    cout << endl;
}

void ConexionMySQL::cargarIdsPacientesEnArbolB(ArbolB &arbolB) {
    system("curl.exe http://localhost/hospital_api/obtener_ids_pacientes.php > data/ids_pacientes.txt");

    ifstream archivo("data/ids_pacientes.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir data/ids_pacientes.txt" << endl;
        return;
    }

    string linea;

    arbolB.limpiar();

    while (getline(archivo, linea)) {
        if (linea != "") {
            try {
                int id = stoi(linea);
                arbolB.insertar(id);
            }
            catch (...) {
                cout << "ID invalido encontrado al cargar Arbol B." << endl;
            }
        }
    }

    archivo.close();

    cout << "IDs cargados desde MySQL al Arbol B correctamente." << endl;
}

// Actualizar cita en MySQL usando PHP + curl.exe
void ConexionMySQL::actualizarCita(
    int id,
    long long paciente_id,
    string fecha,
    string hora,
    string doctor,
    string motivo
) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "-d \"paciente_id=" + to_string(paciente_id) + "\" "
        "-d \"fecha=" + fecha + "\" "
        "--data-urlencode \"hora=" + hora + "\" "
        "--data-urlencode \"doctor=" + doctor + "\" "
        "--data-urlencode \"motivo=" + motivo + "\" "
        "http://localhost/hospital_api/update_cita.php";

    system(comando.c_str());
    cout << endl;
}

// Eliminar cita en MySQL usando PHP + curl.exe
void ConexionMySQL::eliminarCita(int id) {
    string comando =
        "curl.exe -X POST "
        "-d \"id=" + to_string(id) + "\" "
        "http://localhost/hospital_api/eliminar_cita.php";

    system(comando.c_str());
    cout << endl;
}