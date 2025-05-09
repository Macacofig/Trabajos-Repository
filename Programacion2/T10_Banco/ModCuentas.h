#pragma once
#include "Cuenta.h"
#define CU 20
class ModCuentas
{
private:
	int ind;
	Cuenta** cuentas;
public:
	ModCuentas();
	~ModCuentas();
	void registrar(Cuenta* cuenta);
	Cuenta* buscar(int id);
	void eliminarCuenta(int id);
	string toJson();
};

