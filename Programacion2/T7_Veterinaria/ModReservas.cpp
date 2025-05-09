#include "ModReservas.h"

ModReservas::ModReservas(int tam)
{
	ind = 0;
	this->tam = tam;
	reservas = new Reserva * [tam];
}

ModReservas::~ModReservas()
{
	for (int i = 0; i < ind; i++)
	{
		delete reservas[i];
	}
	delete[]reservas;
}

void ModReservas::registar(Reserva* reserva)
{
	if (ind < tam)
	{
		reservas[ind] = reserva;
		ind++;
	}
	else
	{
		cout << "Limite excedido";
	}
}

string ModReservas::toString()
{
	stringstream ss;
	ss << "[";
	for (int i = 0; i < ind; i++)
	{
		ss << reservas[i]->toString();
		if (i < ind - 1)
		{
			ss << ",";
		}
	}
	ss << "]";
	return ss.str();
}
