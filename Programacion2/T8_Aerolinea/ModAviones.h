#pragma once
#include "Avion.h"
class ModAviones
{
private:
	int ind;
	int tam;
	Avion** aviones;
public:
	ModAviones(int tam);
	~ModAviones();
	void registrar(Avion* avion);
	Avion* buscar(int placa);
	string toJson();
};

