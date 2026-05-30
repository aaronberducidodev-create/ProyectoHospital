#ifndef LISTAPACIENTES_H
#define LISTAPACIENTES_H

#include "Paciente.h"

class ListaPacientes {
private:
    Paciente* cabeza;

 public:
   //  Constructor
   ListaPacientes();
   
   //   Destructor // Sirve para liberar memoria con delete y evitar fugas de memoria
   ~ListaPacientes();

   // Operaiones Basicas
   /*
   void insertarPaciente(int id, string nombre, int edad, string dpi); // Crea un nuevo paciente y lo mete en la lista.
   Paciente* buscarPaciente(int id); // buscarPaciente(int id)
   bool eliminarPaciente(int id);  // eliminarPaciente(int id)
  
   */

   void insertarPaciente(long long id, string nombre, int edad, string dpi);
   Paciente* buscarPaciente(long long id);
   bool eliminarPaciente(long long id);
   void mostrarPacientes();   // Recorre toda la lista y muestra todos los pacientes.
 
   // NUEVO:
   // Devuelve el inicio de la lista enlazada 
   Paciente* getCabeza();

   // Verifica si la lista esta vacia
   bool estaVacia();

};

#endif