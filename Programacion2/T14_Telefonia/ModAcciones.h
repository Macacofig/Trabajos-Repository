#pragma once
#include "Accion.h"
#define AS 10
class ModAcciones
{
private:
	int ind;
	Accion** acciones;
public:
	ModAcciones();
	~ModAcciones();
	void registrar(Accion* accion);
	string toJson();
};

