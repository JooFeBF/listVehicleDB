#include <cstring>
#include <iostream>
#include <conio.h>

using namespace std;

/*
 Construya una nueva versión de su programa con listas simples que gestiona la información de vehículos del concesionario (versión antes de la evaluación) de forma que ahora funcione con una lista circular simple. En tal sentido, analice y actualice las funciones que lo componen.
//MENU DE OPCIONES DEL PROGRAMA
1. registrar vehículos que ingresan al negocio.
2. Agregar características a la hoja de vida de un vehículo (la hoja de vida es una lista simple de datos adicionales de cada vehículo).
3. consultar las existencias de vehículos activos por marca-modelo, y, por rango de precio, y, por tipo.
4. actualizar o modificar la información de un vehículo registrado en el sistema (valor, o, tipo).
5. Eliminar-activar (de forma lógica) un vehículo del sistema.
6. Mover vehículos borrados a una nueva lista (desaparecen de la lista original, además desaparece su hoja de vida).
7. Consultar lista total de vehículos (El usuario escoge la lista a consultar: A-ctivos B-orrados)
8. salir
//

Modifique además la opción 7 para lograr que la consulta de vehículos funcione con teclas, es decir, al seleccionar la opción 7 se muestra el primer vehículo de la lista, para ver el siguiente debemos oprimir Flecha Abajo, solo se verá un vehículo a la vez, más precisamente, el siguiente de la lista. En el momento en que se desee volver al menú se imprimirá ESC. Recuerde que en la opción 7 el usuario podrá indicar cuál de las dos listas desea consultar.
*/

#define ESC 27
#define ENTER 13
#define UP 72
#define RIGHT 77


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

void addVehicle (Vehicle **tail, Vehicle **head, string brand, string model, char type, float price, char active, string color, string plate, string year) {
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
    *head = newVehicle;
    newVehicle->next = newVehicle;
  } else {
    Vehicle *temp = *tail;
    *tail = newVehicle;
    temp->next = newVehicle;
    newVehicle->next = *head;
  }
}

void addFeature (Vehicle *vehicle, string name) {
  Feature *newFeature = new Feature;
  newFeature->name = name;
  newFeature->next = NULL;

  if (vehicle->features == NULL) {
    vehicle->features = newFeature;
    vehicle->features->next = newFeature;
  } else {
    Feature *temp = vehicle->features;
    Feature *temp2 = vehicle->features;
    vehicle->features = newFeature;
    newFeature->next = temp;
    while (temp2->next != NULL && temp2->next != temp) {
      temp2 = temp2->next;
    }
    temp2->next = newFeature;
  }
}

void showVehicles (Vehicle *tail) {
  Vehicle *temp = tail;

  int key = 0;
  key = getch();
  while (key != ESC && key != ENTER) {
      cout << "Brand: " << temp->brand << endl;
      cout << "Model: " << temp->model << endl;
      cout << "Type: " << temp->type << endl;
      cout << "Price: " << temp->price << endl;
      cout << "Active: " << temp->active << endl;
      cout << "Color: " << temp->color << endl;
      cout << "Plate: " << temp->plate << endl;
      cout << "Year: " << temp->year << endl;

      Feature *tempFeature = temp->features;
      while (tempFeature != NULL && key != ESC && key != ENTER) {
        cout << "Feature: " << tempFeature->name << endl;
        if (key == RIGHT) {
          tempFeature = tempFeature->next;
        }
        key = getch();
      }

      key = getch();
      if (key == UP) {
        temp = temp->next;
      }
  }
}

void showVehiclesByBrand (Vehicle *tail, string brand) {
  Vehicle *temp = tail;

  int key = 0;
  key = getch();
  while (key != ESC && key != ENTER) {
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
      while (tempFeature != NULL && key != ESC && key != ENTER) {
        cout << "Feature: " << tempFeature->name << endl;
        if (key == RIGHT) {
          tempFeature = tempFeature->next;
        }
        key = getch();
      }
    }

    key = getch();
    if (key == UP) {
      temp = temp->next;
    }
  }
}

void showVehiclesByModel (Vehicle *tail, string model) {
  Vehicle *temp = tail;

  int key = 0;
  key = getch();
  while (key != ESC && key != ENTER) {
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
      while (tempFeature != NULL && key != ESC && key != ENTER) {
        cout << "Feature: " << tempFeature->name << endl;
        if (key == RIGHT) {
          tempFeature = tempFeature->next;
        }
        key = getch();
      }
    }

    key = getch();
    if (key == UP) {
      temp = temp->next;
    }
  }
}

void showVehiclesByPriceRange (Vehicle *tail, float minPrice, float maxPrice) {
  Vehicle *temp = tail;

  int key = 0;
  key = getch();
  while (key != ESC && key != ENTER) {
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
      while (tempFeature != NULL && key != ESC && key != ENTER) {
        cout << "Feature: " << tempFeature->name << endl;
        if (key == RIGHT) {
          tempFeature = tempFeature->next;
        }
        key = getch();
      }
    }

    key = getch();
    if (key == UP) {
      temp = temp->next;
    }
  }
}

void showVehiclesByType (Vehicle *tail, char type) {
  Vehicle *temp = tail;

  int key = 0;
  key = getch();
  while (key != ESC && key != ENTER) {
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
      while (tempFeature != NULL && key != ESC && key != ENTER) {
        cout << "Feature: " << tempFeature->name << endl;
        if (key == RIGHT) {
          tempFeature = tempFeature->next;
        }
        key = getch();
      }
    }

    key = getch();
    if (key == UP) {
      temp = temp->next;
    }
  }
}

void updateVehicle (Vehicle *tail, string plate, float price, char type) {
  Vehicle *temp = tail;

  while (temp != NULL && temp->next != tail) {
    if (strcspn(temp->plate.c_str(), plate.c_str()) == 0) {
      temp->price = price;
      temp->type = type;
    }

    temp = temp->next;
  }
}

void deleteVehicle (Vehicle *tail, string plate) {
  Vehicle *temp = tail;

  while (temp != NULL && temp->next != tail) {
    if (temp -> plate == plate) {
      temp->active = 'B';
      return;
    }
    temp = temp->next;
  }
}


void moveDeactivatedVehicles (Vehicle **tailA, Vehicle **tailB, Vehicle **headA, Vehicle **headB) {
  Vehicle *temp = *tailA;
  Vehicle *prev = NULL;
  Vehicle *next = (*tailA)->next;

  while (temp != NULL && temp->next != *tailA) {
    if (temp->active == 'B') {
      if (prev == NULL) {
        *tailA = next;
        (*headA)->next = next;
      } else {
        prev->next = next;
      }

      if (*tailB == NULL) {
        *tailB = temp;
        *headB = temp;
        temp->next = temp;
      } else {
        Vehicle *tempB = *tailB;
        *tailB = temp;
        tempB->next = temp;
        temp->next = *headB;
      }
    } else {
      prev = temp;
    }

    temp = next;
    next = next->next;
  }
}




int main () {
  Vehicle *tailA = NULL;
  Vehicle *tailB = NULL;
  Vehicle *headA = NULL;
  Vehicle *headB = NULL;

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

        addVehicle(&tailA, &headA, brand, model, type, price, active, color, plate, year);
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
        moveDeactivatedVehicles(&tailA, &tailB, &headA, &headB);
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
