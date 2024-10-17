#include "menu_red.h"
#include "red_nacional.h"
#include <iostream>
#include <limits>

using namespace std;

void menu_gestion_red(red_nacional& red) {
    while (true) {
        int subopcion;
        cout << "\n--- MENÚ DE GESTIÓN DE LA RED ---" << endl;
        cout << "1) Agregar estaciones de servicio." << endl;
        cout << "2) Eliminar una E/S de la red nacional." << endl;
        cout << "3) Calcular el monto total de las ventas en cada E/S del país." << endl;
        cout << "4) Fijar los precios del combustible para toda la red." << endl;
        cout << "5) Volver al menú principal." << endl;

        cout << "Seleccione una opción: ";
        if (cin >> subopcion && subopcion >= 1 && subopcion <= 5) {
            if (subopcion == 5) break; // Volver al menú principal
        } else {
            cout << "Tipo de dato inválido o fuera de rango, vuelva a intentar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (subopcion) {
        case 1: {
            // Acceder al vector de estaciones y agregar una nueva estación
            vector<eds>& estaciones = red.get_estaciones_servicio();
            red.agregar_estacion();
            cout << "Estación agregada exitosamente." << endl;
            cout << "Total de estaciones: " << estaciones.size() << endl;

            // Mostrar los surtidores de la estación recién agregada
            if (!estaciones.empty()) {
                eds& nueva_estacion = estaciones.back(); // Acceder a la última estación agregada
                vector<surtidor>& surtidores = nueva_estacion.get_surtidores();
                cout << "La estación recién agregada tiene " << surtidores.size() << " surtidores." << endl;
            }
            break;
        }

        case 2:
            red.eliminar_estacion();
            cout << "Estación eliminada exitosamente." << endl;
            break;

        case 3:
            red.calcular_ventas();
            break;

        case 4:
            red.fijar_precios();
            cout << "Precios fijados para toda la red." << endl;
            break;
        }
    }
}
