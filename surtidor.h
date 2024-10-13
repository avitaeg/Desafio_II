#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <iostream>
using namespace std;

/////FALTA ASIGNAR LOS SETTERS Y GETTERS, DESTRUCTORS TAMBIÉN//////

class surtidor
{
private: //Atributos
    int codigo;
    string modelo;
    float litros_vendidos;
    float dinero_recolectado;
    float precio_tipo1;
    float precio_tipo_2;
    float precio_tipo3;
    float reservac_tipo1; //Combustible regular
    float reservac_tipo2; //Combustible Premium
    float reservac_tipo3; //Combustible EcoExtra
public: //Métodos
    surtidor();
    void act_reservas(); //Actualiza la cantidad de combustible por reserva y según el tipo.
    void calc_litros_v(); //Calcula la cantidad de litros vendidos.
    void modelo_s(); //Establece el modelo del surtidor de la forma: AKL-0001-963D.
    void codigo_s(); //Genera el código de la estación: 7458.
    void estbl_precios(); //Establece los precios de los combustibles por tipo.


};

#endif // SURTIDOR_H
