#include "ModAviones.h"

ModAviones::ModAviones(int tam)
{
	ind = 0;
	this->tam = tam;
	aviones = new Avion * [tam];
}

ModAviones::~ModAviones()
{
	delete[] aviones;
}

void ModAviones::registrar(Avion* avion)
{
	if (ind < tam)
	{
		aviones[ind] = avion;
		ind++;
	}
	else
		cout << "Limite excedido" << endl;
}

Avion* ModAviones::buscar(int placa)
{
	for (int i = 0; i < ind; i++)
	{
		if (aviones[i]->getPlaca() == placa)
		{
			return aviones[i];
		}
	}
	return NULL;
}

string ModAviones::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << aviones[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
	return string();
}
