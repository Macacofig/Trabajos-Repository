#pragma once
#include "Transaccion.h"
#define TR 10
class ModTransacciones
{
private:
	int ind;
	Transaccion** transacciones;
public:
	ModTransacciones();
	~ModTransacciones();
	int getInd();
	void registrar(Transaccion* transaccion);
	Transaccion* buscar(int id);
	string toJson();
};

