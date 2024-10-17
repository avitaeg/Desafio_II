#ifndef EDS_H
#define EDS_H
#include "surtidor.h"  // Incluir la clase surtidor
#include <vector>


#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
using namespace std;

class eds {
private:
    string nombre;
    int codigo;
    string region;
    string ubicacion;
    string gerente;
    int cant_surtidores;
    float litros_vendidos_tipo1, litros_vendidos_tipo2, litros_vendidos_tipo3;
    float capacidad_tanque;
    vector<surtidor> surtidores;

public:
    eds(); // Constructor

    // Métodos de asignación
    void _nombre();
    void _codigo();
    void _region();
    void _ubicacion();
    void _gerente();
    int _cant_surtidores();
    void _capacidad_tanque();
    vector<surtidor>& get_surtidores(); // Declaración del método

    // Getters
    int get_codigo() const { return codigo; } // Obtener el código
    int get_cant_surtidores() const;
    float _litros_vendidos_tipo1() const;
    float _litros_vendidos_tipo2() const;
    float _litros_vendidos_tipo3() const;
    float _litros_vendidos() const; // Total litros vendidos
};

#endif // EDS_H
