#include "../include/SistemaHospital.h"
#include "../database/ConexionMySQL.h"
#include "../include/Utilidades.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream> //  NUEVO: sirve para separar datos con |
#include <vector>
#include <cctype> // NUEVO: valida si un caracter es digito


// =============================================
// CONSTRUCTOR DEL SISTEMA HOSPITALARIO
// =============================================
// Al iniciar el sistema:
// 1. Obtiene pacientes desde PHP/MySQL.
// 2. Carga los pacientes en memoria.
// 3. Inserta los pacientes en Lista, BST, AVL y Hash.
// 4. Crea las rutas iniciales del hospital para el grafo.
// =============================================


using namespace std;


// =============================================
// FUNCIONES DE VALIDACION
// =============================================
// Estas funciones ayudan a evitar errores cuando
// el usuario ingresa datos con formato incorrecto.
// =============================================

bool esNumero(const string& texto) {
    if (texto.empty()) {
        return false;
    }

    for (char c : texto) {
        if (!isdigit((unsigned char)c)) {
            return false;
        }
    }

    return true;
}

bool edadValida(int edad) {
    return edad >= 0 && edad <= 120;
}

bool dpiValido(const string& dpi) {
    bool dpiValido = true;

    if (dpi.length() != 13) {
        dpiValido = false;
    }

    for (char c : dpi) {
        if (!isdigit((unsigned char)c)) {
            dpiValido = false;
            break;
        }
    }

    return dpiValido;
}

bool fechaValida(const string& fecha) {
    // Formato esperado: YYYY-MM-DD
    if (fecha.length() != 10) {
        return false;
    }

    if (fecha[4] != '-' || fecha[7] != '-') {
        return false;
    }

    string anio = fecha.substr(0, 4);
    string mes = fecha.substr(5, 2);
    string dia = fecha.substr(8, 2);

    if (!esNumero(anio) || !esNumero(mes) || !esNumero(dia)) {
        return false;
    }

    int mesNumero = stoi(mes);
    int diaNumero = stoi(dia);

    if (mesNumero < 1 || mesNumero > 12) {
        return false;
    }

    if (diaNumero < 1 || diaNumero > 31) {
        return false;
    }

    return true;
}


// =============================================
// MENU PRINCIPAL DEL SISTEMA
// =============================================
// Desde aquí se accede a todos los módulos:
// Pacientes, Citas, Emergencias,
// Estructuras de Datos, Grafos y MySQL.
// =============================================


