#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Atencion
{
private:
    int codigo;
    string descripcion;
    int costo;
    string detalle;
public:
    Atencion(int codigo, string descripcion, int costo, string detalle);
    ~Atencion();
    int getCodigo();
    string toString();
};

