#include <cstring>
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

El tipo puede ser P (propio) o C (consignado).
Activo puede ser A (activo) o B (borrado).
*/


struct Feature {
  string name;
  Feature *next;
};

struct Vehicle {
  string brand;
  string model;
  char type;
  float price;
  char active;
  string color;
  string plate;
  string year;
  Feature *features;
  Vehicle *next;
};

void addVehicle (Vehicle **tail, string brand, string model, char type, float price, char active, string color, string plate, string year) {
  Vehicle *newVehicle = new Vehicle;
  newVehicle->brand = brand;
  newVehicle->model = model;
  newVehicle->type = type;
  newVehicle->price = price;
  newVehicle->active = active;
  newVehicle->color = color;
  newVehicle->plate = plate;
  newVehicle->year = year;
  newVehicle->features = NULL;
  newVehicle->next = NULL;

  if (*tail == NULL) {
    *tail = newVehicle;
  } else {
    Vehicle *temp = *tail;
    *tail = newVehicle;
    newVehicle->next = temp;
  }
}

void addFeature (Vehicle *vehicle, string name) {
  Feature *newFeature = new Feature;
  newFeature->name = name;
  newFeature->next = NULL;

  if (vehicle->features == NULL) {
    vehicle->features = newFeature;
  } else {
    Feature *tempFeature = vehicle->features;
    vehicle->features = newFeature;
    newFeature->next = tempFeature;
  }
}

void showVehicles (Vehicle *tail) {
  Vehicle *temp = tail;

  int count = 0;
  while (temp != NULL) {
    cout << "Vehicle " << count << endl;
    cout << "Brand: " << temp->brand << endl;
    cout << "Model: " << temp->model << endl;
    cout << "Type: " << temp->type << endl;
    cout << "Price: " << temp->price << endl;
    cout << "Active: " << temp->active << endl;
    cout << "Color: " << temp->color << endl;
    cout << "Plate: " << temp->plate << endl;
    cout << "Year: " << temp->year << endl;

    Feature *tempFeature = temp->features;
    if (tempFeature == NULL) {
      cout << "No features" << endl;
    } else {
      cout << "Features:" << endl;
      while (tempFeature != NULL) {
        cout << "- " << tempFeature->name << endl;
        tempFeature = tempFeature->next;
      }
    }

    temp = temp->next;
    count++;
  }
}

void showVehiclesByBrand (Vehicle *tail, string brand) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (strcspn(temp->brand.c_str(), brand.c_str()) == 0) {
      cout << "Brand: " << temp->brand << endl;
      cout << "Model: " << temp->model << endl;
      cout << "Type: " << temp->type << endl;
      cout << "Price: " << temp->price << endl;
      cout << "Active: " << temp->active << endl;
      cout << "Color: " << temp->color << endl;
      cout << "Plate: " << temp->plate << endl;
      cout << "Year: " << temp->year << endl;

      Feature *tempFeature = temp->features;
      while (tempFeature != NULL) {
        cout << "Feature: " << tempFeature->name << endl;
        tempFeature = tempFeature->next;
      }
    }

    temp = temp->next;
  }
}

void showVehiclesByModel (Vehicle *tail, string model) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (strcspn(temp->model.c_str(), model.c_str()) == 0) {
      cout << "Brand: " << temp->brand << endl;
      cout << "Model: " << temp->model << endl;
      cout << "Type: " << temp->type << endl;
      cout << "Price: " << temp->price << endl;
      cout << "Active: " << temp->active << endl;
      cout << "Color: " << temp->color << endl;
      cout << "Plate: " << temp->plate << endl;
      cout << "Year: " << temp->year << endl;

      Feature *tempFeature = temp->features;
      while (tempFeature != NULL) {
        cout << "Feature: " << tempFeature->name << endl;
        tempFeature = tempFeature->next;
      }
    }

    temp = temp->next;
  }
}

void showVehiclesByPriceRange (Vehicle *tail, float minPrice, float maxPrice) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (temp->price >= minPrice && temp->price <= maxPrice) {
      cout << "Brand: " << temp->brand << endl;
      cout << "Model: " << temp->model << endl;
      cout << "Type: " << temp->type << endl;
      cout << "Price: " << temp->price << endl;
      cout << "Active: " << temp->active << endl;
      cout << "Color: " << temp->color << endl;
      cout << "Plate: " << temp->plate << endl;
      cout << "Year: " << temp->year << endl;

      Feature *tempFeature = temp->features;
      while (tempFeature != NULL) {
        cout << "Feature: " << tempFeature->name << endl;
        tempFeature = tempFeature->next;
      }
    }

    temp = temp->next;
  }
}

void showVehiclesByType (Vehicle *tail, char type) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (temp->type == type) {
      cout << "Brand: " << temp->brand << endl;
      cout << "Model: " << temp->model << endl;
      cout << "Type: " << temp->type << endl;
      cout << "Price: " << temp->price << endl;
      cout << "Active: " << temp->active << endl;
      cout << "Color: " << temp->color << endl;
      cout << "Plate: " << temp->plate << endl;
      cout << "Year: " << temp->year << endl;

      Feature *tempFeature = temp->features;
      while (tempFeature != NULL) {
        cout << "Feature: " << tempFeature->name << endl;
        tempFeature = tempFeature->next;
      }
    }

    temp = temp->next;
  }
}

