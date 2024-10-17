#include "surtidor.h"
#include <regex>
#include <unordered_set>
#include <vector> // Añadir para el historial

using namespace std;

unordered_set<int> codigos_usados; // Conjunto para almacenar códigos utilizados

vector<string> historial_transacciones; // Registro de transacciones

// Constructor
surtidor::surtidor() {
    codigo = 0;
    modelo = "Desconocido";
    litros_vendidos_tipo1 = litros_vendidos_tipo2 = litros_vendidos_tipo3 = 0.0;
    dinero_recolectado = 0.0;
    precio_tipo1 = precio_tipo2 = precio_tipo3 = 0.0;
    reservac_tipo1 = reservac_tipo2 = reservac_tipo3 = 0.0;
    estado_activo=true;
}
// Implementación del método para consultar el historial de transacciones
void surtidor::consultar_historico() const {
    cout << "Historial de transacciones para el surtidor " << codigo << " (" << modelo << "):" << endl;
    if (historial_transacciones.empty()) {
        cout << "No hay transacciones registradas." << endl;
    } else {
        for (const auto& transaccion : historial_transacciones) {
            cout << transaccion << endl;
        }
    }
}

void surtidor::act_reservas(float venta_actual, int tipo_combustible) {
    switch (tipo_combustible) {
    case 1:
        if (venta_actual > reservac_tipo1) {
            cout << "Error: No hay suficiente combustible regular." << endl;
            return;
        }
        reservac_tipo1 -= venta_actual;
        litros_vendidos_tipo1 += venta_actual;  // Actualizar litros vendidos de tipo1
        cout << "Reserva de combustible regular actualizada. Quedan " << reservac_tipo1 << " litros." << endl;
        break;

    case 2:
        if (venta_actual > reservac_tipo2) {
            cout << "Error: No hay suficiente combustible Premium." << endl;
            return;
        }
        reservac_tipo2 -= venta_actual;
        litros_vendidos_tipo2 += venta_actual;  // Actualizar litros vendidos de tipo2
        cout << "Reserva de combustible Premium actualizada. Quedan " << reservac_tipo2 << " litros." << endl;
        break;

    case 3:
        if (venta_actual > reservac_tipo3) {
            cout << "Error: No hay suficiente combustible EcoExtra." << endl;
            return;
        }
        reservac_tipo3 -= venta_actual;
        litros_vendidos_tipo3 += venta_actual;  // Actualizar litros vendidos de tipo3
        cout << "Reserva de combustible EcoExtra actualizada. Quedan " << reservac_tipo3 << " litros." << endl;
        break;

    default:
        cout << "Tipo de combustible inválido." << endl;
        break;
    }
}

// Imprime la cantidad de litros vendidos según el tipo
void surtidor::set_litros_vendidos_tipo1(float litros) {
    litros_vendidos_tipo1 = litros;
}

void surtidor::set_litros_vendidos_tipo2(float litros) {
    litros_vendidos_tipo2 = litros;
}

void surtidor::set_litros_vendidos_tipo3(float litros) {
    litros_vendidos_tipo3 = litros;
}

float surtidor::get_litros_vendidos_tipo1() const {
    return litros_vendidos_tipo1;
}

float surtidor::get_litros_vendidos_tipo2() const {
    return litros_vendidos_tipo2;
}

float surtidor::get_litros_vendidos_tipo3() const {
    return litros_vendidos_tipo3;
}

void surtidor::calc_litros_v() {
    // Mostrar los litros vendidos por cada tipo de combustible usando los getters
    cout << "Litros vendidos de combustible regular: " << get_litros_vendidos_tipo1() << " litros." << endl;
    cout << "Litros vendidos de combustible Premium: " << get_litros_vendidos_tipo2() << " litros." << endl;
    cout << "Litros vendidos de combustible EcoExtra: " << get_litros_vendidos_tipo3() << " litros." << endl;

    // Calcular y mostrar el total de litros vendidos
    float total_litros_vendidos = get_litros_vendidos_tipo1() + get_litros_vendidos_tipo2() + get_litros_vendidos_tipo3();
    cout << "Total de litros vendidos: " << total_litros_vendidos << " litros." << endl;
}

// Establece el modelo del surtidor
void surtidor::modelo_s() {
    string input_modelo;
    regex formato_modelo("^[A-Z]{3}-[0-9]{4}$"); // Tres letras mayúsculas, guion, y cuatro dígitos

    do {
        cout << "Ingrese el modelo del surtidor (formato AKL-0001): ";
        cin >> input_modelo;

        // Validar si el modelo ingresado coincide con el formato esperado
        if (!regex_match(input_modelo, formato_modelo)) {
            cout << "Error: El modelo no cumple con el formato esperado. Inténtelo de nuevo." << endl;
        }
    } while (!regex_match(input_modelo, formato_modelo));

    // Si la validación es exitosa, asignar el modelo
    modelo = input_modelo;
    cout << "Modelo del surtidor asignado correctamente: " << modelo << endl;
}

// Genera el código del surtidor
void surtidor::codigo_s() {
    int input_codigo;

    while (true) {
        cout << "Ingrese el código del surtidor (4 dígitos): ";
        cin >> input_codigo;

        // Validar que el código tenga exactamente 4 dígitos
        if (input_codigo < 1000 || input_codigo > 9999) {
            cout << "Error: El código debe ser un número de 4 dígitos. Inténtelo de nuevo." << endl;
            continue; // Vuelve a pedir la entrada
        }

        // Comprobar si el código ya ha sido utilizado
        if (codigos_usados.find(input_codigo) != codigos_usados.end()) {
            cout << "Error: Este código ya está en uso. Inténtelo de nuevo." << endl;
        } else {
            // Si pasa todas las validaciones, asignar y agregar a la lista de códigos utilizados
            codigo = input_codigo;
            codigos_usados.insert(codigo); // Añadir el código al conjunto
            cout << "Código del surtidor asignado correctamente: " << codigo << endl;
            break; // Salir del bucle
        }
    }
}


void surtidor::simular_venta(float cantidad, int tipo_combustible, const string& metodo_pago, const string& documento_cliente) {
    float precio = 0.0; // Suponemos que se establecerá el precio correcto basado en el tipo
    switch (tipo_combustible) {
    case 1: precio = precio_tipo1; break;
    case 2: precio = precio_tipo2; break;
    case 3: precio = precio_tipo3; break;
    default: return; // Manejo de error, tipo de combustible no válido
    }

    // Actualizar reservas
    act_reservas(cantidad, tipo_combustible);

    // Calcular el total
    float total = cantidad * precio;

    // Registrar la transacción
    time_t now = time(0);
    char* dt = ctime(&now); // Obtener la fecha y hora actual
    string transaccion = "Fecha: " + string(dt) +
                         ", Cantidad: " + to_string(cantidad) +
                         ", Tipo: " + to_string(tipo_combustible) +
                         ", Pago: " + metodo_pago +
                         ", Documento: " + documento_cliente +
                         ", Total: " + to_string(total);

    historial_transacciones.push_back(transaccion);
    dinero_recolectado += total; // Actualizar el total recolectado
}

int surtidor::get_codigo() const {
    return codigo;  // Retorna el valor de 'codigo'
}

