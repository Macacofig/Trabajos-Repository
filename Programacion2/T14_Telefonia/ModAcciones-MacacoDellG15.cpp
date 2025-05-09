#include "ModAcciones.h"

ModAcciones::ModAcciones()
{
	ind = 0;
	acciones = new Accion * [AS];
}

ModAcciones::~ModAcciones()
{
	delete[] acciones;
}

void ModAcciones::registrar(Accion* accion)
{
	if (ind < AS)
	{
		acciones[ind] = accion;
		ind++;
	}
}

string ModAcciones::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << acciones[i]->toJson();
		if (i < ind - 3)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
