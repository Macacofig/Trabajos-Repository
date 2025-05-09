#include "ModPaquetes.h"

ModPaquetes::ModPaquetes()
{
	ind = 0;
	paquetes = new Paquete * [PS];
}

ModPaquetes::~ModPaquetes()
{
	delete[] paquetes;
}

void ModPaquetes::registrar(Paquete* paquete)
{
	if (ind < PS)
	{
		paquetes[ind] = paquete;
		ind++;
	}
}

PaqueteMinutos* ModPaquetes::buscar(string tipo)
{
	for (int i = 0; i < ind; i++)
	{
		if (paquetes[i]->getTipo() == tipo)
		{
			PaqueteMinutos* p = (PaqueteMinutos*)paquetes[i];
				return p;
		}
	}
	return NULL;
}

PaqueteSMS* ModPaquetes::buscars(string tipo)
{
	for (int i = 0; i < ind; i++)
	{
		if (paquetes[i]->getTipo() == tipo)
		{
			PaqueteSMS* p = (PaqueteSMS*)paquetes[i];
			return p;
		}
	}
	return NULL;
}

string ModPaquetes::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << paquetes[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
