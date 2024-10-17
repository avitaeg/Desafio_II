#include "eds.h"
#include <regex>    // Para usar expresiones regulares
#include <cctype>   // Para comprobar caracteres
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()
#include <iostream>
#include <limits>
#include <surtidor.h>

using namespace std;

// Constructor: Inicializa valores por defecto
eds::eds() {
    nombre = "";
    codigo = 0;
    region = "";
    ubicacion = "";
    gerente = "";
    cant_surtidores = 0;
    litros_vendidos_tipo1 = litros_vendidos_tipo2 = litros_vendidos_tipo3 = 0.0;
    capacidad_tanque = 0.0;
}

// Función para asignar el nombre de la estación (solo letras)
void eds::_nombre() {
    bool valid = false;
    while (!valid) {
        cout << "Ingrese el nombre de la estación (solo caracteres alfabéticos): ";
        cin >> nombre;

        valid = true;
        for (char c : nombre) {
            if (!isalpha(c)) {
                valid = false;
                cout << "Error: El nombre debe contener solo letras." << endl;
                break;
            }
        }
    }
}

// Función para asignar el código de la estación (5 dígitos)
void eds::_codigo() {
    bool valid = false;
    while (!valid) {
        cout << "Ingrese el código de la estación (5 dígitos): ";
        cin >> codigo;

        if (codigo >= 10000 && codigo <= 99999) {
            valid = true;
        } else {
            cout << "Error: El código debe ser un número de 5 dígitos." << endl;
        }
    }
}

// Función para asignar la región de la estación (opción de menú)
void eds::_region() {
    int opcion = 0;
    while (opcion < 1 || opcion > 3) {
        cout << "Seleccione la región (1. NORTE, 2. CENTRO, 3. SUR): ";
        cin >> opcion;

        switch (opcion) {
        case 1: region = "NORTE"; break;
        case 2: region = "CENTRO"; break;
        case 3: region = "SUR"; break;
        default: cout << "Error: Seleccione una opción válida (1, 2, 3)." <<endl;
        }
    }
}

// Función para asignar la ubicación (coordenadas GPS en formato: xx.xxxxxx, yy.yyyyyy)
void eds::_ubicacion() {
    bool valid = false;
    while (!valid) {
        cout << "Ingrese la ubicación (coordenadas GPS en formato: xx.xxxxxx, yy.yyyyyy): ";
        getline(cin, ubicacion);

        // Expresión regular para validar coordenadas GPS en formato decimal
        regex gps_pattern("^-?\\d{1,2}\\.\\d{6},\\s?-?\\d{1,3}\\.\\d{6}$");
        if (regex_match(ubicacion, gps_pattern)) {
            valid = true;
        } else {
            cout << "Error: La ubicación debe estar en formato GPS (xx.xxxxxx, yy.yyyyyy)." << endl;
        }
    }
}

void eds::_gerente() {
    cout << "Ingrese el nombre o código del gerente: ";
    cin >> gerente;
}

int eds::_cant_surtidores() {
    int cantidad;
    bool valid = false;

    while (!valid) {
        cout << "Ingrese la cantidad de surtidores activos (entre 2 y 12): ";
        cin >> cantidad;

        if (cin.fail()) { // Verificar si la entrada falló
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la línea actual
            cout << "Error: Entrada no válida. Por favor, ingrese un número entero." << endl;
        } else if (cantidad >= 2 && cantidad <= 12) {
            cant_surtidores = cantidad; // Asignar la cantidad si es válida
            valid = true; // Salir del bucle
            // Crear surtidores
            for (int i = 0; i < cant_surtidores; i++) {
                surtidor nuevo_surtidor;  // Crear un nuevo surtidor

                // Llamar a las funciones para establecer datos de cada surtidor
                nuevo_surtidor.modelo_s();  // Establecer el modelo
                nuevo_surtidor.codigo_s();  // Generar código
               //  nuevo_surtidor.estbl_precios(); // Establecer precios
                // Agregar el surtidor al vector de surtidores
                surtidores.push_back(nuevo_surtidor);
            }
        }
            else
            {
            cout << "Error: La cantidad de surtidores debe estar entre 2 y 12." << endl;
        }
    }
    return cant_surtidores; // Retornar la cantidad de surtidores
}


// Getter para la cantidad de surtidores
int eds::get_cant_surtidores() const {
    return cant_surtidores;
}

// Getter para litros vendidos tipo 1
float eds::_litros_vendidos_tipo1() const {
    return litros_vendidos_tipo1;
}

// Getter para litros vendidos tipo 2
float eds::_litros_vendidos_tipo2() const {
    return litros_vendidos_tipo2;
}

// Getter para litros vendidos tipo 3
float eds::_litros_vendidos_tipo3() const {
    return litros_vendidos_tipo3;
}

// Función para asignar los litros vendidos
float eds::_litros_vendidos() const {
    return litros_vendidos_tipo1 + litros_vendidos_tipo2 + litros_vendidos_tipo3;
}

// Función para generar la capacidad del tanque (número entre 100 y 200)
void eds::_capacidad_tanque() {
    srand(static_cast<unsigned>(time(0))); // Semilla para generar números aleatorios
    capacidad_tanque = 100 + rand() % 101; // Número entre 100 y 200
    cout << "Capacidad del tanque asignada: " << capacidad_tanque << " litros" <<endl;
}

vector<surtidor>& eds::get_surtidores() {
    return surtidores; // Implementación del método
}
