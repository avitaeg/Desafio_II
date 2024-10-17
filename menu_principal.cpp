#include "menu_principal.h"
#include <iostream>
#include <limits>
using namespace std;

int menu_principal() {
    int opcion;
    cout<<"BIENVENIDO AL SISTEMA DE GESTIoN DE LA RED NACIONAL DE ESTACIONES"<<endl;
    cout<<"POR FAVOR ESCOJA EL NÚMERO CORRESPONDIENTE A SU ELECCIÓN"<<endl;
    cout<<"1)GESTION DE LA RED"<<endl;
    cout<<"2)GESTION DE ESTACIONES DE SERVICIO"<<endl;
    cout<<"3)VERIFICACIÓN DE FUGAS"<<endl;
    cout<<"4)SIMULAR UNA VENTA"<<endl;

    while (true) {
        cout << "Ingrese una opción (1-5): ";
        if (cin >> opcion && opcion >= 1 && opcion <= 5) {
            break;
        } else {
            cout << "Tipo de dato inválido o fuera de rango, vuelva a intentar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return opcion;
}
