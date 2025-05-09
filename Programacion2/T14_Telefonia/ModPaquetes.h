#pragma once
#include "Paquete.h"
#include "PaqueteMinutos.h"
#include "PaqueteSMS.h"
#define PS 10
class ModPaquetes
{
private:
	int ind;
	Paquete** paquetes;
public:
	ModPaquetes();
	~ModPaquetes();
	void registrar(Paquete* paquete);
	PaqueteMinutos* buscar(string tipo);
	PaqueteSMS* buscars(string tipo);
	string toJson();
};

