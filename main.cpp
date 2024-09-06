#include <iostream>

using namespace std;

/**
Para el problema de la consignataria de vehículos...

Se requiere construir un programa en C o C++ para gestionar la información relacionada con los vehículos que administra y comercializa una empresa consignataria de vehículos (compra-venta de vehículos). El objetivo es disponer de un sistema que permita:
1. registrar vehículos que ingresan al negocio.
2. Agregar características a la hoja de vida de un vehículo (la hoja de vida es una lista simple de datos adicionales de cada vehículo).
3. consultar las existencias de vehículos activos por marca-modelo, y, por rango de precio, y, por tipo.
4. actualizar o modificar la información de un vehículo registrado en el sistema (valor, o, tipo).
5. Eliminar-activar (de forma lógica) un vehículo del sistema.
6. Mover vehículos borrados a una nueva lista (desaparecen de la lista original, además desaparece su hoja de vida).
7. Consultar lista total de vehículos (El usuario escoge la lista a consultar: A-ctivos B-orrados)
8. salir

Elabore la versión con listas simples, es decir, en está versión cada vehículo es un nodo de una lista simple, observe que la versión con listas simples incluye nuevas funcionalidades (en el menú anterior las puede identificar -opciones 2, 6, 76-).

Al momento de registrar un vehículo en el sistema (opción 1) es opcional adicionarle de una vez características o, no hacerlo y agregarlas o agregar más luego por la opción 2. Es decir, en la opción 1 se puede preguntar si se desea agregar características.
*/

struct Vehicle {
  string brand;
  string model;
  string type;
  float price;
  string active;
  string *features;
  Vehicle *next;
};

struct Feature {
  string name;
  Feature *next;
};



int main () {
  cout << "Hello, World!" << endl;
  return 0;
}
