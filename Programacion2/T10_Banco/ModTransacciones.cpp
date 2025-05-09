#include "ModTransacciones.h"

ModTransacciones::ModTransacciones()
{
	ind = 0;
	transacciones = new Transaccion*[TR];
}

ModTransacciones::~ModTransacciones()
{
	delete[] transacciones;
}

int ModTransacciones::getInd()
{
	return ind;
}

void ModTransacciones::registrar(Transaccion* transaccion)
{
	if (ind < TR)
	{
		transacciones[ind] = transaccion;
		ind++;
	}
}

Transaccion* ModTransacciones::buscar(int id)
{
	for (int i = 0; i < ind; i++)
	{
		if (transacciones[i]->getId() == id)
		{
			return transacciones[i];
		}
	}
	return NULL;
}

string ModTransacciones::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << transacciones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