SistemaHospital::SistemaHospital() {

    system("curl http://localhost/hospital_api/obtener_pacientes.php > data/pacientes.txt");

    ifstream archivo("data/pacientes.txt");

    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);

        string idStr, nombre, edadStr, dpi;

        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, dpi, '|');

        if (idStr != "" && nombre != "" && edadStr != "" && dpi != "") {

            try {
                int id = stoi(idStr);
                int edad = stoi(edadStr);

                if (!edadValida(edad)) {
                    cout << "Edad fuera de rango al cargar paciente desde MySQL/TXT." << endl;
                    continue;
                }

                if (!dpiValido(dpi)) {
                    cout << "DPI invalido al cargar paciente desde MySQL/TXT." << endl;
                    continue;
                }

                listaPacientes.insertarPaciente(id, nombre, edad, dpi);

                Paciente* p = listaPacientes.buscarPaciente(id);

                if (p != nullptr) {
                    arbolBST.insertar(p);
                    arbolAVL.insertar(p);
                    hashPacientes.insertar(dpi, p);
                }
            }
            catch (...) {
                cout << "Error al cargar paciente desde MySQL/TXT. Datos invalidos." << endl;
            }
        }
    }

    archivo.close();

    grafo.agregarRuta(0, 1, 4);
    grafo.agregarRuta(0, 2, 2);
    grafo.agregarRuta(1, 3, 5);
    grafo.agregarRuta(2, 3, 1);
    grafo.agregarRuta(3, 4, 3);
}
void SistemaHospital::iniciar() {
    int opcion;

    do {
        cout << "\n===== SISTEMA INTELIGENTE DE GESTION HOSPITALARIA =====" << endl;
        cout << "1. Gestion de pacientes" << endl;
        cout << "2. Emergencias" << endl;
        cout << "3. Citas medicas" << endl;
        cout << "4. Estructuras de datos" << endl;
        cout << "5. Mapa y memoria del hospital" << endl;
        cout << "6. Mostrar desde Base de Datos" << endl;
        cout << "7. Arbol de expresiones - Facturacion" << endl;
        cout << "8. Demostracion de Polimorfismo" << endl;
        cout << "9. Arbol B - Indice de pacientes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        switch (opcion) {

            case 1:
                menuPacientes();
                break;

            case 2:
                menuEmergencias();
                break;

            case 3:
                menuCitas();
                break;

            case 4:
                menuEstructuras();
                break;

            case 5:
                menuHospital();
                break;

            // ===============================
            // OPCION 6: MYSQL
            // ===============================
            // Muestra los pacientes y citas guardados
            // en MySQL mediante PHP + XAMPP.
            case 6:
                conexion.conectar();

                cout << "\n--- PACIENTES EN MYSQL ---" << endl;
                conexion.mostrarPacientes();

                cout << "\n--- CITAS EN MYSQL ---" << endl;
                conexion.mostrarCitas();

                break;

            
            // ===============================
            // OPCION 7: ARBOL DE EXPRESIONES
            // ===============================
            // Demuestra el calculo de facturacion:
            // (CostoConsulta + Medicamentos) * IVA
            case 7:
                arbolExpresiones.construirArbol();

                cout << "\n===== ARBOL DE EXPRESIONES - FACTURACION =====" << endl;
                cout << "Formula: (CostoConsulta + Medicamentos) * IVA" << endl;
                cout << "Ejemplo: (500 + 250) * 1.12" << endl;
                cout << "Total a pagar: Q"
                     << arbolExpresiones.evaluarExpresion()
                     << endl;

                break;

            // ===============================
            // OPCION 8: HERENCIA Y POLIMORFISMO
            // ===============================
            // Herencia:
            // Paciente hereda de Persona.
            //
            // Polimorfismo:
            // Un puntero de tipo Persona apunta a un objeto Paciente.
            // Al llamar mostrar(), se ejecuta el metodo mostrar()
            // sobrescrito en la clase Paciente.
            case 8: {
                cout << "\n===== DEMOSTRACION DE POLIMORFISMO =====" << endl;
                cout << "Clase padre: Persona" << endl;
                cout << "Clase hija: Paciente" << endl;

                // Se busca un paciente real que ya fue cargado
                // desde MySQL hacia la lista de pacientes.
                Paciente* paciente = listaPacientes.buscarPaciente(1001);

                if (paciente != nullptr) {
                    // Puntero de la clase padre apuntando
                    // a un objeto de la clase hija.
                    Persona* persona = paciente;

                    cout << "\nPaciente obtenido desde MySQL y memoria:" << endl;
                    cout << "Se ejecuta persona->mostrar(), pero responde Paciente::mostrar().\n" << endl;

                    persona->mostrar();
                } else {
                    cout << "Paciente no encontrado en memoria." << endl;
                    cout << "Verifique que Apache y MySQL esten activos y que exista el paciente 1001." << endl;
                }

                break;
            }

            // ===============================
            // OPCION 9: ARBOL B
            // ===============================
            // Carga los IDs reales de pacientes desde MySQL
            // y los inserta en el Arbol B como indice.
            case 9:
                conexion.cargarIdsPacientesEnArbolB(arbolB);

                cout << "\n===== ARBOL B - INDICE DE PACIENTES =====" << endl;
                cout << "IDs cargados desde MySQL:" << endl;

                arbolB.mostrar();

                break;

            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);
}


