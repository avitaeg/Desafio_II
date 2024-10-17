#include "menu_eds.h"
#include "red_nacional.h"
#include "eds.h"
#include "surtidor.h"
#include <iostream>
#include <vector> // Para el manejo de los arreglos dinámicos
#include <limits>

using namespace std;

void menu_gestion_eds(red_nacional& red) {
    // Arreglos dinámicos para gestionar surtidores activos e inactivos
    vector<int> codigos_surtidores_activos;
    vector<int> codigos_surtidores_inactivos;

    while (true) {
        int subopcion;
        cout << "\n--- MENÚ DE GESTIÓN DE ESTACIONES DE SERVICIO ---" << endl;
        cout << "1) Agregar/eliminar surtidor." << endl;
        cout << "2) Activar/desactivar surtidor." << endl;
        cout << "3) Consultar el histórico de transacciones." << endl;
        cout << "4) Reportar la cantidad de litros vendidos." << endl;
        cout << "5) Simular una venta." << endl;
        cout << "6) Asignar capacidad del tanque." << endl;
        cout << "7) Volver al menú principal." << endl;

        cout << "Seleccione una opción: ";
        if (cin >> subopcion && subopcion >= 1 && subopcion <= 7) {
            if (subopcion == 7) break; // Volver al menú principal
        } else {
            cout << "Tipo de dato inválido o fuera de rango, vuelva a intentar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (subopcion) {
        case 1: {
            // Agregar/eliminar surtidor
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {

                    // Mostrar surtidores activos
                    cout << "Surtidores activos: ";
                    for (int codigo : codigos_surtidores_activos) {
                        cout << codigo << " ";
                    }
                    cout << endl;

                    int accion;
                    cout << "Seleccione la acción:\n1) Agregar surtidor\n2) Eliminar surtidor" << endl;
                    cin >> accion;

                    if (accion == 1) {
                        // Agregar surtidor
                        int cant_surtidores = estacion.get_cant_surtidores();
                        if (cant_surtidores < 12) {
                            estacion._cant_surtidores();  // Aumenta el contador de surtidores

                            surtidor nuevo_surtidor;
                            nuevo_surtidor.modelo_s();
                            nuevo_surtidor.codigo_s();
                            codigos_surtidores_activos.push_back(nuevo_surtidor.get_codigo());

                            cout << "Surtidor agregado correctamente. Código: " << nuevo_surtidor.get_codigo() << endl;
                        } else {
                            cout << "No se pueden agregar más surtidores, el máximo es 12." << endl;
                        }
                    } else if (accion == 2) {
                        // Eliminar surtidor
                        int codigo_surtidor;
                        cout << "Ingrese el código del surtidor a eliminar: ";
                        cin >> codigo_surtidor;

                        auto it = find(codigos_surtidores_activos.begin(), codigos_surtidores_activos.end(), codigo_surtidor);
                        if (it != codigos_surtidores_activos.end()) {
                            codigos_surtidores_activos.erase(it);
                            cout << "Surtidor eliminado correctamente." << endl;
                        } else {
                            cout << "Surtidor no encontrado." << endl;
                        }
                    } else {
                        cout << "Opción inválida." << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 2: {
            // Activar/desactivar surtidor
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {

                    int codigo_surtidor;
                    cout << "Ingrese el código del surtidor a activar/desactivar: ";
                    cin >> codigo_surtidor;

                    int accion;
                    cout << "Seleccione la acción:\n1) Activar surtidor\n2) Desactivar surtidor" << endl;
                    cin >> accion;

                    if (accion == 1) {
                        // Activar surtidor
                        auto it = find(codigos_surtidores_inactivos.begin(), codigos_surtidores_inactivos.end(), codigo_surtidor);
                        if (it != codigos_surtidores_inactivos.end()) {
                            codigos_surtidores_inactivos.erase(it);
                            codigos_surtidores_activos.push_back(codigo_surtidor);
                            cout << "Surtidor activado correctamente." << endl;
                        } else {
                            cout << "Surtidor ya está activo o no encontrado." << endl;
                        }
                    } else if (accion == 2) {
                        // Desactivar surtidor
                        auto it = find(codigos_surtidores_activos.begin(), codigos_surtidores_activos.end(), codigo_surtidor);
                        if (it != codigos_surtidores_activos.end()) {
                            codigos_surtidores_activos.erase(it);
                            codigos_surtidores_inactivos.push_back(codigo_surtidor);
                            cout << "Surtidor desactivado correctamente." << endl;
                        } else {
                            cout << "Surtidor ya está inactivo o no encontrado." << endl;
                        }
                    } else {
                        cout << "Opción inválida." << endl;
                    }
                    break;
                }
            }
            break;
        }
        case 3: break;

        case 4: break;

            ///////////////////////////////////////////////////////////////////////
        case 5: {
            // Simular venta
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {

                    int codigo_surtidor;
                    cout << "Ingrese el código del surtidor: ";
                    cin >> codigo_surtidor;

                    // Buscar el surtidor dentro de la estación
                    surtidor* surtidor_seleccionado = nullptr;
                    for (surtidor& s : estacion.get_surtidores()) {
                        if (s.get_codigo() == codigo_surtidor) {
                            surtidor_seleccionado = &s;
                            break;
                        }
                    }

                    if (surtidor_seleccionado) {
                        float cantidad;
                        int tipo_combustible;
                        string metodo_pago, documento_cliente;

                        cout << "Ingrese la cantidad de combustible: ";
                        cin >> cantidad;
                        cout << "Ingrese el tipo de combustible (1, 2, 3): ";
                        cin >> tipo_combustible;
                        cout << "Ingrese el método de pago (Efectivo, TDebito, TCredito): ";
                        cin >> metodo_pago;
                        cout << "Ingrese el número de documento del cliente: ";
                        cin >> documento_cliente;

                        // Simular la venta en el surtidor seleccionado
                        surtidor_seleccionado->simular_venta(cantidad, tipo_combustible, metodo_pago, documento_cliente);
                    } else {
                        cout << "Surtidor no encontrado." << endl;
                    }
                    break;
                }
            }
            break;
        }


            //caso 6
        case 6: {
            // Asignar capacidad del tanque
            int codigo_estacion;
            cout << "Ingrese el código de la estación de servicio: ";
            cin >> codigo_estacion;

            // Buscar la estación
            for (eds& estacion : red.get_estaciones_servicio()) {
                if (estacion.get_codigo() == codigo_estacion) {
                    estacion._capacidad_tanque();
                    cout << "Capacidad del tanque asignada exitosamente." << endl;
                    break; // Casos 3, 4, 5, y 6 se mantienen igual que en tu código original...
                }
            }
        }
        case 7: break;
        }
    }
}
