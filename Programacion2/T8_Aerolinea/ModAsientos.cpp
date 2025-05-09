#include "ModAsientos.h"

ModAsientos::ModAsientos(int tam)
{
	ind = 0;
	this->tam = tam;
	asientos = new Asiento * [tam];
}

ModAsientos::~ModAsientos()
{
	delete[] asientos;
}

void ModAsientos::registarAsiento(Asiento* asiento)
{
	if (ind < tam)
	{
		asientos[ind] = asiento;
		ind++;
	}
	else
		cout << "Limite excedido"<<endl;
}

Asiento* ModAsientos::buscar(int fila, int columna)
{
	for (int i = 0; i < ind; i++)
	{
		if (asientos[i]->getFila() == fila && asientos[i]->getColumna() == columna)
		{
			return asientos[i];
		}
	}
	return NULL;
}

string ModAsientos::toJson()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << asientos[i]->toJson();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
