#include <iostream>
#include "menu_principal.h"  // Asegúrate de que los archivos existan
#include "red_nacional.h"
#include "menu_eds.h"
#include "menu_red.h"

using namespace std;

red_nacional red; // Instancia de la clase red_nacional

int main() {
    int opcion;
    opcion = menu_principal(); // Llamada al menú principal
    switch (opcion) {
    case 1: {
        menu_gestion_red(red);  // Llamada al menú de EDS
        break;
    case 2:
        menu_gestion_eds(red);
    default:
        cout << "Opción no válida en el menú principal." << endl;
        break;
    } // fin switch principal

    return 0;
}
}
