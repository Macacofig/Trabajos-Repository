#include "ModCuentas.h"

ModCuentas::ModCuentas()
{
	ind = 0;
	cuentas = new Cuenta*[CU];
}

ModCuentas::~ModCuentas()
{
	delete[] cuentas;
}

void ModCuentas::registrar(Cuenta* cuenta)
{
	if (ind < CU)
	{
		cuentas[ind] = cuenta;
		ind++;
	}
}

Cuenta* ModCuentas::buscar(int id)
{
	for (int i = 0; i < ind; i++)
	{
		if (cuentas[i]->getId() == id)
		{
			return cuentas[i];
		}
	}
	return NULL;
}

void ModCuentas::eliminarCuenta(int id)
{
	int j;
	for (int i = 0; i < ind; i++)
	{
		if (cuentas[i]->getId() == id)
		{
			cuentas[i] = NULL;
			for (j = i + 1; j < ind; j++)
			{
				cuentas[j - 1] = cuentas[j];
			}
			cuentas[j - 1] = NULL;
			ind--;
		}
	}
}

string ModCuentas::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << cuentas[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		} 
	}
	ss << "]";
	return ss.str();
}