void updateVehicle (Vehicle *tail, string plate, float price, char type) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (strcspn(temp->plate.c_str(), plate.c_str()) == 0) {
      temp->price = price;
      temp->type = type;
    }

    temp = temp->next;
  }
}

void deleteVehicle (Vehicle *tail, string plate) {
  Vehicle *temp = tail;

  while (temp != NULL) {
    if (temp -> plate == plate) {
      temp->active = 'B';
      return;
    }
    temp = temp->next;
  }
}

void moveDeactivatedVehicles (Vehicle **tailA, Vehicle **tailB) {
  Vehicle *temp = *tailA;
  Vehicle *prev = NULL;

  while (temp != NULL) {
    if (temp->active == 'B') {
      if (prev == NULL) {
        *tailA = temp->next;
      } else {
        prev->next = temp->next;
      }

      if (*tailB == NULL) {
        *tailB = temp;
      } else {
        Vehicle *tempB = *tailB;
        *tailB = temp;
        temp->next = tempB;
      }

      Feature *tempFeature = temp->features;
      temp->features = NULL;
      while (tempFeature != NULL) {
        Feature *tempFeatureNext = tempFeature->next;
        delete tempFeature;
        tempFeature = tempFeatureNext;
      }

      temp = temp->next;
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
}




int main () {
  Vehicle *tailA = NULL;

  Vehicle *tailB = NULL;

  int option;

  do {
    cout << "1. Add vehicle" << endl;
    cout << "2. Add feature" << endl;
    cout << "3. Show vehicles by brand" << endl;
    cout << "4. Show vehicles by model" << endl;
    cout << "5. Show vehicles by price range" << endl;
    cout << "6. Show vehicles by type" << endl;
    cout << "7. Update vehicle" << endl;
    cout << "8. Delete vehicle" << endl;
    cout << "9. Move deactivated vehicles" << endl;
    cout << "10. Show vehicles" << endl;
    cout << "11. Exit" << endl;
    cout << "Option: ";
    cin >> option;

    switch (option) {
      case 1: {
        string brand;
        string model;
        char type;
        float price;
        char active;
        string color;
        string plate;
        string year;

        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Type: ";
        cin >> type;
        cout << "Price: ";
        cin >> price;
        cout << "Active: ";
        cin >> active;
        cout << "Color: ";
        cin >> color;
        cout << "Plate: ";
        cin >> plate;
        cout << "Year: ";
        cin >> year;

        addVehicle(&tailA, brand, model, type, price, active, color, plate, year);
        break;
      }
      case 2: {
        string plate;
        string name;

        cout << "Plate: ";
        cin >> plate;
        cout << "Name: ";
        cin >> name;

        Vehicle *temp = tailA;

        while (temp != NULL) {
          if (strcspn(temp->plate.c_str(), plate.c_str()) == 0) {
            addFeature(temp, name);
          }

          temp = temp->next;
        }
        break;
      }
      case 3: {
        string brand;

        cout << "Brand: ";
        cin >> brand;

        showVehiclesByBrand(tailA, brand);
        break;
      }
      case 4: {
        string model;

        cout << "Model: ";
        cin >> model;

        showVehiclesByModel(tailA, model);
        break;
      }
      case 5: {
        float minPrice;
        float maxPrice;

        cout << "Min price: ";
        cin >> minPrice;
        cout << "Max price: ";
        cin >> maxPrice;

        showVehiclesByPriceRange(tailA, minPrice, maxPrice);
        break;
      }
      case 6: {
        char type;

        cout << "Type: ";
        cin >> type;

        showVehiclesByType(tailA, type);
        break;
      }
      case 7: {
        string plate;
        float price;
        char type;

        cout << "Plate: ";
        cin >> plate;
        cout << "Price: ";
        cin >> price;
        cout << "Type: ";
        cin >> type;

        updateVehicle(tailA, plate, price, type);
        break;
      }
      case 8: {
        string plate;

        cout << "Plate: ";
        cin >> plate;

        deleteVehicle(tailA, plate);
        break;
      }
      case 9: {
        moveDeactivatedVehicles(&tailA, &tailB);
        break;
      }
      case 10: {
        int listOption;

        cout << "1. Active vehicles" << endl;
        cout << "2. Deactivated vehicles" << endl;
        cout << "Option: ";
        cin >> listOption;
        if (listOption == 1) {
          showVehicles(tailA);
        } else if (listOption == 2) {
          showVehicles(tailB);
        } else {
          cout << "Invalid option" << endl;
        }
        break;
      }
      case 11: {
        break;
      }
      default: {
        cout << "Invalid option" << endl;
        break;
      }
  }
  } while (option != 11);

  return 0;
}
