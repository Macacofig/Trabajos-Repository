#pragma once
#include "SingletonEquipos.h"
class Federacion
{
private:
	string nombre;
public:
	Federacion(string nombre);
	~Federacion();
	void registrarEqiopo(string nombre, string descripcion);
	string toJson();
	void mostrar();
};

