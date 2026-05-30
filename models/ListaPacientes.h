#ifndef LISTAPACIENTES_H
#define LISTAPACIENTES_H

#include "Paciente.h"

// =============================================
// LISTA SIMPLE DE PACIENTES
// =============================================
// Gestiona todos los pacientes registrados
// utilizando una lista simplemente enlazada.
//
// Cada paciente apunta al siguiente mediante
// el puntero 'siguiente'.
// =============================================
class ListaPacientes {
private:

    // Primer paciente de la lista
    Paciente* cabeza;

 public:

   // =============================================
   // CONSTRUCTOR
   // =============================================
   // Inicializa la lista vacía.
   // =============================================
   ListaPacientes();
   
   // =============================================
   // DESTRUCTOR
   // =============================================
   // Libera la memoria utilizada por todos
   // los pacientes almacenados en la lista.
   // Evita fugas de memoria.
   // =============================================
   ~ListaPacientes();

   // =============================================
   // OPERACIONES BÁSICAS
   // =============================================
   // Permiten insertar, buscar y eliminar
   // pacientes dentro de la lista enlazada.
   // =============================================

   /*
   void insertarPaciente(int id, string nombre, int edad, string dpi);
   Paciente* buscarPaciente(int id);
   bool eliminarPaciente(int id);
   */

   // Agrega un nuevo paciente a la lista
   void insertarPaciente(long long id, string nombre, int edad, string dpi);

   // Busca un paciente utilizando su ID
   Paciente* buscarPaciente(long long id);

   // Elimina un paciente por ID
   bool eliminarPaciente(long long id);

   // Muestra todos los pacientes registrados
   void mostrarPacientes();

   // =============================================
   // ACCESO A LA LISTA
   // =============================================
   // Devuelve el primer nodo para recorrer
   // la lista desde otras clases del sistema.
   // =============================================
   Paciente* getCabeza();

   // =============================================
   // VERIFICACIÓN
   // =============================================
   // Indica si la lista contiene pacientes
   // o se encuentra vacía.
   // =============================================
   bool estaVacia();

};

#endif