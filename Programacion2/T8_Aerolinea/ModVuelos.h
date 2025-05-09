#pragma once
#include "Vuelo.h"
class ModVuelos
{
private:
	int ind;
	int tam;
	Vuelo** vuelos;
public:
	ModVuelos(int tam);
	~ModVuelos();
	void registrarVuelo(Vuelo* vuelo);
	Vuelo* buscar(int numero);
	string toJson();
};