// =============================================
// GESTION DE PACIENTES
// =============================================
// Permite:
// - Registrar pacientes
// - Consultar pacientes
// - Eliminar pacientes
// - Historial médico
// - Exportar información
// =============================================

void SistemaHospital::menuPacientes() {
    int opcion;

    do {
        cout << "\n===== GESTION DE PACIENTE =====" << endl;
        cout << "1. Registrar nuevo paciente" << endl;
        cout << "2. Mostrar pacientes" << endl;
        cout << "3. Consultar paciente por ID" << endl;
        cout << "4. Eliminar registro de paciente" << endl;
        cout << "5. Registrar historial medico" << endl;
        cout << "6. Consultar historial medico" << endl;
        cout << "7. Modificar datos del Paciente" << endl;
        cout << "8. Exportar pacientes a CSV para Excel" << endl;
        cout << "0. Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        if (opcion == 1) {
            long long id;
            int edad;
            string nombre, dpi;

            cout << "ID: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            if (listaPacientes.buscarPaciente(id) != nullptr) {
                cout << "Ya existe un paciente con ese ID." << endl;
                continue;
            }

            cin.ignore();

            cout << "Nombre: ";
            getline(cin, nombre);

            cout << "Edad: ";
            cin >> edad;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Edad invalida. Ingrese solo numeros." << endl;
                continue;
            }

            if (!edadValida(edad)) {
                cout << "Edad fuera de rango. Debe estar entre 0 y 120." << endl;
                continue;
            }

            cout << "DPI: ";
            cin >> dpi;

            if (!dpiValido(dpi)) {
                cout << "DPI invalido. Debe contener exactamente 13 digitos." << endl;
                continue;
            }

            listaPacientes.insertarPaciente(id, nombre, edad, dpi);

            Paciente* paciente = listaPacientes.buscarPaciente(id);

            arbolBST.insertar(paciente);
            arbolAVL.insertar(paciente);
            hashPacientes.insertar(dpi, paciente);

            conexion.insertarPaciente(id, nombre, edad, dpi);

            cout << "\nPaciente registrado correctamente." << endl;
            cout << "===== REGISTRO AGREGADO =====" << endl;

            if (paciente != nullptr) {
                paciente->mostrar();
            } else {
                cout << "ID: " << id << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Edad: " << edad << endl;
                cout << "DPI: " << dpi << endl;
            }

            cout << "=============================" << endl;
        }

        else if (opcion == 2) {
    listaPacientes.mostrarPacientes();

    // =========================================
    // NUEVO:
    // VECTOR DE EDADES
    // Se usa vector para almacenar edades
    // y generar estadisticas.
    // =========================================

    vector<int> edades;

    Paciente* actual = listaPacientes.getCabeza();

    while (actual != nullptr) {
        edades.push_back(actual->getEdad());
        actual = actual->siguiente;
    }

    if (!edades.empty()) {
        int suma = 0;
        int mayor = edades[0];
        int menor = edades[0];

        for (int edad : edades) {
            suma += edad;

            if (edad > mayor) {
                mayor = edad;
            }

            if (edad < menor) {
                menor = edad;
            }
        }

       // =============================================
       // ORDENAMIENTO BURBUJA (BUBBLE SORT)
       // =============================================
       // Ordena las edades de menor a mayor.
       // Se utiliza únicamente para mostrar
       // estadísticas ordenadas.
       // =============================================

        for (int i = 0; i < edades.size() - 1; i++) {

            for (int j = 0; j < edades.size() - i - 1; j++) {

                if (edades[j] > edades[j + 1]) {

                    int temp = edades[j];
                    edades[j] = edades[j + 1];
                    edades[j + 1] = temp;
                }
            }
        }

        double promedio = (double)suma / edades.size();

        cout << "\n===== ESTADISTICAS CON VECTOR =====" << endl;

        cout << "Cantidad de pacientes: "
             << edades.size()
             << endl;

        cout << "Edad promedio: "
             << promedio
             << endl;

        cout << "Edad mayor: "
             << mayor
             << endl;

        cout << "Edad menor: "
             << menor
             << endl;

        // =========================================
        // NUEVO:
        // Mostrar edades ordenadas
        // =========================================

        cout << "Edades ordenadas: ";

        for (int edad : edades) {
            cout << edad << " ";
        }

        cout << endl;
    }
}

        else if (opcion == 3) {
            long long id;

            cout << "Ingrese ID: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            Paciente* paciente = listaPacientes.buscarPaciente(id);

            if (paciente != nullptr) {
                paciente->mostrar();
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

        else if (opcion == 4) {
            long long id;

            cout << "Ingrese ID a eliminar: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            if (listaPacientes.eliminarPaciente(id)) {
                cout << "Paciente eliminado de la lista." << endl;
                conexion.eliminarPaciente(id);
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

        else if (opcion == 5) {
            long long id;
            string diagnostico, tratamiento, fecha;

            cout << "Ingrese ID del paciente: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            Paciente* paciente = listaPacientes.buscarPaciente(id);

            if (paciente != nullptr) {
                cin.ignore();

                cout << "Diagnostico: ";
                getline(cin, diagnostico);

                cout << "Tratamiento: ";
                getline(cin, tratamiento);

                cout << "Fecha: ";
                getline(cin, fecha);

                paciente->agregarHistorial(diagnostico, tratamiento, fecha);

                cout << "Historial agregado correctamente." << endl;
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

        else if (opcion == 6) {
            long long id;

            cout << "Ingrese ID del paciente: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            Paciente* paciente = listaPacientes.buscarPaciente(id);

            if (paciente != nullptr) {
                paciente->mostrarHistorial();
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

        else if (opcion == 7) {
            long long id;
            string nuevoNombre, nuevoDpi;
            int nuevaEdad;

            cout << "Ingrese ID del paciente a editar: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            Paciente* paciente = listaPacientes.buscarPaciente(id);

            if (paciente != nullptr) {
                cin.ignore();

                cout << "Nuevo nombre: ";
                getline(cin, nuevoNombre);

                cout << "Nueva edad: ";
                cin >> nuevaEdad;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Edad invalida. Ingrese solo numeros." << endl;
                    continue;
                }

                if (!edadValida(nuevaEdad)) {
                    cout << "Edad fuera de rango. Debe estar entre 0 y 120." << endl;
                    continue;
                }

                cout << "Nuevo DPI: ";
                cin >> nuevoDpi;

                if (!dpiValido(nuevoDpi)) {
                    cout << "DPI invalido. Debe contener exactamente 13 digitos." << endl;
                    continue;
                }

                conexion.actualizarPaciente(id, nuevoNombre, nuevaEdad, nuevoDpi);

                cout << "Paciente actualizado en MySQL correctamente." << endl;
                cout << "IMPORTANTE: reinicia el programa para ver los cambios en memoria." << endl;
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

      else if (opcion == 8) {
    // =========================================
    // EXPORTAR PACIENTES A CSV
    // =========================================
    // CSV significa Comma Separated Values.
    // Este formato se puede abrir directamente
    // en Microsoft Excel o Google Sheets.
    // =========================================

    ofstream archivo("data/pacientes_exportados.csv");

    if (!archivo.is_open()) {
        cout << "Error al crear archivo CSV de pacientes." << endl;
        continue;
    }

    Paciente* actual = listaPacientes.getCabeza();

    // Encabezados para Excel
    archivo << "ID,Nombre,Edad,DPI\n";

    if (actual == nullptr) {
        cout << "No hay pacientes registrados para exportar." << endl;
    }

    while (actual != nullptr) {
        archivo << actual->getId() << ","
                << actual->getNombre() << ","
                << actual->getEdad() << ","
                << actual->getDpi()
                << "\n";

        actual = actual->siguiente;
    }

    archivo.close();

    cout << "Pacientes exportados correctamente en data/pacientes_exportados.csv" << endl;
}


    } while (opcion != 0);


    
}


// =============================================
// COLA DE EMERGENCIAS
// =============================================
// Implementa una estructura FIFO.
// Los pacientes son atendidos según
// el orden de llegada y prioridad.
// =============================================

void SistemaHospital::menuEmergencias() {
    int opcion;

    do {
        cout << "\n====================================\n";
        cout << "===== COLA DE EMERGENCIAS =====" << endl;
        cout << "====================================\n";

        cout << "1. Encolar paciente" << endl;
        cout << "2. Atender paciente" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "0. Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        // =========================================
        // ENCOLAR PACIENTE EN EMERGENCIAS
        // =========================================
        if (opcion == 1) {

            long long id;
            int prioridad;

            cout << "Ingrese ID del paciente: ";
            cin >> id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID invalido. Ingrese solo numeros." << endl;
                continue;
            }

            // Buscar paciente en la lista general
            Paciente* paciente = listaPacientes.buscarPaciente(id);

            if (paciente != nullptr) {

                // =========================================
                // SISTEMA DE TRIAJE
                // =========================================
                // 1 = Critico
                // 2 = Urgente
                // 3 = Normal
                // =========================================
                cout << "\n===== PRIORIDAD DE EMERGENCIA =====" << endl;
                cout << "1. Critico" << endl;
                cout << "2. Urgente" << endl;
                cout << "3. Normal" << endl;
                cout << "Seleccione prioridad: ";
                cin >> prioridad;

                // VALIDIACION
                
                if (cin.fail() || prioridad < 1 || prioridad > 3) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Prioridad invalida." << endl;
                    continue;
                }

                // Guardar prioridad en el paciente
                paciente->setPrioridad(prioridad);

                // Agregar paciente a la cola
                colaEmergencias.encolar(paciente);

                cout << "Paciente agregado a emergencia." << endl;

            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

        // =========================================
        // ATENDER PACIENTE
        // =========================================
        else if (opcion == 2) {

            Paciente* paciente = colaEmergencias.desencolar();

            if (paciente != nullptr) {

                cout << "\nPaciente atendido:" << endl;

                paciente->mostrar();

                cout << "Prioridad: "
                     << paciente->getPrioridad()
                     << endl;

            } else {
                cout << "No hay pacientes en emergencia." << endl;
            }
        }

        // =========================================
        // MOSTRAR COLA DE EMERGENCIAS
        // =========================================
        else if (opcion == 3) {
            colaEmergencias.mostrarCola();
        }

    } while (opcion != 0);
}



// =============================================
// GESTION DE CITAS MEDICAS
// =============================================
// Permite registrar, buscar,
// modificar y eliminar citas.
// =============================================

void SistemaHospital::menuCitas() {
    int opcion;

    do {
        cout << "\n===== CITAS MEDICAS =====" << endl;
        cout << "1. Registrar cita" << endl;
        cout << "2. Mostrar citas hacia adelante" << endl;
        cout << "3. Mostrar citas hacia atras" << endl;
        cout << "4. Buscar cita" << endl;
        cout << "5. Eliminar cita" << endl;
        cout << "6. Modificar cita" << endl;
        cout << "0. Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        if (opcion == 1) {
            int idCita;
            long long idPaciente;
            string doctor, fecha, hora, motivo;

            cout << "ID Cita: ";
            cin >> idCita;


            // Validar que el usuario ingrese un ID numérico válido.
            // Si ocurre un error en la entrada, se limpia el flujo
            // y se solicita nuevamente el dato.
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de cita invalido." << endl;
                continue;
            }

            cout << "ID Paciente: ";
            cin >> idPaciente;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de paciente invalido." << endl;
                continue;
            }

            cin.ignore();

            cout << "Doctor: ";
            getline(cin, doctor);

            cout << "Fecha (YYYY-MM-DD): ";
            getline(cin, fecha);

            if (!fechaValida(fecha)) {
                cout << "Fecha invalida. Use formato YYYY-MM-DD." << endl;
                continue;
            }

            cout << "Hora: ";
            getline(cin, hora);

            cout << "Motivo: ";
            getline(cin, motivo);

            listaCitas.insertarCita(idCita, idPaciente, doctor, fecha, hora, motivo);
            conexion.insertarCita(idCita, idPaciente, fecha, hora, doctor, motivo);

            cout << "\nCita registrada correctamente." << endl;
            cout << "===== REGISTRO AGREGADO =====" << endl;

            Cita* citaAgregada = listaCitas.buscarCita(idCita);

            if (citaAgregada != nullptr) {
                citaAgregada->mostrar();
            } else {
                cout << "ID Cita: " << idCita << endl;
                cout << "ID Paciente: " << idPaciente << endl;
                cout << "Doctor: " << doctor << endl;
                cout << "Fecha: " << fecha << endl;
                cout << "Hora: " << hora << endl;
                cout << "Motivo: " << motivo << endl;
            }

            cout << "=============================" << endl;
        }

        else if (opcion == 2) {
            listaCitas.mostrarAdelante();
        }

        else if (opcion == 3) {
            listaCitas.mostrarAtras();
        }

        else if (opcion == 4) {
            int idCita;

            cout << "Ingrese ID de cita: ";
            cin >> idCita;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de cita invalido." << endl;
                continue;
            }

            Cita* cita = listaCitas.buscarCita(idCita);

            if (cita != nullptr) {
                cita->mostrar();
            } else {
                cout << "Cita no encontrada." << endl;
            }
        }

        else if (opcion == 5) {
            int idCita;

            cout << "Ingrese ID de cita a eliminar: ";
            cin >> idCita;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de cita invalido." << endl;
                continue;
            }

            if (listaCitas.eliminarCita(idCita)) {
                conexion.eliminarCita(idCita);
                cout << "Cita eliminada correctamente." << endl;
            } else {
                cout << "Cita no encontrada en memoria." << endl;
                cout << "Intentando eliminar tambien en MySQL..." << endl;
                conexion.eliminarCita(idCita);
            }
        }

        else if (opcion == 6) {
            int idCita;
            long long idPaciente;
            string doctor, fecha, hora, motivo;

            cout << "ID de cita a modificar: ";
            cin >> idCita;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de cita invalido." << endl;
                continue;
            }

            cout << "Nuevo ID Paciente: ";
            cin >> idPaciente;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ID de paciente invalido." << endl;
                continue;
            }

            cin.ignore();

            cout << "Nuevo doctor: ";
            getline(cin, doctor);

            cout << "Nueva fecha (YYYY-MM-DD): ";
            getline(cin, fecha);

            if (!fechaValida(fecha)) {
                cout << "Fecha invalida. Use formato YYYY-MM-DD." << endl;
                continue;
            }

            cout << "Nueva hora: ";
            getline(cin, hora);

            cout << "Nuevo motivo: ";
            getline(cin, motivo);

            conexion.actualizarCita(
                idCita,
                idPaciente,
                fecha,
                hora,
                doctor,
                motivo
            );

            cout << "Cita actualizada en MySQL correctamente." << endl;
            cout << "IMPORTANTE: reinicia el programa para ver cambios en memoria." << endl;
        }

    } while (opcion != 0);
}

