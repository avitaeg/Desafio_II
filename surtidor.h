/*
#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector> // Añadir para el historial
#include <ctime> // Para registrar fecha y hora

using namespace std;

class surtidor {
private:
    int codigo;
    string modelo;
    float litros_vendidos_tipo1, litros_vendidos_tipo2, litros_vendidos_tipo3;
    float dinero_recolectado;
    float precio_tipo1, precio_tipo2, precio_tipo3;
    float reservac_tipo1, reservac_tipo2, reservac_tipo3;

    // Historial de transacciones
    vector<string> historial_transacciones; // Agregado

public:
    surtidor(); // Constructor

    void act_reservas(float venta_actual, int tipo_combustible); // Actualizar reservas
    void modelo_s(); // Establecer modelo
    void codigo_s(); // Generar código
    void estbl_precios(); // Establecer precios
    void calc_litros_v(); // Calcular litros vendidos

    // Métodos para establecer y obtener litros vendidos
    void set_litros_vendidos_tipo1(float litros);
    void set_litros_vendidos_tipo2(float litros);
    void set_litros_vendidos_tipo3(float litros);
    float get_litros_vendidos_tipo1() const;
    float get_litros_vendidos_tipo2() const;
    float get_litros_vendidos_tipo3() const;

    // Nuevo método para consultar el historial de transacciones
    void consultar_historico() const; // Agregado
    void simular_venta(float cantidad, int tipo_combustible, const string& metodo_pago, const string& documento_cliente);
};

// Declaración de la plantilla para establecer los precios
template <typename T>
void establecer_precio(T& precio);

#endif // SURTIDOR_H

*/
#ifndef SURTIDOR_H

#define SURTIDOR_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector> // Añadir para el historial
#include <ctime> // Para registrar fecha y hora

using namespace std;

class surtidor {

private:
    int codigo;
    string modelo;
    float litros_vendidos_tipo1, litros_vendidos_tipo2, litros_vendidos_tipo3;
    float dinero_recolectado;
    float precio_tipo1, precio_tipo2, precio_tipo3;
    float reservac_tipo1, reservac_tipo2, reservac_tipo3;
    bool estado_activo;

    // Historial de transacciones
    vector<string> historial_transacciones; // Agregado

public:
    surtidor(); // Constructor

    void act_reservas(float venta_actual, int tipo_combustible); // Actualizar reservas
    void modelo_s(); // Establecer modelo
    void codigo_s(); // Generar código

    // Getter para el código
    int get_codigo() const; // Agregado

    //void estbl_precios(); // Establecer precios
    void calc_litros_v(); // Calcular litros vendidos

    // Métodos para establecer y obtener litros vendidos
    void set_litros_vendidos_tipo1(float litros);
    void set_litros_vendidos_tipo2(float litros);
    void set_litros_vendidos_tipo3(float litros);
    float get_litros_vendidos_tipo1() const;
    float get_litros_vendidos_tipo2() const;
    float get_litros_vendidos_tipo3() const;
    void activar() { estado_activo = true; }
    void desactivar() { estado_activo = false; }

    // Método para verificar si el surtidor está activo
    bool esta_activo() const { return estado_activo; }
    // Nuevo método para consultar el historial de transacciones
    void consultar_historico() const; // Agregado
    void simular_venta(float cantidad, int tipo_combustible, const string& metodo_pago, const string& documento_cliente);
};

// Declaración de la plantilla para establecer los precios
template <typename T>
void establecer_precio(T& precio);

#endif // SURTIDOR_H
