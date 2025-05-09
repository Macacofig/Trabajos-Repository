#pragma once
#include "Vehiculo.h"
#define VEH 10
class ModVehiculos
{
private:
	int ind;
	Vehiculo** vehiculos;
public:
	ModVehiculos();
	~ModVehiculos();
	void ordenar();
	void registrar(Vehiculo* vehiculo);
	Vehiculo* buscar(string patente);
	void mostrar();
	string toJson();
};