// =============================================
// ESTRUCTURAS DE DATOS AVANZADAS
// =============================================
// Demostración de:
// - Árbol BST
// - Árbol AVL
// - Tabla Hash
// =============================================

void SistemaHospital::menuEstructuras() {
    int opcion;

    do {
        cout << "\n===== ESTRUCTURAS DE DATOS =====" << endl;
        cout << "1. Mostrar BST pacientes InOrden" << endl;
        cout << "2. Mostrar BST pacientes PreOrden" << endl;
        cout << "3. Mostrar BST pacientes PostOrden" << endl;
        cout << "4. Mostrar AVL por edades" << endl;
        cout << "5. Mostrar tabla Hash" << endl;
        cout << "6. Buscar paciente por DPI" << endl;
        cout << "0. Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        if (opcion == 1) {
            arbolBST.mostrarInOrden();
        }
        else if (opcion == 2) {
            arbolBST.mostrarPreOrden();
        }
        else if (opcion == 3) {
            arbolBST.mostrarPostOrden();
        }
        else if (opcion == 4) {
            arbolAVL.mostrarInOrden();
        }
        else if (opcion == 5) {
            hashPacientes.mostrarTabla();
        }
        else if (opcion == 6) {
            string dpi;

            cout << "Ingrese DPI: ";
            cin >> dpi;

            if (!dpiValido(dpi)) {
                cout << "DPI invalido. Debe contener exactamente 13 digitos." << endl;
                continue;
            }

            Paciente* paciente = hashPacientes.buscar(dpi);

            if (paciente != nullptr) {
                paciente->mostrar();
            } else {
                cout << "Paciente no encontrado." << endl;
            }
        }

    } while (opcion != 0);
}

