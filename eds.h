#ifndef EDS_H
#define EDS_H
#include <iostream>
using namespace std;

/////FALTA ASIGNAR LOS SETTERS Y GETTERS, DESTRUCTORS TAMBIÉN//////

class eds
{
private: //Atributos
    string nombre;
    int codigo; //Codigo estación: 78541.
    string region;
    string ubicacion; //(NORTE, CENTRO, SUR).
    string gerente; // Nombre o código de gerente.
    float cant_surtidores; // Surtidores activos.
    float litros_vendidos; // Discriminando el tipo de combustible.
    float capacidad_tanque; //Un número entre 100 y 200.

public:
    eds();
    void _nombre(); //Función para asignar el nombre de la estación.
    void _codigo(); //Asigna el código de la estación.
    void _region(); //Asigna la región.
    void _ubicacion(); //Asigna la ubicación (NORTE, CENTRO, SUR)
    void _gerente(); //Asigna el nombre o datos del gerente
    void _cant_surtidores(); //Cantidad de surtidores activos
    void _litros_vendidos(); //Extrae los litros vendidos de cada uno de los surtidores.
    void _capacidad_tanque(); //Genera un número aleatorio entre 100 y 200 que será la capacidad del tanque.
};

#endif // EDS_H
