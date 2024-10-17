#ifndef RED_NACIONAL_H
#define RED_NACIONAL_H

#include "eds.h"
#include <vector>

using namespace std;

class red_nacional {
private:
    string pais;
    float ventas;
    double precio_ctipo1, precio_ctipo2, precio_ctipo3;
    bool estaciones_activa;
    vector<eds> estaciones_servicio; // Vector de estaciones de servicio

public:
    red_nacional(); // Constructor
    vector<double> fijar_precios(); //CON ESTO OBTENGO UNA LISTA CON LOS PRECIOS
    // Métodos para manejar la red nacional
    void calcular_ventas(); // Calcular ventas por tipo de combustible
    void agregar_estacion(); // Agregar estación
    void eliminar_estacion(); // Eliminar estación
    vector<eds>& get_estaciones_servicio() {
        return estaciones_servicio;
    }
};

#endif // RED_NACIONAL_H
