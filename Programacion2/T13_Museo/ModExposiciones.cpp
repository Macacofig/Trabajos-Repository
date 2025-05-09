#include "ModExposiciones.h"

ModExposiciones::ModExposiciones()
{
	ind = 0;
	exposiciones = new Exposicion * [ES];
}

ModExposiciones::~ModExposiciones()
{
	delete[] exposiciones;
}

Exposicion* ModExposiciones::buscar(int numero)
{
	for (int i = 0; i < ind; i++)
	{
		if (exposiciones[i]->getNumero() == numero)
		{
			return exposiciones[i];
		}
	}
	return NULL;
}

void ModExposiciones::registrar(Exposicion* exposicion)
{
	if (ind < ES)
	{
		exposiciones[ind] = exposicion;
		ind++;
	}
}

string ModExposiciones::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << exposiciones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