// =============================================
// MAPA Y MEMORIA DEL HOSPITAL
// =============================================
// Demuestra algoritmos:
// - BFS
// - DFS
// - Dijkstra // Sirve para encontrar la ruta más corta entre un punto y los demás puntos de un grafo.
//
// También incluye simulación de
// administración de memoria.
// =============================================

void SistemaHospital::menuHospital() {
    int opcion;

    do {
        cout << "\n===== MAPA Y MEMORIA DEL HOSPITAL =====" << endl;
        cout << "1. Mostrar mapa del hospital" << endl;
        cout << "2. BFS desde Emergencias" << endl;
        cout << "3. DFS desde Emergencias" << endl;
        cout << "4. Dijkstra desde Emergencias" << endl;
        cout << "5. Mostrar memoria" << endl;
        cout << "6. Primer ajuste" << endl;
        cout << "7. Mejor ajuste" << endl;
        cout << "8. Peor ajuste" << endl;
        cout << "9. Liberar bloque" << endl;
        cout << "0. Regresar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. Ingrese solo numeros." << endl;
            continue;
        }

        if (opcion == 1) {
            grafo.mostrarGrafo();
        }
        else if (opcion == 2) {
            grafo.BFS(0);
        }
        else if (opcion == 3) {
            grafo.DFS(0);
        }
        else if (opcion == 4) {
            grafo.dijkstra(0);
        }
        else if (opcion == 5) {
            memoria.mostrarMemoria();
        }
        else if (opcion == 6) {
            int tamano;

            cout << "Tamano necesario: ";
            cin >> tamano;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Tamano invalido." << endl;
                continue;
            }

            memoria.primerAjuste(tamano);
        }
        else if (opcion == 7) {
            int tamano;

            cout << "Tamano necesario: ";
            cin >> tamano;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Tamano invalido." << endl;
                continue;
            }

            memoria.mejorAjuste(tamano);
        }
        else if (opcion == 8) {
            int tamano;

            cout << "Tamano necesario: ";
            cin >> tamano;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Tamano invalido." << endl;
                continue;
            }

            memoria.peorAjuste(tamano);
        }
        else if (opcion == 9) {
            int posicion;

            cout << "Bloque a liberar: ";
            cin >> posicion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Posicion invalida." << endl;
                continue;
            }

            memoria.liberarBloque(posicion);
        }

    } while (opcion != 0);
}