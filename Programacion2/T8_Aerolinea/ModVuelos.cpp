#include "ModVuelos.h"

ModVuelos::ModVuelos(int tam)
{
	ind = 0;
	this->tam = tam;
	vuelos = new Vuelo * [tam];
}

ModVuelos::~ModVuelos()
{
	delete[] vuelos;
}

void ModVuelos::registrarVuelo(Vuelo* vuelo)
{
	if (ind < tam)
	{
		vuelos[ind] = vuelo;
		ind++;
	}
	else
		cout << "Limite excedido" << endl;
}

Vuelo* ModVuelos::buscar(int numero)
{
	for (int i = 0; i < ind; i++)
	{
		if (vuelos[i]->getNumero() == numero)
		{
			return vuelos[i];
		}
	}
	return NULL;
}

string ModVuelos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << vuelos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
	return string();
}
